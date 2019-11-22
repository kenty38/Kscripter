
/**********************************
*	画面に文字を出力させる関数。				*
*	一文字ずつrefresh()して次の文字を	*
*	出力するのに0.3秒かかる。						*
***********************************/

#include "function.h"

void write_text(int length,char original[],char now[LINE_MAX][N],int *Lline){
  int i;
  int line_row;
  //getch();
  
  strcpy(now[(*Lline)%LINE_MAX],original);
  //printw("Load_line=%d\n",*Lline);
  
  i=0;
  line_row=0;
  while(i<length){
  	if(i == length-1 || (original[i] >= ASCII_LIST_START && original[i] <= ASCII_LIST_END)){
  		mvprintw(TEXT_X+ *Lline,TEXT_Y + line_row,"%c",original[i]);
  		i=i+1;
  		line_row=line_row+1;
  	}
  	else{
    	mvprintw(TEXT_X+ *Lline,TEXT_Y + line_row,"%c%c%c",original[i],original[i+1],original[i+2]);
    	i=i+JAPANESE_BYTE;
    	line_row=line_row+JCHARACTER_WIDTH;
    }    
    refresh();
    usleep(1*60000);
  }
  mvprintw(TEXT_X+ *Lline,MESSAGE_LAST_Y,"| |");

  *Lline=*Lline+1;
  
  //最終行ですぐに画面を消去しないようにする
  if(*Lline%LINE_MAX==0)
    getch();
  
  //printw("%d\n",*Lline-1);
  //printw("%s\n",now[*Lline-1]);
  
}

void write_text_new_line(int length,char original[],char now[LINE_MAX][N],int *Lline,char back[LINE_MAX][N]){
  int i;
  int line_row;
  bool fake=false;
  //getch();
  
  strcpy(now[(*Lline)%LINE_MAX],original);
  //printw("Load_line=%d\n",*Lline);
  i=0;
  line_row=0;
  while(i<length){
  	if(i == length-1 || (original[i] >= ASCII_LIST_START && original[i] <= ASCII_LIST_END)){
  		mvprintw(TEXT_X+ *Lline,TEXT_Y + line_row,"%c",original[i]);
  		i=i+1;
  		line_row=line_row+1;
  	}
  	else{
    	mvprintw(TEXT_X+ *Lline,TEXT_Y + line_row,"%c%c%c",original[i],original[i+1],original[i+2]);
    	i=i+JAPANESE_BYTE;
    	line_row=line_row+JCHARACTER_WIDTH;
    }  
    refresh();
    usleep(1*60000);
    
    if((i/JAPANESE_BYTE)%TERMINAL_STRING_MAX == 0){
    	*Lline=*Lline+1;
    	line_row=0;
    	if(*Lline%LINE_MAX == 0)
    		display_clear_and_copy(fake, Lline, back, now);
    }		
  }
  mvprintw(TEXT_X+ *Lline,MESSAGE_LAST_Y,"| |");

  *Lline=*Lline+1;
  
  //最終行ですぐに画面を消去しないようにする
  if(*Lline%LINE_MAX==0)
    getch();

  
}


