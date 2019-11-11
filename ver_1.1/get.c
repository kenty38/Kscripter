#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<locale.h>

int main(void){
  int ch;
  initscr();
  noecho();
  printw("input\n");
  ch=getch();
  
  switch(ch){
    case 'a':
      printw("a\n");
      break;
    case 'b':
      printw("b\n");
      break;
    default:
      printw("ha?\n");
  }
  
  getch();
  
  endwin();
}
