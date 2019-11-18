
/**********************************
*	画面に文字を出力させる関数。				*
*	一文字ずつrefresh()して次の文字を	*
*	出力するのに0.3秒かかる。						*
***********************************/


#include "function.h"

void write_text(int length,char original[],char now[LINE_MAX][N],int *Lline){
  int i;
  
  //getch();
  
  strcpy(now[(*Lline)%LINE_MAX],original);
  //printw("Load_line=%d\n",*Lline);
  i=0;
  while(i<length){
  	if(i == length-1)
  		mvprintw(TEXT_X+ *Lline,TEXT_Y + i,"%c",original[i]);
  	else	
    	mvprintw(TEXT_X+ *Lline,TEXT_Y + i,"%c%c%c",original[i],original[i+1],original[i+2]);
    refresh();
    usleep(1*60000);
    i=i+JAPANESE_BYTE;
  }
  mvprintw(TEXT_X+ *Lline,MESSAGE_LAST_Y,"| |");

  *Lline=*Lline+1;
  
  //最終行ですぐに画面を消去しないようにする
  if(*Lline%LINE_MAX==0)
    getch();
  
  //printw("%d\n",*Lline-1);
  //printw("%s\n",now[*Lline-1]);
  
}


