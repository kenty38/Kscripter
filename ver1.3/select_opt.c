
/**************************************************************
* 選択肢を一気に出力する関数。																	 	*
* originが<SELECT>にあるときにフラグを立たせる。									 	*
* <CASE>が入れ子構造の時,<IF>が飛ばせるようにcase_flagを利用する。 	*
*																														　	*
* originが<SELECT_END>にある時はフラグを折り、<SELECT>と						*
* <SELECT_END>に挟まれた文章を出力する。													*
*																															*	
***************************************************************/

#include "function.h"

int select_opt(char original[], bool *flag,int *select_number,int *cflag,int *lcflag,int *Lline,char now[LINE_MAX][N]){

  if(strcmp(original,"<SELECT>\n")==SAME && *cflag==*lcflag){          //originが<SELECT>の時 
    *flag=true;
    *select_number=0;
    //もしif文がLINE_MAXを超過するならば、nowlogを新しいものに切り替える
    if(*Lline%LINE_MAX>=LINE_MAX-2){
      while(*Lline==LINE_MAX)
        *Lline=*Lline+1;
      return REACT;
    }
  }
    else if(strcmp(original,"<SELECT_END>\n")==SAME){ //originが<SELECT_END>の時
      *flag=false;
      usleep(1*90000);
      refresh();
      return REACT;
    }
    
    //<>以外のものを記述
    if(*flag==true){
      //originが<SELECT>文と同じ時は出力しない
      if(strcmp(original,"<SELECT>\n")!=SAME){
        printw("%s",original);
        strcpy(now[(*Lline)%LINE_MAX],original);
        *Lline=*Lline+1;
        //printw("%s\n",now[*Lline-1]);
        select_number++;
      }
        return REACT;  
    }
 
    return 1;
}
