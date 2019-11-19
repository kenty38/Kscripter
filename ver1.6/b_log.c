
#include "function.h"

void display_backlog_immd(char b[LINE_MAX][N]);



void b_log(char back[LINE_MAX][N],char now[LINE_MAX][N],int *Lline){
    	  
  erase();
  
  printw("<<backlog>>\n");  
  display_backlog_immd(back);
 
 	create_frame(FRAME_FILENAME);
 	draw_AA(AA_X,AA_Y,AA_FILENAME);
 	write_nowlog(*Lline,now);
    
  fseek(fp,before_fp_pos,SEEK_SET);  	    
}



//-------------------<function>-------------------
void display_backlog_immd(char b[LINE_MAX][N]){
	 
	 int i;
	 for(i=0;i<LINE_MAX;i++){
    printw("%s",b[i]);
  }
  getch();
  erase();
}

