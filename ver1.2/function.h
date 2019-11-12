#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/ncurses.h"
#include"../include/unistd.h"
#include"../include/locale.h"

#define N 256
#define LINE_MAX 22

#define SAME 0
#define REACT -1

FILE *fp;

enum FLAG{
  ON,
  OFF
};


long before_pos;        //一つ前のfpの位置を保存


//function
extern void initialize(int *c_flag, int *lc_flag);

extern void Load_first_display(int *c_flag, int *lc_flag);

extern int Load(void);

extern void b_log(char back[LINE_MAX][N],char now[LINE_MAX][N],int *Lline);

extern void dis_pause(int Lline,char now[LINE_MAX][N]);

extern int save(long byte_num,int cflag,int lcflag,int Lline,char now[LINE_MAX][N]);

extern void write_text(int length,char original[],char now[LINE_MAX][N],int *Lline);

extern int select_opt(char original[],bool *flag,int *select_number,int *cflag,int *lcflag,int *Lline,char now[LINE_MAX][N]);

extern int case_binary(char original[],int *c_flag,int *lc_flag,char pattern[],bool *start,int Lline,char now[LINE_MAX][N],char back[LINE_MAX][N]);


