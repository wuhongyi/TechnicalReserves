// example4.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:24:46 2015 (+0800)
// Last-Updated: 六 1月 10 15:28:32 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 3
// URL: http://wuhongyi.cn 

//显示不同的窗口,按下 m 键可移动窗口
#include <ncurses.h> /* stdio.h is also included */
#define WINDOW_NUM 4
#define WINDOW_SIZE 6
int main(int argc, char **argv)
{
  WINDOW *warr[WINDOW_NUM];
  int i, j, k, ch,starty, startx,old_y, old_x;
  initscr(); /* init ncurses mode */
  noecho(); /* input is invisiable */
  cbreak(); /* no line buffering */
  curs_set(0);
  keypad(stdscr, TRUE);
  for (i = k = 0; i < 2; ++i)
    for (j = 0; j < 2; ++j, ++k) {
      warr[k] = newwin(WINDOW_SIZE, WINDOW_SIZE,
		       i*(WINDOW_SIZE+4)+6, j*2*WINDOW_SIZE+8);
      wbkgd(warr[k], (k+1)+'0');
      box(warr[k], 0, 0);
      wrefresh(warr[k]);
    }
  touchwin(stdscr);
  refresh();
  touchwin(warr[0]);
  wrefresh(warr[0]);
  k = 0;
  do {
    ch = getch();
    switch (ch) {
    case KEY_LEFT: k = k%2 == 0 ? k+1 : k-1; break;
    case KEY_RIGHT: k = k%2 == 0 ? k+1 : k-1; break;
    case KEY_UP: break;
      k = k > 1 ? k - 2 : k + 2;
    case KEY_DOWN: k = k < 2 ? k + 2 : k - 2;
    default:
      break;
      break;
    }
    touchline(stdscr, 0, 2*WINDOW_SIZE+14);
    refresh();
    touchwin(warr[k]);
    wrefresh(warr[k]);
  } while (ch != 'q' && ch != 'm');
  for (i = 0; i < WINDOW_NUM; ++i)
    if (i != k)
      delwin(warr[i]);
 if ('m' == ch) {
   old_y = starty = (k <= 1
		     ? 6 : WINDOW_SIZE+10);
   old_x = startx = (k%2 == 0 ? 8 : 2*WINDOW_SIZE+8);
   do {
     ch = getch();
     switch (ch) {
     case KEY_LEFT:
       if (startx > 0) --startx;
       break;
     case KEY_RIGHT:
       if (startx+WINDOW_SIZE < getmaxx(stdscr))
	 ++startx;
       break;
     case KEY_UP:
       if (starty > 0) --starty;
       break;
     case KEY_DOWN:
       if (starty+WINDOW_SIZE < getmaxy(stdscr))
	 ++starty;
       break;
     default:
       break;
     }
     if (starty != old_y || startx != old_x) {
       touchwin(stdscr);
       refresh();
       mvwin(warr[k], starty, startx);
       wrefresh(warr[k]);
       old_y = starty;
       old_x = startx;
     }
   } while (ch != 'q');
 }
 delwin(warr[k]);
 endwin();/* leave ncurses mode */
 return 0;
}


// 
// example4.cc ends here
