// example5.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:31:20 2015 (+0800)
// Last-Updated: 六 1月 10 15:32:53 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

//彩色窗口演示,用方向键控制或按对应窗口编号控制。
#include <ncurses.h>
/* stdio.h is also included */
#define SUBWIN_NUM 6
#define SUBWIN_SIZE 8
int main(int argc, char **argv)
{
  int i, ch;
  WINDOW *warr[SUBWIN_NUM], *win = NULL;
  initscr(); /* init ncurses mode */
  noecho(); /* input is invisiable */
  cbreak(); /* no line buffering */
  keypad(stdscr, TRUE);
curs_set(0);
start_color();
for (i = 0; i < SUBWIN_NUM; ++i) {
warr[i] = subwin(stdscr, SUBWIN_SIZE, SUBWIN_SIZE,
2, i*(SUBWIN_SIZE+2)+10);
init_pair(i+1, COLOR_WHITE, COLOR_BLACK+i+1);
 wbkgd(warr[i], COLOR_PAIR(i+1));
 if (0 == i) attron(A_BOLD);
 box(warr[i], 0, 0);
 if (0 == i) attroff(A_BOLD);
 wrefresh(warr[i]);
 delwin(warr[i]);
 }
 win = derwin(stdscr, SUBWIN_SIZE, SUBWIN_SIZE,
	      2+SUBWIN_SIZE+2, 4*SUBWIN_SIZE+3);
 box(win, 0, 0);
 wrefresh(win);
 delwin(win);
 win = NULL;
 i = 0;
 do {
   ch = getch();
   switch (ch) {
   case KEY_RIGHT: i = (i == SUBWIN_NUM - 1 ? 0 : i + 1);break;
   case KEY_LEFT: i = (i == 0 ? SUBWIN_NUM - 1 : i - 1);break;
   default:
     if (ch>='0' && ch<'0'+SUBWIN_NUM)
       i = ch - '0';
     break;
   }
   if (win)
     delwin(win);
   win = newwin(SUBWIN_SIZE, SUBWIN_SIZE, 0, 0);
   wbkgd(win, COLOR_PAIR(i+1));
   box(win, 0, 0);
   mvwin(win, 2+SUBWIN_SIZE+2, 4*SUBWIN_SIZE+3);
   touchwin(stdscr);
   refresh();
   touchwin(win);
   wrefresh(win);
 } while (ch != 'q');
 getch();/* just hold and wait for any key pressed */
 endwin();/* leave ncurses mode */
 return 0;
}


// 
// example5.cc ends here
