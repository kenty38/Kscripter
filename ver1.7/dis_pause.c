
#include "function.h"

void display_pause(void);


void dis_pause(int Lline,char now[LINE_MAX][N]){
	int i;
	int ch;
	
	display_pause();
	
	while(1){
		ch=getch();
		switch(ch){
			case 'r':
				erase();
				write_nowlog(Lline,now);
				break;
			
			case 'p':
				erase();
				write_nowlog(Lline,now);
				break;		
			
			case 'e':
				endwin();
				exit(1);
				break;
			
			default:
				continue;
		}
		break;
	}
	
	draw_AA(AA_X,AA_Y,now_AA_file);
	fseek(fp,before_fp_pos,SEEK_SET);
}


//-------------------<function>-------------------

void display_pause(void){
	erase();
	printw("\n\n\n\n\n\n<<Pause>>\n\n\n\n\n\n");
	printw("(r)restart\n");
	printw("(s)skip\n");
	printw("(e)exit\n");
}
