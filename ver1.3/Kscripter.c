
#include "function.h"

void dis_pause(int Lline,char now[LINE_MAX][N]);

int main(void){
  
  int i;
  int Load_count=0;                //何行読み込んだかを記憶しておく変数
  int line_length;								        //文字配列の長さを格納する変数
  //int select_num;					        //選択肢の個数(10個まで)
  int ch;									        //getch()の中身を保存する関数    
  
  char origin[N];					        //txtから一行コピーした文字配列
  char case_pattern[N];		        //条件分岐の先頭へ移動するために必要なもの
  char nowlog[LINE_MAX][N];       //映しだされている画面の文字を格納
  char backlog[LINE_MAX][N];			//バックログ表示に用いる文字列
  
  char fname[]="text/text2.txt";
  
  bool select_flag=false;			        //false:SELECTなし , true:SELECTあり
  bool if_start=false;		        //選択肢をキーが押した瞬間に書き始めさせるためのフラグ
  bool skip_flag=false;
  

  //ファイルを開く。失敗するとNULLを返す
  fp=fopen(fname,"r");
  if(fp==NULL){
    printf("%s file not open!\n",fname);
    exit(1);
  }
  
  
	//初期化
	initialize();

  //タイトル画面作成
  Load_first_display();

  
	//<<txtデータが末端に行くまで繰り返す>>
  while(fgets(origin,N,fp)!=NULL){
    
    //改行文字のみの行は無視
    if(*origin=='\n')
    	continue;
    
    //nowlogが24行に達した時、今までのログをバックログ文字配列に格納し、
    //バックログ呼び出し時にはbacklogを用いる。
    //これは文字が画面にいっぱいになるたびに繰り返される
    if(Load_count%LINE_MAX==0){
      erase();
      for(i=0;i<LINE_MAX;i++)
        strcpy(backlog[i],nowlog[i]);
    }
      
    //一行の長さを図る(\n込み)
    line_length=strlen(origin);
  
    //<<SELECT管理>>
    if(select_opt(origin, &select_flag, &case_flag, &lcase_flag, &Load_count, nowlog)==REACT)
      continue;
    //<<SELECT終了>>
    
    //<<CASE管理>>
    if(case_binary(origin, &case_flag, &lcase_flag, case_pattern, &if_start, Load_count, nowlog, backlog)==REACT)
      continue;
    //<<CASE終了>>
	    
    //画面出力(case_binaryにもgetchがあるため、その関数からリアクションがある場合はgetchを起動させない(おそらく))
    if(if_start==false)
    	ch=getch();
    else
      if_start=false;
      
    switch(ch){
    	
    	case 'b':
    	  b_log(backlog, nowlog, &Load_count);
    	  continue;
    	  
    	case 'p':
    		dis_pause(Load_count, nowlog);
    		continue;
    	
    	case 's':
    		save(before_pos, case_flag, lcase_flag, Load_count, nowlog);
    		//printw("save_byte=%ld\n",save_byte);
    		continue;
    		
    	default:
    		write_text(line_length, origin, nowlog, &Load_count);
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
void write_nowlog(int line,char a_now[LINE_MAX][N]){
	int i;
	
	for(i=0;i<line%LINE_MAX;i++)
    printw("%s",a_now[i]);

}
