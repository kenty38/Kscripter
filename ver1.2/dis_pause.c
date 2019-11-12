
#include "function.h"

void dis_pause(int Lline,char now[LINE_MAX][N]){
	int i;
	int ch;
	
	erase();
	printw("\n\n\n\n\n\n<<Pause>>\n\n\n\n\n\n");
	printw("(r)restart\n");
	printw("(s)skip\n");
	printw("(e)exit\n");
	while(1){
		ch=getch();
		switch(ch){
			case 'r':
				erase();
				for(i=0;i<Lline%LINE_MAX;i++)
					printw("%s",now[i]);
				break;
		
			case 'p':
				erase();
				for(i=0;i<Lline%LINE_MAX;i++)
					printw("%s",now[i]);
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
	
	fseek(fp,before_pos,SEEK_SET);  //???
}
