#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  int i,j,len;
  FILE *fp;
  char fname[]="text.txt";
  //*strではstrcpyでエラーが起きたが、str[]ではエラーが発生しなかった。
  //strcpyは前回のデータを一度消去してから上書きする(かも)
  //strlenは配列の長さではなく文字列の長さを返す。
  
  //char str[100]="simple";
  //char origin[200]="oimo";
  
  char str[100];
  char origin[200];
  
  if((fp=fopen(fname,"r"))==NULL){
    printf("%s file not open!\n",fname);
    return -1;
  }
  
  while(fgets(origin,256,fp)!=NULL){
    len = strlen(origin);
    strcpy(str,origin);
    str[len-1]='\0';
    printf("str=%s\n",strcat(str,"SSS"));
    printf("origin=%s\n",origin);
  }
/*  
  printf("str=%s\n",str);
  printf("origin=%s\n",origin);
  
  strcpy(str,origin);
  
  printf("str=%s\n",str);
  printf("origin=%s\n",origin);
  
  puts("");
  
  i=strlen(str);
  j=strlen(origin);
  printf("i=%d,j=%d\n",i,j);
*/
  return 1;
}
