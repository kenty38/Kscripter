
#include "function.h"

void dis_pause(int Lline,char now[LINE_MAX][N]);

int main(int argc, char *argv[]){
  
  int i;
  int Load_line=0;                //何行読み込んだかを記憶しておく変数
  int len;								        //文字配列の長さを格納する変数
  int select_num;					        //選択肢の個数(10個まで)
  int ch;									        //getch()の中身を保存する関数    
  
  char origin[N];					        //txtから一行コピーした文字配列
  char case_pattern[N];		        //条件分岐の先頭へ移動するために必要なもの
  char nowlog[LINE_MAX][N];       //映しだされている画面の文字を格納
  char backlog[LINE_MAX][N];			//バックログ表示に用いる文字列
  
  char fname[]="text/text.txt";
  
  bool select_flag=false;			        //false:SELECTなし , true:SELECTあり(select_flag)
  bool select_decide=false;		        //選択肢をキーが押した瞬間に書き始めさせるためのフラグ(select_decide)
  
  int case_flag;				//<CASE_LAUNCH> , <CASE_TERMINAL>用のフラグ 
	int lcase_flag;				//little_case_flag:<X.CASE Y> , <CASE_END>用のフラグ (2つともinitialize.cで初期化)
  
  bool skip_flag=false;

  //ファイルを開く。失敗するとNULLを返す
  fp=fopen(fname,"r");
  if(fp==NULL){
    printf("%s file not open!\n",fname);
    exit(1);
  }
  
	//初期化
	initialize(&case_flag,&lcase_flag);

  //タイトル画面作成
  Load_first_display(&case_flag,&lcase_flag);

  
	//<<txtデータが末端に行くまで繰り返す>>
  while(fgets(origin,N,fp)!=NULL){
 		printw("Load_line=%d\n",Load_line);
    //改行文字のみの行は無視
    if(*origin=='\n')
    	continue;
    
		
		//LINE_MAXの時、画面をクリアにしバックログに保存
    if(Load_line%LINE_MAX==0){
      erase();
      for(i=0;i<LINE_MAX;i++)
        strcpy(backlog[i],nowlog[i]);
    }
      
    //一行の長さを図る(\n込み)
    len=strlen(origin);
  
    //<<SELECT管理>>
    if(select_opt(origin,&select_flag,&select_num,&case_flag,&lcase_flag,&Load_line,nowlog)==REACT)
      continue;
    //<<SELECT終了>>
    
    //<<CASE管理>>
    if(case_binary(origin,&case_flag,&lcase_flag,case_pattern,&select_decide,Load_line,nowlog,backlog)==REACT)
      continue;
    //<<CASE終了>>
	    
    //画面出力
    if(select_decide==false)
    	ch=getch();
    else
      select_decide=false;
      
    switch(ch){
    	
    	case 'b':
    	  b_log(backlog,nowlog,&Load_line);
    	  continue;
    	  
    	case 'p':
    		dis_pause(Load_line,nowlog);
    		continue;
    	
    	case 's':
    		save(before_pos,case_flag,lcase_flag,Load_line,nowlog);
    		//printw("save_byte=%ld\n",save_byte);
    		continue;
    		
    	default:
    		write_text(len,origin,nowlog,&Load_line);
    		break;
    }
    //一つ前のバイト数を覚えさせておく
   
    before_pos=ftell(fp);   
  }
 	
 	//erase();//文字を消去
 	getch();
 	fclose(fp);
 	endwin();
}

//----------<<function>>--------------------------------------------------

