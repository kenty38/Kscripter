
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
  *Lline=*Lline+1;
  
  for(i=0;i<length;i++){
    printw("%c",original[i]);
    refresh();
    usleep(1*30000);
  }
  
  //最終行ですぐに画面を消去しないようにする
  if(*Lline%LINE_MAX==0)
    getch();
  
  //printw("%d\n",*Lline-1);
  //printw("%s\n",now[*Lline-1]);
  
}
