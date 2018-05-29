// example2.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:14:29 2015 (+0800)
// Last-Updated: 六 1月 10 15:17:13 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

#include <ncurses.h>
/* stdio.h is also included */
#define ENTER 10
#define ESC 27
#define STARTY 3
#define STARTX 4
#define MENU_ITEM_LENGTH 60
#define MENU_ITEM_NUM 5
#define GET_ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))
int menu(void)
{
const char items[MENU_ITEM_NUM][MENU_ITEM_LENGTH] = {
"This is a simple menu",
"1 Start New Game",
"2 Load Game",
"3 Top Records",
"4 Exit"
};
int
choice, old_choice, ch, i;
clear();
mvprintw(STARTY, STARTX, items[0]);
for (i = 1; i < GET_ARR_LEN(items); ++i) {
if (1 == i) attron(A_REVERSE);
mvprintw(STARTY+i, STARTX+2, "%s\n", items[i]);
if (1 == i) attroff(A_REVERSE);
}
choice = old_choice = 1;
for ( ; ; ) {
ch = getch();
switch (ch) {
case KEY_UP: choice = choice == 1 ? 4 : choice - 1; break;
case KEY_DOWN: choice = choice == 4 ? 1 : choice + 1; break;
case ESC:
return 4;
case ENTER: return choice;
default:
break;
}
 mvprintw(STARTY + old_choice, STARTX + 2, items[old_choice]);
 attron(A_REVERSE);
 mvprintw(STARTY + choice, STARTX + 2, items[choice]);
 attroff(A_REVERSE);
 old_choice = choice;
 }
 getch();
 refresh();
}
int main(int argc, char **argv)
{
  int choice;
  initscr(); /* init ncurses mode */
  noecho(); /* input is invisiable */
  cbreak(); /* no line buffering */
  curs_set(0);
  keypad(stdscr, TRUE);
  for ( ; ; ) {
    choice = menu();
    switch (choice) {
    case 1: mvprintw(15, 0, "Game is starting...\n"); goto end;
    case 2: mvprintw(15, 0, "Loading...\n"); goto end;
    case 3: mvprintw(15, 0, "Openning the record..\n"); goto end;
    case 4: mvprintw(15, 0, "Press any key quit...\n"); goto end;
    default: break;
    }
  }
 end:
  getch(); /* just hold and wait for any key pressed */
  endwin(); /* leave ncurses mode */
  return 0;
}


// 
// example2.cc ends here
