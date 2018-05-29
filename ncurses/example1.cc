// example1.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 1月 10 14:53:47 2015 (+0800)
// Last-Updated: 六 1月 10 15:00:14 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

#include <ncurses.h>
#include <string>
#include <vector>
//#define DEBUG
#ifdef DEBUG
#include <iostream>
#include <cstdio>
#endif
int main(void)
{
  int x,y;
  std::vector<std::string> msg;
  msg.push_back("Hello Ncurses!");
  msg.push_back("Please Enter Anykey to exit. . .");
  std::vector<std::string>::iterator pa=msg.begin();
#ifndef DEBUG
  initscr();
  curs_set(0);
  noecho();
  getmaxyx(stdscr,y,x);
  //refresh();
  //mvprintw(y/2,x/2-pa->size()/2,pa->c_str());
  for(int i=0;pa!=msg.end();++pa,++i)
    mvprintw(y/2+i,x/2-pa->size()/2,pa->c_str());
  //refresh();
  getch();
  echo();
  curs_set(1);
  endwin();
#else
  printf("%s\n",(pa++)->c_str());
  std::cout<<*pa<<std::endl;
#endif
  return 0;
}

// 
// example1.cc ends here
