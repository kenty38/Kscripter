#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include<unistd.h>
#include<locale.h>

#define N 256

#define LINE_MAX 10

#define SAME 0

#define REACT -1

FILE *fp;

int case_flag;				//<CASE_LAUNCH> , <makeCASE_TERMINAL>用のフラグ 
int lcase_flag;				//<X.CASE Y> , <CASE_END>用のフラグ (2つともinitialize.cで初期化)
                      //X:case_flag, Y:lcase_flag

long before_fp_pos;        //一つ前のfpの位置を保存


//function
extern void initialize(void);

extern void Load_first_display(void);

extern int Load(void);

extern void b_log(char back[LINE_MAX][N],char now[LINE_MAX][N],int *Lline);

extern void dis_pause(int Lline,char now[LINE_MAX][N]);

extern int save(long byte_num,int cflag,int lcflag,int Lline,char now[LINE_MAX][N]);

extern void write_text(int length,char original[],char now[LINE_MAX][N],int *Lline);

extern int select_opt(char original[],bool *flag,int *cflag,int *lcflag,int *Lline,char now[LINE_MAX][N]);

extern int case_binary(char original[],int *c_flag,int *lc_flag,char x_case_y[],bool *start,int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]);

extern void write_nowlog(int line,char a_now[LINE_MAX][N]);

