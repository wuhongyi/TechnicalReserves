// example7.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:43:51 2015 (+0800)
// Last-Updated: 六 1月 10 15:46:11 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//鼠标和键盘同时控制菜单
#include <ncurses.h>
#include <string.h>
#define DEBUG
#define MENU_WIDTH 30
#define MENU_HEIGHT 10
#define ENTER 10
#define GET_ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))
int startx, starty;
char *choices[] = {
"Choice 1",
"Choice 2",
"Choice 3",
"Choice 4",
"Exit"
};
int nchoices = GET_ARR_LEN(choices);
void print_menu(WINDOW *menu_win, int highlight);
int report_choice(int mousey, int mousex);
int main(int argc, char **argv)
{
  WINDOW *menu_win = NULL;
  MEVENT event;
  int highlight = nchoices;
  int choice = 5;
  int ch;
  initscr();
  noecho();
  raw();
  curs_set(0);
  mousemask(ALL_MOUSE_EVENTS, NULL);
  startx = (COLS - MENU_WIDTH)/2;
  starty = (LINES - MENU_HEIGHT)/2;
  menu_win = newwin(MENU_HEIGHT, MENU_WIDTH, starty, startx);
  keypad(menu_win, TRUE);
  attron(A_REVERSE);
  printw("Use arrow keys to go up and down, press enter to select.");
  refresh();
  attroff(A_REVERSE);
  print_menu(menu_win, highlight );
  for ( ; ; ) {
    ch = wgetch(menu_win);
    switch (ch) {
    case KEY_MOUSE:
      if (OK == getmouse(&event)) {
#ifdef DEBUG
	mvprintw(21, 0, "event.y = %d, event.x = %d",
		 event.y, event.x);
	refresh();
#endif
	if (event.bstate & BUTTON1_CLICKED) {
#ifdef DEBUG
	  mvprintw(20, 0, "Yes, we have button1 clicked!");
	  refresh();
#endif
	  choice = report_choice(event.y + 1, event.x + 1);
	  if (choice != -1)
	    goto ok;
	}
      }
      break;
    case KEY_UP:
      if (1 == highlight)
	highlight = nchoices;
      else
	--highlight;
      break;
    case KEY_DOWN:
      if (nchoices == highlight)
	highlight = 1;
      else
	++highlight;
      break;
    case ENTER:
      choice = highlight;
      goto ok;
    default:
      mvprintw(LINES-2, 0, "Inputted char: %c", ch);
      clrtoeol();
      refresh();
      break;
    }
    print_menu(menu_win, highlight);
  }
 ok:
  mvprintw(LINES-1, 0, "choice = %d, Item = %s", choice, choices[choice - 1]);
  clrtoeol();
  getch();
  endwin();
  return 0;
}
void print_menu(WINDOW *menu_win, int highlight)
{
  int x, y, i;
  x = y = 2;
  box(menu_win, 0, 0);
  for (i = 0; i < nchoices; ++i, ++y) {
    if (i+1 == highlight) {
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, choices[i]);
      wattroff(menu_win, A_REVERSE);
    } else
      mvwprintw(menu_win, y, x, choices[i]);
  }
  wrefresh(menu_win);
}
int report_choice(int mousey, int mousex)
{
  int i, j, choice;
  i = startx + 2;
  j = starty + 2 + 1;
  for (choice = 0; choice < nchoices; ++choice)
    if (mousey == j + choice &&
	mousex >= i && mousex <= i + strlen(choices[choice])) {
      return (choice + 1);
    }
  return -1;
}


// 
// example7.cc ends here
