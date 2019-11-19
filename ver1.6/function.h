#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include<unistd.h>
#include<locale.h>

#define FRAME_FILENAME "display/frame.txt"
#define TITLE_FILENAME "display/p_l_s.txt"
#define SAVE_FILENAME  "save/save.txt"
#define AA_FILENAME    "display/monor.txt"

#define N 256
#define LINE_MAX 7

#define TERMINAL_STRING_MAX 26

#define SAME 0
#define REACT -1

#define TEXT_X 14
#define TEXT_Y  5

#define AA_X 7
#define AA_Y 9

#define MESSAGE_LAST_Y 61
#define FRAME_LAST_Y 63

#define ASCII_LIST_START 33
#define ASCII_LIST_END 126

#define JCHARACTER_WIDTH 2
#define JAPANESE_BYTE 3

FILE *fp;

int case_flag;				//<CASE_LAUNCH> , <makeCASE_TERMINAL>用のフラグ 
int lcase_flag;				//<X.CASE Y> , <CASE_END>用のフラグ (2つともinitialize.cで初期化)
                      //X:case_flag, Y:lcase_flag

long before_fp_pos;        //一つ前のfpの位置を保存


//function
extern void initialize(void);

extern void Load_first_display(void);

extern void create_frame(char *filename);

extern void draw_AA(int x, int y, char *filename);

extern int Load(void);

extern void b_log(char back[LINE_MAX][N],char now[LINE_MAX][N],int *Lline);

extern void dis_pause(int Lline,char now[LINE_MAX][N]);

extern int save(long byte_num,int cflag,int lcflag,int Lline,char now[LINE_MAX][N]);

extern void write_text(int length,char original[],char now[LINE_MAX][N],int *Lline);

extern void write_text_new_line(int length,char original[],char now[LINE_MAX][N],int *Lline,char back[LINE_MAX][N]);

extern int select_opt(char original[],bool *flag,int *cflag,int *lcflag,int *Lline,char now[LINE_MAX][N]);

extern int case_binary(char original[],int *c_flag,int *lc_flag,char x_case_y[],bool *start,int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]);

extern void write_nowlog(int line,char a_now[LINE_MAX][N]);

