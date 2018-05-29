// example6.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:35:50 2015 (+0800)
// Last-Updated: 六 1月 10 15:40:32 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 2
// URL: http://wuhongyi.cn 

//一个多级菜单
#include <ncurses.h>
/* stdio.h is also included */
#include <string.h>
#define MAIN_MENU_NUM 3
#define SUB_MENU_NUM 1
#define KEY_ESC 27
#define ENTER 10
#define MENUNAME_LEN 20
#define MAX_MENU_ITEMS 10
struct _menulist {
char menuname[MENUNAME_LEN];
char str[MAX_MENU_ITEMS][MENUNAME_LEN];
int n;
} menulist[MAIN_MENU_NUM + 1]; /* 1 for sub-menu */
WINDOW *menu_win[MAIN_MENU_NUM];
WINDOW *sub_win[SUB_MENU_NUM];
WINDOW *edit_win;
int part1, part2, part3;
void init_menu(void);
void draw_main_menu(WINDOW *win);
void draw_menulist(int m, int t);
void move_menulist(int m, int n);
void draw_submenulist(int m, int n, int k);
void move_submenulist(int m, int t, int k);
// int part1, part2, part3;
// void init_menu(void);
// void draw_main_menu(WINDOW *win);
// void draw_menulist(int m, int t);
// void move_menulist(int m, int n);
// void draw_submenulist(int m, int n, int k);
// void move_submenulist(int m, int t, int k);

void init_menu(void)
{
  int i;
  for (i = 0; i < MAIN_MENU_NUM; ++i)
    menu_win[i] = NULL;
  for (i = 0; i < SUB_MENU_NUM; ++i)
    sub_win[i] = NULL;
  strcpy(menulist[0].menuname, "Search (F1)");
  strcpy(menulist[0].str[0], "Sear by date ");
  strcpy(menulist[0].str[1], "Sear by item ");
  strcpy(menulist[0].str[2], "Sear by money ->");
  strcpy(menulist[0].str[3], "by single list ");
  strcpy(menulist[0].str[4], "----------------");
  strcpy(menulist[0].str[5], "exit");
  menulist[0].n = 6;
  strcpy(menulist[1].menuname, "Modify (F2)");
  strcpy(menulist[1].str[0], "modi single list");
  menulist[1].n = 1;
  strcpy(menulist[2].menuname, "Delete (F3)");
  strcpy(menulist[2].str[0], "dele single list");
  strcpy(menulist[2].str[1], "dele whole list");
  strcpy(menulist[2].str[2], "delete datefile ");
  menulist[2].n = 3;
  strcpy(menulist[3].str[0], "above a num ");
  strcpy(menulist[3].str[1], "equal a num ");
  strcpy(menulist[3].str[2], "below a num ");
  menulist[3].n = 3;
}
void draw_main_menu(WINDOW *win)
{
  int
    i;
  for (i = 0; i < MAIN_MENU_NUM; ++i)
    mvwprintw(win, 2, 4+i*18, menulist[i].menuname);
}
void draw_menulist(int m, int t)
{
  int
    i;
  if (NULL == menu_win[m]) {
    menu_win[m] = newwin(2+menulist[m].n, 18, 3, 4+m*18-1);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
    wbkgd(menu_win[m], COLOR_PAIR(4));
  }
  touchline(edit_win, 0, 18);
  wrefresh(edit_win);
  box(menu_win[m], 0, 0);
  for (i = 0; i < menulist[m].n; ++i) {
    if (t == i) wattron(menu_win[m], A_REVERSE);
    mvwprintw(menu_win[m], i+1, 1, menulist[m].str[i]);
    if (t == i) wattroff(menu_win[m], A_REVERSE);
  }
  move_menulist(m, t);
}
void move_menulist(int m, int t)
{
  int ch;
  bool bdomenu = TRUE;
  keypad(menu_win[m], TRUE);
  while (bdomenu) {
    ch = wgetch(menu_win[m]);
    switch (ch) {
    case KEY_F(1):
    case KEY_ESC:
    case 'q':
      draw_menulist(0, 5);
    bdomenu = FALSE;
    break;
    case KEY_F(2):
      draw_menulist(1, 0);
      bdomenu = FALSE;
      break;
    case KEY_F(3):
      draw_menulist(2, 0);
      bdomenu = FALSE;
      break;
    case KEY_LEFT:
      draw_menulist((m+MAIN_MENU_NUM-1)%MAIN_MENU_NUM, 0);
      bdomenu = FALSE;
      break;
    case KEY_RIGHT:
      draw_menulist((m+MAIN_MENU_NUM+1)%MAIN_MENU_NUM, 0);
      bdomenu = FALSE;
      break;
    case KEY_UP:
      mvwprintw(menu_win[m], t+1, 1, menulist[m].str[t]);
      t = (t+menulist[m].n-1)%menulist[m].n;
      if (4 == t) t = 3;
      if (0 == m && t == 2) {
	draw_submenulist(m, t, 3);
	bdomenu = FALSE;
	break;
      }
      wattron(menu_win[m], A_REVERSE);
      mvwprintw(menu_win[m], t+1, 1, menulist[m].str[t]);
      wattroff(menu_win[m], A_REVERSE);
      break;
    case KEY_DOWN:
      mvwprintw(menu_win[m], t+1, 1, menulist[m].str[t]);
      t = (t+menulist[m].n+1)%menulist[m].n;
      if (4 == t) t = 5;
      if (0 == m && 2 == t) {
	draw_submenulist(m, t, 3);
	bdomenu = FALSE;
	break;
      }
      wattron(menu_win[m], A_REVERSE);
      mvwprintw(menu_win[m], t+1, 1, menulist[m].str[t]);
      wattroff(menu_win[m], A_REVERSE);
      break;
    case ENTER:
      part1 = m;
      part2 = t;
      part3 = -1;
      bdomenu = FALSE;
      break;
    default:
      break;
    }
  }
}
void draw_submenulist(int m, int t, int k)
{
  int
    i, sub_index;
  wattron(menu_win[m], A_REVERSE);
  mvwprintw(menu_win[m], t+1, 1, menulist[m].str[t]);
  wrefresh(menu_win[m]);
  wattroff(menu_win[m], A_REVERSE);
  if (0 == m && 2 == t) {
    sub_index = 0;
    if (NULL == sub_win[sub_index]) {
      sub_win[sub_index] = newwin(menulist[k].n+2, 15, t+3, 3+(m+1)*18);
      wbkgd(sub_win[sub_index], COLOR_PAIR(4));
    }
  }
  box(sub_win[sub_index], 0, 0);
  for (i = 0; i < menulist[k].n; ++i) {
    if (0 == i) wattron(sub_win[sub_index], A_REVERSE);
    mvwprintw(sub_win[sub_index], i+1, 1, menulist[k].str[i]);
    if (0 == i) wattroff(sub_win[sub_index], A_REVERSE);
  }
  move_submenulist(m, t, k);
  return;
}
void move_submenulist(int m, int t, int k)
{
  bool bdosubmenu = TRUE;
  int ch, sub_index, choice;
  if (0 == m && 2 == t)
    sub_index = 0;
  keypad(sub_win[sub_index], TRUE);
  choice = 0;
  while (bdosubmenu) {
    ch = wgetch(sub_win[sub_index]);
    mvwprintw(sub_win[sub_index], choice+1, 1, menulist[k].str[choice]);
    switch (ch) {
    case KEY_ESC:
    case KEY_LEFT:
      if (0 == sub_index)
	draw_menulist(0, t);
      bdosubmenu = FALSE;
      break;
    case KEY_UP:
      choice = (choice+menulist[k].n-1)%menulist[k].n;
      break;
    case KEY_DOWN:
      choice = (choice+menulist[k].n+1)%menulist[k].n;
      break;
    case ENTER:
      bdosubmenu = FALSE;
      part1 = m;
      part2 = t;
      part3 = choice;
      break;
    default:
      break;
    }
    wattron(sub_win[sub_index], A_REVERSE);
    mvwprintw(sub_win[sub_index], choice+1, 1, menulist[k].str[choice]);
    wattroff(sub_win[sub_index], A_REVERSE);
  }
}
int main(int argc, char **argv)
{
  int i;
  initscr(); /* init ncurses mode */
  noecho(); /* input is invisiable */
  cbreak(); /* no line buffering */
  start_color();
  curs_set(0);
  init_pair(1, COLOR_BLACK, COLOR_CYAN);
  bkgd(COLOR_PAIR(1));
  box(stdscr, 0, 0);
  edit_win = newwin(LINES-4, COLS-20, 3, 2);
  init_pair(2, COLOR_CYAN, COLOR_BLUE);
  wbkgd(edit_win, COLOR_PAIR(2));
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  wattron(edit_win, COLOR_PAIR(3));
  box(edit_win, 0, 0);
  wattroff(edit_win, COLOR_PAIR(3));
  init_menu();
  draw_main_menu(stdscr);
  wnoutrefresh(stdscr);
  wnoutrefresh(edit_win);
  doupdate();
  draw_menulist(0, 0);
  mvwprintw(edit_win, getmaxy(edit_win)/2-2, getmaxx(edit_win)/2-14,
	    "Menu %d, Item %d, Sub %d", part1, part2, part3);
  touchline(edit_win, 0, 18);
  wrefresh(edit_win);
  wgetch(edit_win);
  delwin(edit_win);
  for (i = 0; i < MAIN_MENU_NUM; ++i)
    if (menu_win[i] != NULL)
      delwin(menu_win[i]);
  for (i = 0; i < SUB_MENU_NUM; ++i)
    if (sub_win[i] != NULL)
      delwin(sub_win[i]);
  endwin();
  return 0;
  /* leave ncurses mode */
}


// 
// example6.cc ends here
