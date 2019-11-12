
#include "function.h"

void Load_first_display(void){
	FILE *fp_load;
	int ch;

  long load_byte;

	char fname[]="save/save.txt";
	
	char title[]= {"title display\n\n\n\n\n\n\n"};
	char start[]= {"(s)start\n\n"};
	char load[]=  {"(l)load\n\n"};
	char o_exit[]={"(e)exit\n\n"};

	printw(title);
	printw(start);
	printw(load);
	printw(o_exit);
	refresh();

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
  			
  			fscanf(fp_load,"%ld,%d,%d",&load_byte,&case_flag,&lcase_flag);
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
  refresh();
  usleep(2*100000);	
	erase();
}
