// example3.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:17:47 2015 (+0800)
// Last-Updated: 六 1月 10 15:18:56 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//模拟一个登录框
#include <ncurses.h>
/* stdio.h is also included */
#define USERNAME_LEN 15
#define PASSWORD_LEN 10
int main(int argc, char **argv)
{
  char user[USERNAME_LEN], passwd[PASSWORD_LEN];
  WINDOW *win;
  initscr();
  /* init ncurses mode */
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  bkgd(COLOR_PAIR(1));
  refresh();
  init_pair(2, COLOR_YELLOW, COLOR_BLUE);
  win = newwin(7, 25, 2, 2);
  wbkgd(win, COLOR_PAIR(2));
  box(win, 0, 0);
  mvwprintw(win, 2, 2, "User:");
  mvwprintw(win, 4, 2, "Pass:");
  wbkgdset(win, COLOR_PAIR(1));
  mvwprintw(win, 2, 8, " ");
  mvwprintw(win, 4, 8, " ");
  wrefresh(win);
  mvwgetnstr(win, 2, 8, user, sizeof(user));
  noecho();
  mvwscanw(win, 4, 8, "%s", passwd);
  overwrite(win, stdscr);
  delwin(win);
  touchwin(stdscr);
  mvprintw(11, 0, "user: %s, passwd: %s\n", user, passwd);
  getch(); /* just hold and wait for any key pressed */
  endwin(); /* leave ncurses mode */
  return 0;
}


// 
// example3.cc ends here
