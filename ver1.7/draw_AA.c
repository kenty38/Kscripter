
#include "function.h"

void draw_AA(int x, int y, char *filename){
	int i=0;
	char line[N];
	FILE *fp2;
	
	file_open(filename,&fp2);
  
  while(fgets(line,N,fp2)!=NULL){
	
	  mvprintw(x+i,y,line);
	  mvprintw(x+i,FRAME_LAST_Y,"|");
	  i++;
	}
	
	refresh();
	fclose(fp2);
}


int draw_AA_from_text(int x, int y, char original[]){
	int i=0;
	char line[N];
	FILE *fp2;
	
	if(strstr(original,"draw--") == NULL){
    return 1;
  }

  else{
    sscanf(original,"draw--%s\n",now_AA_file);
	  file_open(now_AA_file,&fp2);
  
    while(fgets(line,N,fp2)!=NULL){
	
	    mvprintw(x+i,y,line);
	    mvprintw(x+i,FRAME_LAST_Y,"|");
	    i++;
	  }
	
	  refresh();
	  fclose(fp2);
	  
	  return AA_DRAW;
	}
	
}
