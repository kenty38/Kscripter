
#include "function.h"

void display_title(char *titl, char *star, char *s_lo, char *s_ex);
void load_savedate(long *L_byte, char *filename);


void Load_first_display(void){
	int ch;

  long load_byte;

	char fname[]="save/save.txt";
	
	char title[]= {"title display\n\n\n\n\n\n\n"};
	char start[]= {"(s)start\n\n"};
	char load[]=  {"(l)load\n\n"};
	char s_exit[]={"(e)exit\n\n"};


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
}


//-------------------<function>-------------------
void display_title(char *titl, char *star, char *s_lo, char *s_ex){

  printw(titl);
	printw(star);
	printw(s_lo);
	printw(s_ex);
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

