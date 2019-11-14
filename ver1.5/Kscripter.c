
#include "function.h"

void file_open(char *filename);
void display_clear_and_copy(bool s_flag, int *count, char back[LINE_MAX][N],char now[LINE_MAX][N]);
void finish(void);


int main(void){
  
  int Load_count=0;                //何行読み込んだかを記憶しておく変数
  int line_length;								 //文字配列の長さを格納する変数
  int ch;									        //getch()の中身を保存する関数    
  
  char origin[N];					        //txtから一行コピーした文字配列
  char case_pattern[N];		        //条件分岐の先頭へ移動するために必要なもの
  char nowlog[LINE_MAX][N];       //映しだされている画面の文字を格納
  char backlog[LINE_MAX][N];			//バックログ表示に用いる文字列
  
  char fname[]="text/kazu.txt";  //コマンドライン引数で与えるため、後々消去
  
  bool select_flag=false;			        //false:SELECTなし , true:SELECTあり
  bool case_start=false;		        //選択肢をキーが押した瞬間に書き始めさせるためのフラグ
  bool skip_flag=false;
  

  //ファイルを開く。失敗するとNULLを返す
  file_open(fname);
  
	//初期化
	initialize();

  //タイトル画面作成
  Load_first_display();
  
	//<<txtデータが末端に行くまで繰り返す>>
  while(fgets(origin,N,fp)!=NULL){
    
    //改行文字のみの行は無視
    if(*origin=='\n')
    	continue;
    
    //画面がいっぱいになったら画面をクリアし、バックログを保存
    display_clear_and_copy(select_flag,&Load_count, backlog, nowlog);
      
    //一行の長さを図る(\n込み)
    line_length=strlen(origin);
  
    //SELECTを見つけたらSELECT_ENDまで読み込み一気に出力する
    if(select_opt(origin, &select_flag, &case_flag, &lcase_flag, &Load_count, nowlog)==REACT)
      continue;
    
    //CASE関連を処理する関数群
    if(case_binary(origin, &case_flag, &lcase_flag, case_pattern, &case_start, Load_count, nowlog, backlog)==REACT)
      continue;
	    
    //画面出力(case_binaryにもgetchがあるため、その関数からリアクションがある場合はgetchを起動させない(おそらく)(?))
    if(case_start==false)
    	ch=getch();
    else
      case_start=false;
      
    switch(ch){    	
    	case 'b':
    	  b_log(backlog, nowlog, &Load_count);
    	  continue;
    	  
    	case 'p':
    		dis_pause(Load_count, nowlog);
    		continue;
    	
    	case 's':
    		save(before_fp_pos, case_flag, lcase_flag, Load_count, nowlog);
    		//printw("save_byte=%ld\n",save_byte);
    		continue;
    		
    	default:
    		write_text(line_length, origin, nowlog, &Load_count);
    		break;
    }
    
    //一つ前のファイルの位置を覚えさせておく(?)
    before_fp_pos=ftell(fp);     
  }
 	
 	//erase();//文字を消去
 	finish();
}


//----------<<function>>--------------------------------------------------
void file_open(char *filename){
  fp=fopen(filename,"r");
  if(fp==NULL){
    printf("%s file not open!\n",filename);
    exit(1);
  }
}

void display_clear_and_copy(bool s_flag, int *count, char back[LINE_MAX][N],char now[LINE_MAX][N]){
  int i;
  
  if(*count%LINE_MAX==0){
    erase();
    for(i=0;i<LINE_MAX;i++){
      strcpy(back[i],now[i]);
  	}
  	*count=0;
  	
  	if(s_flag==true && *count == 0)
  		*count++;	
  }
}

void write_nowlog(int line,char a_now[LINE_MAX][N]){
	int i;
	
	for(i=0;i<line%LINE_MAX;i++)
    printw("%s",a_now[i]);
}

void finish(void){
  getch();
 	fclose(fp);
 	endwin();
}


