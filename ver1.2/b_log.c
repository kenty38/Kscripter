
#include "function.h"

void b_log(char back[LINE_MAX][N],char now[LINE_MAX][N],int *Lline){
  int i;
    	  
  erase();
  printw("<<>backlog>>\n");
  for(i=0;i<LINE_MAX;i++){
    printw("%s",back[i]);
  }
  getch();
  erase();
  for(i=0;i<*Lline%LINE_MAX;i++)
    printw("%s",now[i]);
    
  fseek(fp,before_pos,SEEK_SET);  	    
}

