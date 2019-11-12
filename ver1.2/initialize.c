
#include "function.h"

void initialize(int *c_flag, int *lc_flag){

	setlocale(LC_ALL,"");
  start_color();					//カラー属性を扱うための初期化
  initscr();							//スクリーン初期化(ncurses.h)
  noecho();								//端末上に入力文字を表示しない(ncurses.h)
  
  *c_flag=OFF;
  *lc_flag=ON;

}
