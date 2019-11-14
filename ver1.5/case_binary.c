
#include "function.h"


void detect_case_launch(char original[],int *c_flag,int *lc_flag,char x_case_y[],int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]);
void detect_little_case(int *c_flag, int *lc_flag, char x_case_y[], bool *start);
void detect_terminal(int *c_flag, int *ls_case);



int case_binary(char original[],int *c_flag,int *lc_flag,char x_case_y[],bool *start,int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]){
  int terminal_count; //caseが終了したかどうか知るための変数.0より小さい場合はcaseフラグを全て0にする.
 
  //originが<<CASE_LAUNCH>>の時(返り値REACT)
  if(strcmp(original,"<<CASE_LAUNCH>>\n")==0 && *c_flag==*lc_flag){         
      *c_flag=*c_flag+1;
      
      //originが<CASE_LAUNCH>にいるときに選択肢を選ぶ
      detect_case_launch(original, c_flag, lc_flag, x_case_y, Lline, now, back);	
      
      return REACT;    
    }
    
    //<<CASE_LAUNCH>>を既に発見している時
    if(abs(*c_flag-*lc_flag)==1){
    
      if(strcmp(original, x_case_y)==SAME)
        detect_little_case(c_flag, lc_flag, x_case_y,start);
 
      else if(strcmp(original,"<<CASE_TERMINAL>>\n")==SAME){
        terminal_count=*c_flag - 1;
        
        if(terminal_count<=0){
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



//------------------<<<function>>-----------------------------------------------
void detect_case_launch(char original[],int *c_flag,int *lc_flag,char x_case_y[],int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]){
	int ch;
	
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
          	save(before_fp_pos, case_flag-1, *lc_flag,Lline,now);
          	continue;          	
          default:
            continue;    
        }
       break;
      }
	
}

void detect_little_case(int *c_flag, int *lc_flag, char x_case_y[],bool *start){
	*lc_flag=*lc_flag+1;
	sprintf(x_case_y, " ");
  *start=true;
}

void detect_terminal(int *c_flag, int *ls_case){
	int terminal_count;
	
	terminal_count=*c_flag;
	terminal_count--;
	
}


