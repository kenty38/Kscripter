
#include "function.h"

void display_save_string(void);

int save(long byte_num,int cflag,int lcflag,int Lline,char now[LINE_MAX][N]){
		FILE *fp_save;
		
		int i;
		char fname[]="save/save.txt";
		
		fp_save=fopen(fname,"w");		//ファイルを開く。失敗するとNULLを返す
 	  if(fp_save==NULL){
    	printf("%s file not open!\n",fname);
    	return -1;
    }
		//ファイルのどこまで進んだかを保存
		fprintf(fp_save,"%ld,%d,%d\n",byte_num,cflag,lcflag);
		
		display_save_string();
		write_nowlog(Lline,now);
		
		fseek(fp,before_fp_pos,SEEK_SET);
		
		fclose(fp_save);		
		return 1;
}


//-------------------<function>-------------------
void display_save_string(void){
	erase();
	printw("\n\n\n\n\n\n\n<<<save_complete!!>>>\n");
	refresh();
	sleep(2);
	erase();
	create_frame(FRAME_FILENAME);
}
