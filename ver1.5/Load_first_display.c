
#include "function.h"

void display_title(char *titl, char *star, char *s_lo, char *s_ex);
void load_savedate(long *L_byte, char *filename);


void Load_first_display(void){
	int ch;

  long load_byte;

	char fname[]="save/save.txt";
	
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
  			load_savedate(&load_byte,fname);
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
	
	create_AA_and_frame("display/frame.txt");
}


//-------------------<function>-------------------
void display_title(char *titl, char *star, char *s_lo, char *s_ex){
	
	//titleのAA記述
	create_AA_and_frame("display/p_l_s.txt");
	
	mvprintw(10,3,star);
	mvprintw(12,3,s_lo);
	mvprintw(14,3,s_ex);
	printw("\n\n--------------------------------------------------------------------------------\n");
	refresh();  
}


void load_savedate(long *L_byte, char *filename){
  FILE *fp_load;
  
  fp_load=fopen(filename,"r");		//ファイルを開く。失敗するとNULLを返す
 	
 	if(fp_load==NULL){
    printf("%s file not open!\n",filename);
    exit(1);
  }
  			
  fscanf(fp_load,"%ld,%d,%d",L_byte,&case_flag,&lcase_flag);
  //printf("load_byte=%ld\n",load_byte);
  fseek(fp,*L_byte,SEEK_SET);
}


