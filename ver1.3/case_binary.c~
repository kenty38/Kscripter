
/**********************************************
* 選択肢を分岐させるための関数。								　	*
* case_flagとlcase_flagは入れ子構造を考慮して	 	*	
* boolではなくint型にしている。									 	*
*	case_flagが先に増え,lcase_flagが先に減る			　 *
* 性質を用いてif文の条件分岐を行っている。	        *
*			                                      	*
*	選択肢内のセーブは、ロード時に<<CASE_LAUNCH>>     *
* を二重に読み込みflagに1余分に足してしまうため、		*
* 1を引いている。  
***********************************************/

/*
  case文を使うときは必ず<<CASE_LAUNCH>>から始め<<CASE_TERMINAL>>で終わらせる
  <<CASE_LAUNCH>>の時、返り値はREACT
  
*/

#include "function.h"

int case_binary(char original[],int *c_flag,int *lc_flag,char x_case_y[],bool *start,int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]){
  int ch;
  int terminal_count; //caseが終了したかどうか知るための変数.0より小さい場合はcaseフラグを全て0にする.
  //bool check;  
 
  //originが<<CASE_LAUNCH>>の時(返り値REACT)
  if(strcmp(original,"<<CASE_LAUNCH>>\n")==0 && *c_flag==*lc_flag){           
      *c_flag=*c_flag+1;
      
      //originが<CASE_LAUNCH>にいるときに選択肢を選ぶ
      while(1){
        ch=getch();
        //printw("ch=%c\n",ch);
        switch(ch){
          case '1':
            sprintf(x_case_y,"<%d.CASE %c>\n",*c_flag,ch);
            break;
            
          case '2':
            sprintf(x_case_y,"<%d.CASE %c>\n",*c_flag,ch);
            break;
            
          case '3':
            sprintf(x_case_y,"<%d.CASE %c>\n",*c_flag,ch);
            break;
          
          case 'b':   	
    	  		b_log(back,now,&Lline);
    	  		continue;
            
          case 'p':
          	dis_pause(Lline,now);
          	continue;  
            
          case 's':
          	save(before_pos,case_flag-1,*lc_flag,Lline,now);
          	continue;
          	
          default:
            continue;    
        }
       break;
      }
      
      return REACT;    
    }
    
    //flagが立っていれば指定されたCASEまで飛ぶ
    if(abs(*c_flag-*lc_flag)==1){
    
      //<CASE X>にoriginがあるとき
      if(strcmp(original, x_case_y)==SAME){
        *lc_flag=*lc_flag+1;
        *start=true;
        sprintf(x_case_y," ");//???
      }
      else if(strcmp(original,"<<CASE_TERMINAL>>\n")==SAME){
        terminal_count=*c_flag;
        terminal_count--;
        if(terminal_count<0){
          *c_flag=0;
          *lc_flag=0;
          return REACT;
        }
        *c_flag=*c_flag-1;
      }
      return REACT;
    }
    
    //case_flagとlcase_flagの値が同じ時かつoriginalが<CASE_END>の時,lcase_flagを小さくする
    else if(*c_flag==*lc_flag){
      if(strcmp(original,"<CASE_END>\n")==SAME){
        *lc_flag=*lc_flag-1;
        return REACT;
      }
    }
    
    //if文に当てはまらなかったら正常終了
    return 1;
}



