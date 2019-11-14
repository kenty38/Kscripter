
#include "function.h"

void initialize(){

	setlocale(LC_ALL,"");
  start_color();					//カラー属性を扱うための初期化
  initscr();							//スクリーン初期化
  noecho();								//端末上に入力文字を表示しない
  
  case_flag=0;
  lcase_flag=0;

}
