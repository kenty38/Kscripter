
#include "function.h"

void draw_AA(int x, int y, char *filename){
	int i=0;
	char line[N];
	FILE *fp2;
	
	fp2=fopen(filename,"r");
  if(fp2==NULL){
    printf("%s file not open!\n",filename);
    exit(1);
  }
  
  while(fgets(line,N,fp2)!=NULL){
	
	  mvprintw(x+i,y,line);
	  mvprintw(x+i,FRAME_LAST_Y,"|");
	  i++;
	}
	
	refresh();
	fclose(fp2);
}
