// example8.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 15:48:21 2015 (+0800)
// Last-Updated: 六 1月 10 15:48:34 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

//动态按钮的显示
#include <ncurses.h>
/* stdio.h is also included */
#include <stdlib.h>
#include <unistd.h>
#define STARTY 2
#define STARTX 2
#define BUTTON_NUM 3
#define BUTTON_HEIGHT 3
#define BUTTON_WIDTH 15
#define ENTER 10
#define Swap(x, y) do { \
(x) ^= (y); \
(y) ^= (x); \
(x) ^= (y); \
} while (0)
int fill_rectangle(WINDOW *win, int starty, int startx,
int endy, int endx, chtype ch)
{
if (NULL == win ||
starty < 0 || starty >= getmaxy(win) ||
startx < 0 || startx >= getmaxx(win) ||
endy < 0 || endy >= getmaxy(win) ||
endx < 0 || endx >= getmaxx(win))
return ERR;
else {
int
i;
if (endy < starty) Swap(endy, starty);
if (endx < startx) Swap(endx, startx);
for (i = starty; i <= endy; ++i)
mvwhline(win, i, startx, ch, endx-startx+1);
return OK;
}
}
int Box(WINDOW *win, int starty, int startx,
int endy, int endx, int attrs)
{
if (NULL == win ||
starty < 0 || starty >= getmaxy(win) ||
startx < 0 || startx >= getmaxx(win) ||
endy < 0 || endy >= getmaxy(win) ||
endx < 0 || endx >= getmaxx(win) ||
abs(startx - endx) < 2 || abs(starty - endy) < 2)
return ERR;
else {
mvwhline(win, starty, startx+1, ACS_HLINE | attrs, endx-startx-1);
mvwhline(win, endy, startx+1, ACS_HLINE | attrs, endx-startx-1);
mvwvline(win, starty+1, startx, ACS_VLINE | attrs, endy-starty-1);
mvwvline(win, starty+1, endx, ACS_VLINE | attrs, endy-starty-1);
mvwaddch(win, starty, startx, ACS_ULCORNER | attrs);
mvwaddch(win, starty, endx, ACS_URCORNER | attrs);
mvwaddch(win, endy, startx, ACS_LLCORNER | attrs);
mvwaddch(win, endy, endx, ACS_LRCORNER | attrs);
return OK;
}
}
int draw_3D_window(WINDOW *win, int starty, int startx,
int endy, int endx, int attrs)
{
if (NULL == win ||
starty < 0 || starty >= getmaxy(win) - 1 ||
startx < 0 || startx >= getmaxx(win) - 1 ||
endy < 0 || endy >= getmaxy(win) - 1||
endx < 0 || endx >= getmaxx(win) - 1)
return ERR;
else {
init_pair(COLOR_PAIRS-1, COLOR_WHITE, COLOR_BLACK);
fill_rectangle(win, starty+1, startx+1, endy+1, endx+1,
' ' | COLOR_PAIR(COLOR_PAIRS-1));
fill_rectangle(win, starty, startx, endy, endx, ' ' | attrs);
return OK;
}
}
int main(int argc, char **argv)
{
char
*btn_msg[BUTTON_NUM] = {
"This Button 1",
"This Button 2",
"This Button 3"
};
int
i, ch, choice, old_choice;
MEVENT event;
bool
dobutton = TRUE;
initscr(); /* init ncurses mode */
noecho(); /* input is invisiable */
cbreak(); /* no line buffering */
keypad(stdscr, TRUE);
curs_set(0);
start_color();
mvprintw(LINES-1, 0, "Use key or mouse to select/push the button.");
init_pair(1, COLOR_YELLOW, COLOR_WHITE);
bkgd(COLOR_PAIR(1));
init_pair(2, COLOR_YELLOW, COLOR_BLUE);
bkgdset(COLOR_PAIR(2));
for (i = 0; i < BUTTON_NUM; ++i) {
draw_3D_window(stdscr, STARTY+i*BUTTON_HEIGHT+i*3, STARTX,
STARTY+(i+1)*BUTTON_HEIGHT-1+i*3, STARTX+BUTTON_WIDTH-1,
COLOR_PAIR(2));
if (0 == i) attron(A_BOLD);
Box(stdscr, STARTY+i*BUTTON_HEIGHT+i*3, STARTX,
STARTY+(i+1)*BUTTON_HEIGHT-1+i*3, STARTX+BUTTON_WIDTH-1, 0);
mvprintw(STARTY+i*BUTTON_HEIGHT+i*3+1, STARTX+1, btn_msg[i]);
if (0 == i) attroff(A_BOLD);
}
mousemask(ALL_MOUSE_EVENTS, NULL);
old_choice = choice = 0;
while (dobutton) {
ch = getch();
switch (ch) {
case KEY_MOUSE:
if (OK == getmouse(&event)) {
if (event.bstate & BUTTON1_CLICKED) {
for (i = 0; i < BUTTON_NUM; ++i)
if (event.y >= STARTY+i*BUTTON_HEIGHT+i*3 &&
event.y <= STARTY+(i+1)*BUTTON_HEIGHT-1+i*3 &&
event.x >= STARTX &&
event.x <= STARTX+BUTTON_WIDTH-1) {
choice = i;
dobutton = FALSE;
break;
}
}
}
break;
case KEY_UP:
choice = (choice+BUTTON_NUM-1)%BUTTON_NUM;
break;
case KEY_DOWN:
choice = (choice+BUTTON_NUM+1)%BUTTON_NUM;
break;
case ENTER:
dobutton = FALSE;
break;
default:
break;
}
if (old_choice != choice) {
Box(stdscr, STARTY+old_choice*BUTTON_HEIGHT+old_choice*3, STARTX,
STARTY+(old_choice+1)*BUTTON_HEIGHT-1+old_choice*3,
STARTX+BUTTON_WIDTH-1, 0);
mvprintw(STARTY+old_choice*BUTTON_HEIGHT+old_choice*3+1,
STARTX+1, btn_msg[old_choice]);
attron(A_BOLD);
Box(stdscr, STARTY+choice*BUTTON_HEIGHT+choice*3, STARTX,
STARTY+(choice+1)*BUTTON_HEIGHT-1+choice*3,
STARTX+BUTTON_WIDTH-1, 0);
mvprintw(STARTY+choice*BUTTON_HEIGHT+choice*3+1,
STARTX+1, btn_msg[choice]);
attroff(A_BOLD);
old_choice = choice;
}
}
/* button effect */
fill_rectangle(stdscr, STARTY+choice*BUTTON_HEIGHT+choice*3, STARTX,
STARTY+(choice+1)*BUTTON_HEIGHT-1+choice*3+1,
STARTX+BUTTON_WIDTH-1+1, ' ' | COLOR_PAIR(1));
refresh();
attron(A_BOLD);
Box(stdscr, STARTY+choice*BUTTON_HEIGHT+choice*3+1, STARTX+1,
STARTY+(choice+1)*BUTTON_HEIGHT-1+choice*3+1,
STARTX+BUTTON_WIDTH-1+1, 0);
mvprintw(STARTY+choice*BUTTON_HEIGHT+choice*3+1+1,
STARTX+1+1, btn_msg[choice]);
attroff(A_BOLD);
refresh();
usleep(120000);
draw_3D_window(stdscr, STARTY+choice*BUTTON_HEIGHT+choice*3, STARTX,
STARTY+(choice+1)*BUTTON_HEIGHT-1+choice*3, STARTX+BUTTON_WIDTH-1,
COLOR_PAIR(2));
attron(A_BOLD);
Box(stdscr, STARTY+choice*BUTTON_HEIGHT+choice*3, STARTX,
STARTY+(choice+1)*BUTTON_HEIGHT-1+choice*3,
STARTX+BUTTON_WIDTH-1, 0);
mvprintw(STARTY+choice*BUTTON_HEIGHT+choice*3+1,
STARTX+1, btn_msg[choice]);
attroff(A_BOLD);
getch(); /* just hold and wait for any key pressed */
endwin(); /* leave ncurses mode */
return 0;
}


// 
// example8.cc ends here
