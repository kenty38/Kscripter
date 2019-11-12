
/**********************************************
* 選択肢を分岐させるための関数。								　	*
* case_flagとlcase_flagは入れ子構造を考慮して	 	*	
* boolではなくint型にしている。									 	*
*	case_flagが先に増え,lcase_flagが先に減る			　 *
* 性質を用いてif文の条件分岐を行っている。	        *
*			                                      	*
*	選択肢内のセーブは、ロード時に<CASE_LAUNCH>     *
* を二重に読み込みflagに1余分に足してしまうため、		*
* 1を引いている。  
***********************************************/

#include "function.h"

int case_binary(char original[],int *c_flag,int *lc_flag,char pattern[],bool *start,int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]){
  int ch;
  int terminal_point;
  bool check;  
 
  if(strcmp(original,"<CASE_LAUNCH>\n")==0 && *c_flag==*lc_flag){          //originが<CASE_LAUNCH>の時 
      *c_flag=*c_flag+1;
      
      //originが<CASE_LAUNCH>にいるときに選択肢を選ぶ
      while(1){
        check=false;
        ch=getch();
        //printw("ch=%c\n",ch);
        switch(ch){
          case '1':
            check=true;
            sprintf(pattern,"<%d.CASE %c>\n",*c_flag,ch);
            break;
            
          case '2':
            check=true;
            sprintf(pattern,"<%d.CASE %c>\n",*c_flag,ch);
            break;
            
          case '3':
            check=true;
            sprintf(pattern,"<%d.CASE %c>\n",*c_flag,ch);
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
      if(strcmp(original,pattern)==SAME){
        *lc_flag=*lc_flag+1;
        *start=true;
        sprintf(pattern," ");
      }
      else if(strcmp(original,"<CASE_TERMINAL>\n")==SAME){
        terminal_point=*c_flag;
        terminal_point--;
        if(terminal_point<0){
          *c_flag=0;
          *lc_flag=0;
          return REACT;
        }
        *c_flag=*c_flag-1;
      }
      return -1;
    }
    
    else if(*c_flag==*lc_flag){
      if(strcmp(original,"<CASE_END>\n")==SAME){
        *lc_flag=*lc_flag-1;
        return REACT;
      }
    }
    return 1;
}
