
#include "function.h"

void create_AA_and_frame(char *filename){
	int i=0;
	char line[N]  ;
	
	FILE *fp2;
	
	fp2=fopen(filename,"r");
	
	if(fp2==NULL){
    printf("%s file not open!\n",filename);
    endwin();
    exit(1);
  }
	
	while(fgets(line,N,fp2)!=NULL){
	
	  mvprintw(i,1,line);
	  i++;
	}
	
	refresh();
	fclose(fp2);
}
