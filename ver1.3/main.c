
#include "function.h"

int main(void){

  FILE *fp;

  int i,j;
  int len;								//文字配列の長さを格納する変数
  int select_num;					//選択肢の個数(10個まで)
  
  int case_flag=0;				//<CASE_LAUNCH> , <CASE_TERMINAL>用のフラグ 
  int lcase_flag=0;				//<X.CASE Y> , <CASE_END>用のフラグ
  
  char origin[N];					//txtから一行コピーした文字配列
  char origin_except_n[N];//originから改行文字を抜かしたもの
  char case_pattern[N];		//条件分岐の先頭へ移動するために必要なもの
  char fname[]="text2.txt";
  
  bool if_flag=false;			//false:SELECTなし , true:SELECTあり

  setlocale(LC_ALL,"");
  start_color();					//カラー属性を扱うための初期化
  keypad(initscr(),TRUE);	//スクリーン初期化
  noecho();								//端末上に入力文字を表示しない
  
  fp=fopen(fname,"r");		//ファイルを開く。失敗するとNULLを返す
  if(fp==NULL){
    printf("%s file not open!\n",fname);
     endwin();
  }
  
	//txtデータが末端に行くまで繰り返す
  while(fgets(origin,N,fp)!=NULL){
    
    //改行文字のみの行は無視
    if(*origin=='\n')
    	continue;
    
    //一行の長さを図る(\n込み)
    len=strlen(origin);
  
    //<<SELECT管理>>
    if(select_opt(origin,&if_flag,&select_num,&case_flag,&lcase_flag)==-1)
      continue;
    //<<SELECT終了>>
    
    //<<CASE管理>>
    if(case_binary(origin,&case_flag,&lcase_flag,case_pattern)==-1)
      continue;
    //<<CASE終了>>
    
    //画面出力    
    write_text(len,origin);
    getch();
  }
 	
 	//erase();//文字を消去
 	getch();
 
 	endwin();
}



//----------<<function>>--------------------------------------------------

