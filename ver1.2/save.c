
#include "function.h"

int save(long byte_num,int cflag,int lcflag,int Lline,char now[LINE_MAX][N]){
		FILE *fp_save;
		
		int i;
		char fname[]="save/save.txt";
		
		fp_save=fopen(fname,"w");		//ファイルを開く。失敗するとNULLを返す
 	  if(fp_save==NULL){
    	printf("%s file not open!\n",fname);
    	return -1;
    }
		
		fprintf(fp_save,"%ld,%d,%d\n",byte_num,cflag,lcflag);
		erase();
		printw("\n\n\n\n\n\n\n<<<save_complete!!>>>\n");
		refresh();
		sleep(2);
		erase();
		
		for(i=0;i<Lline%LINE_MAX;i++)
		  printw("%s",now[i]);
		
		fseek(fp,before_pos,SEEK_SET);
		
		fclose(fp_save);		
		return 1;
}
