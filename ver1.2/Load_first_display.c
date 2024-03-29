
#include "function.h"

void display_menu(char *v_title, char *v_start, char *v_load, char *v_exit);
void finish_function(void);

void Load_first_display(int *c_flag, int *lc_flag){
	FILE *fp_load;
	int ch;

  long load_byte;

	char fname[]="save/save.txt";
	
	//メニュー画面は事前に準備する可能性があるため全削除の可能性あり
	char title[]= {"title display\n\n\n\n\n\n\n"};
	char start[]= {"(s)start\n\n"};
	char load[]=  {"(l)load\n\n"};
	char o_exit[]={"(e)exit\n\n"};

	display_menu(title,start,load,o_exit);

	while(1){
		ch=getch();
	
		switch(ch){
			case 's':
				printw("start\n");
				break;
			
			case 'l':
				printw("loading...\n");			
				fp_load=fopen(fname,"r");		//ファイルを開く。失敗するとNULLを返す
 	  		
 				if(fp_load==NULL){
    			printf("%s file not open!\n",fname);
    			//return -1;
  			}
  			
  			fscanf(fp_load,"%ld,%d,%d",&load_byte,c_flag,lc_flag);
  			//printf("load_byte=%ld\n",load_byte);
  			fseek(fp,load_byte,SEEK_SET);
  			
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
 
 finish_function(); 
}


//-----------------------------------------------------------------------------------

void display_menu(char *v_title, char *v_start, char *v_load, char *v_exit){
  printw(v_title);
	printw(v_start);
	printw(v_load);
	printw(v_exit);
	refresh();
}

void finish_function(void){
  refresh();
  sleep(2);	//2秒待機
	erase();
}

