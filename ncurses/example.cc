// example.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 09:05:34 2015 (+0800)
// Last-Updated: 二 4月 14 21:19:49 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 11
// URL: http://wuhongyi.cn 

// g++ example.cc -lncurses -o 123

// 我们将来分析一个非常简单实用的程序.在这个程序中,将使用ncurses定义菜单,菜单中的?一个选择项都会被证明选种. 这个程序比较有意思的一面就是使用了ncurses的窗体来达到菜单效果.您可以看下面的屏幕截图.
// 程序开始和普通一样,包括进去了一个头文件.接着我们定义了回车键和escape键的ASCII码值.
#include <ncurses.h> 
#include <stdlib.h>
#define ENTER 10
#define ESCAPE 27
// 当程序的时候,下面的函数会被调用.它首先调用initscr初始化指针接着调用start_color来显示彩色. 整个程序中所使用的颜色对会在后面定义.调用curs_set(0)会屏蔽掉物理指针.noecho()将终止键盘上的输入会在屏幕上显示出来. 您可以使用noecho函数控制键盘输入进来的字符,只允许需要的字符显示.echo()将会屏蔽掉这种效果. 接着的函数keypad设置了可以在stdscr中接受键盘的功能键(快捷键),我们需要在后面的程序中定义F1,F2以及移动的光标键.
void init_curses()
{
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  init_pair(2,COLOR_BLUE,COLOR_WHITE);
  init_pair(3,COLOR_RED,COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
}

// 下面定义的这个函数定义了一个显示在屏幕最顶部的菜单栏, 您可以看下面的main段程序,它看上去好象只是屏幕最顶部的一行,其实实际上是stdscr窗体的一个子窗体,该子窗体只有 一行.下面的程序将指向该子窗体的指针作为它的参数,首先改变它的背景色,接着定义菜单的?字,我们使用waddstr定义菜单 的?字.需要注意的是wattron调用了另外一个不同的颜色对(序号3)以取代缺省的颜色对(序号2).记住2号颜色对在最开始就 由wbkgd设置成缺省的颜色对了.wattroff函数可以让我们切换到缺省的颜色对状态.
void draw_menubar(WINDOW *menubar)
{
  wbkgd(menubar,COLOR_PAIR(2));
  waddstr(menubar,"Menu1");
  wattron(menubar,COLOR_PAIR(3));
  waddstr(menubar,"(F1)");
  wattroff(menubar,COLOR_PAIR(3));

  wmove(menubar,0,20);

  waddstr(menubar,"Menu2");
  wattron(menubar,COLOR_PAIR(3));
  waddstr(menubar,"(F2)");
  wattroff(menubar,COLOR_PAIR(3));
}
// 下一个函数显示了当按下F1或者F2键显示的菜单,定义了一个在蓝色背景上 菜单栏颜色一样的白色背景窗体,我们不希望这个新窗口会被显示在背景色上的字覆盖掉.它们应该停留在那里直到 关闭了菜单.这就是为什么菜单窗体不能定义为stdscr的子窗体,下面会提到,窗体items[0]是用newwin函数定义的, 其他8个窗体则都是定义成items[0]窗体的子窗体.这里的items[0]被用来绘制一个围绕在菜单旁边的边框,其他的 窗体则用来显示菜单中选中的单元.同样的,他们不会覆盖掉菜单上的边框.为了区别选中和没选中的状态,有必要让 选中的单元背景色和其他的不一样.这就是这个函数中倒数第三句的作用了,菜单中的第一个单元背景色和其他的不一样, 这是因为菜单弹出来后,第一个单元是选中状态.
WINDOW **draw_menu(int start_col)
{
  int i;
  WINDOW **items;
  items=(WINDOW **)malloc(9*sizeof(WINDOW *));
  items[0]=newwin(10,19,1,start_col);
  wbkgd(items[0],COLOR_PAIR(2));
  box(items[0],ACS_VLINE,ACS_HLINE);
  items[1]=subwin(items[0],1,17,2,start_col+1);
  items[2]=subwin(items[0],1,17,3,start_col+1);
  items[3]=subwin(items[0],1,17,4,start_col+1);
  items[4]=subwin(items[0],1,17,5,start_col+1);
  items[5]=subwin(items[0],1,17,6,start_col+1);
  items[6]=subwin(items[0],1,17,7,start_col+1);
  items[7]=subwin(items[0],1,17,8,start_col+1);
  items[8]=subwin(items[0],1,17,9,start_col+1);
  for (i=1;i<9;i++)
    wprintw(items[i],"Item%d",i);
  wbkgd(items[1],COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}
// 下面这个函数简单的删除了上面函数定义的菜单窗体.它首先用delwin函数删除窗体, 接着释放items指针的内存单元.
void delete_menu(WINDOW **items,int count)
{
  int i;
  for (i=0;i<count;i++)
    delwin(items[i]);
  free(items);
}
// scroll_menu函数允许我们在菜单选择项上上下移动,它通过getch读取键盘上的键值,如果按下了键盘上的上移或者下移方向键, 菜单选择项的上一个项或者下一个项被选中.回忆一下刚才所讲的,选中项的背景色将会和没选中的不一样.如果是向左或者向右 的方向键,当前菜单将会关闭,另一个菜单打开.如果按下了回车键,则返回选中的单元值.如果按下了ESC键,菜单将会被关闭,并且没有任何选择项 ,下面的函数忽略了其他的输入键.getch能从键盘上读取键值,这是因为我们在程序开始使用了keypad(stdscr,TRUE) 并且将返回值赋给一个int型变量而不是char型变量,这是因为int型变量能表示比char型更大的值.
int scroll_menu(WINDOW **items,int count,int menu_start_col)
{ 
  int key;
  int selected=0;
  while (1) {
    key=getch();
    if (key==KEY_DOWN || key==KEY_UP)
      {
	wbkgd(items[selected+1],COLOR_PAIR(2));
	wnoutrefresh(items[selected+1]);
	if (key==KEY_DOWN)
	  {
	    selected=(selected+1) % count;
	  } else {
	  selected=(selected+count-1) % count;
	}
	wbkgd(items[selected+1],COLOR_PAIR(1));
	wnoutrefresh(items[selected+1]);
	doupdate();
      }
    else if (key==KEY_LEFT || key==KEY_RIGHT)
      {
	delete_menu(items,count+1);
	touchwin(stdscr); refresh();
	items=draw_menu(20-menu_start_col);
	return scroll_menu(items,8,20-menu_start_col);
      }
    else if (key==ESCAPE)
      {
	return -1;
      }
    else if (key==ENTER)
      {
	return selected;
      }
  }
}
// 最后就是我们的main部分了.它使用了上面所有我们所讲述和编写的函数来使程序合适的工作. 它同样通过getch读取键值来判断F1或者F2是否按下了,并且用draw_menu来在相应的菜单窗体上绘制菜单. 接着调用scroll_menu函数让用户选择某一个菜单,当scroll_menu返回后,它删除菜单窗体并且显示所选择的单元内容 在信息栏里.
// 我必须提到的是函数touchwin.如果在菜单关闭后没有调用touchwin而立即刷新,那么最后打开的菜单将一直停留在 屏幕上.这是因为在调用refresh时,menu函数根本就没有完全改变stdscr的内容.它没有重新写入数据到stdscr上, 因为它以为窗体内容没有改变.touchwin函数设置了所有WINDOW结构中的标志位,它通知refresh刷新窗体中所有的行, 值都改变了,这样在下一次刷新整个窗体时,即使窗体内容没有改变也要重新写入一次.在菜单关闭后,选择的菜单信息会一直停留在 stdscr上面.菜单没有在stdscr上写数据,因为它是开了一个新的子窗口.
int main()
{
  int key;
  WINDOW *menubar,*messagebar;
  init_curses();
  bkgd(COLOR_PAIR(1));
  menubar=subwin(stdscr,1,80,0,0);
  messagebar=subwin(stdscr,1,79,23,1);
  draw_menubar(menubar); move(2,1);
  printw("Press F1 or F2 to open the menus. ");
  printw("ESC quits.");
  refresh();
  do
    {
      int selected_item;
      WINDOW **menu_items;
      key=getch();
      werase(messagebar);
      wrefresh(messagebar);
      if (key==KEY_F(1))
	{
	  menu_items=draw_menu(0);
	  selected_item=scroll_menu(menu_items,8,0);
	  delete_menu(menu_items,9);
	  if (selected_item<0)
	    wprintw(messagebar,"You haven't selected any item.");
	  else
	    wprintw(messagebar, "You have selected menu item %d.",selected_item+1);
	  touchwin(stdscr); refresh();
	}
      else if (key==KEY_F(2))
	{
	  menu_items=draw_menu(20);
	  selected_item=scroll_menu(menu_items,8,20);
	  delete_menu(menu_items,9);
	  if (selected_item<0)
	    wprintw(messagebar,"You haven't selected any item.");
	  else
	    wprintw(messagebar, "You have selected menu item %d.",selected_item+1);
	  touchwin(stdscr); refresh();
	}
    } while (key!=ESCAPE);
  delwin(menubar);
  delwin(messagebar);
  endwin();
  return 0;
}

// 
// example.cc ends here
