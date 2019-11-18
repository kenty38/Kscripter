#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include<unistd.h>
#include<locale.h>
#define N 256


int main(void){
int i,j;
int len;
int ch;
char moji1[256]="i am oimo.\n";
char moji2[256]="i am confident of novel-game engine.\n";
FILE *fp;
char fname[]="literature.txt";
char str[N];
len=strlen(moji1);
setlocale(LC_ALL,"");
  start_color();	//カラー属性を扱うための初期化
  //initscr();	//スクリーン初期化
  
  keypad(initscr(),TRUE);
  noecho();
 /* 
  fp=fopen(fname,"r");//ファイルを開く。失敗するとNULLを返す
  if(if==NULL){
  printf("%s file not open!\n",fname);
  return -1;
  }
  
  while(fgetc(str,N,fp)!=NEOF){
  printw("%c",str[i])
  refresh();
  usleep();
  }
  */
 
  for(j=0;j<len;j++){
  printw("%c",moji1[j]);
  refresh();
  usleep(1*30000);
  }
  //printw("\n");
  ch=getch();
  printw("getch()=%d\n",(char)ch);
  len=strlen(moji2);
 
  for(j=0;j<len;j++){
  printw("%c",moji2[j]);
  refresh();
  usleep(1*30000);
  }
  //printw("\n");
  
 	getch();
 	
  printw("getch()=%d\n",getch());
 	erase();//文字を消去
 	getch();
 
 	endwin();
}

