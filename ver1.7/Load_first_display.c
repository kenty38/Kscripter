
#include "function.h"

void display_title(char *titl, char *star, char *s_lo, char *s_ex);
void load_savedate(long *L_byte);


void Load_first_display(void){
	int ch;

  long load_byte;
	
	char *title={'\0'};
	char start[]= {"(s)start\n\n"};
	char load[]=  {"(l)load\n\n"};
	char s_exit[]={"(e)exit"};


  display_title(title, start, load, s_exit);

	while(1){
		ch=getch();
	
		switch(ch){
			case 's':
				printw("start\n");
				break;
			
			case 'l':
				printw("loading...\n");
  			load_savedate(&load_byte);
				break;
			
			case 'e':
				printw("e pushed\n");
				endwin();
				exit(1);
				break;
			
			default:
				continue;
		}
		
		break;
	}
  refresh();
  usleep(2*100000);	
	erase();
	
	create_frame(FRAME_FILENAME);
	draw_AA(AA_X,AA_Y,AA_FILENAME);
}


//-------------------<function>-------------------
void display_title(char *titl, char *star, char *s_lo, char *s_ex){
	
	//titleのAA記述
	create_frame(TITLE_FILENAME);
	
	mvprintw(10,3,star);
	mvprintw(12,3,s_lo);
	mvprintw(14,3,s_ex);
	printw("\n\n--------------------------------------------------------------------------------\n");
	refresh();  
}


void load_savedate(long *L_byte){
  FILE *fp_load;
  
  fp_load=fopen(SAVE_FILENAME,"r");		//ファイルを開く。失敗するとNULLを返す
 	
 	if(fp_load==NULL){
    printf("%s file not open!\n",SAVE_FILENAME);
    exit(1);
  }
  			
  fscanf(fp_load,"%ld,%d,%d,%s",L_byte,&case_flag,&lcase_flag,now_AA_file);
  //printf("load_byte=%ld\n",load_byte);
  fseek(fp,*L_byte,SEEK_SET);
}


