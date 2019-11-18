#include<stdio.h>
#include<string.h>

int main(void){
   FILE *fp;
   
   int ch;
   int pos=0;
   long tell;
   char origin[256];
   char fname[]="text/text3.txt";
   
   fp=fopen(fname,"r");

   if(fp==NULL){
    puts("このファイルは開けません");
   }
  
  
  fseek(fp,35,SEEK_SET);
  while(fgets(origin,256,fp)!=NULL){

    printf("1.現在%ldバイトです\n",ftell(fp));
    printf("%s\n",origin);
    
    if(strcmp(origin,"a\n")==0){
      puts("oimo");
    }
  
    //fseek(fp,tell,SEEK_SET); 
    //printf("2.現在%ldバイトです\n",ftell(fp));    
  }

  fclose(fp);
}
