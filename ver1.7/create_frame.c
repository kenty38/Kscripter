
#include "function.h"

void create_frame(char *filename){
	int i=0;
	char line[N]  ;
	
	FILE *fp2;
	
	file_open(filename,&fp2);
	
	while(fgets(line,N,fp2)!=NULL){
	
	  mvprintw(i,1,line);
	  i++;
	}
	
	refresh();
	fclose(fp2);
}
