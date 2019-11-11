#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        FILE *fp;
        fpos_t fpos, tmppos;
        char    s[256];

        if((fp = fopen("TEMP.FIL", "w+")) == NULL ) {
                fprintf(stderr,"入力ファイルオープンエラー\n");
                exit(EXIT_FAILURE);
        }

        /* ファイル位置の退避 */
        fgetpos(fp, &fpos);
        printf("最初のファイル位置: %ld\n", fpos);

        /* ファイルに7文字書き込み */
        fputs("ABCDEFG",fp);

        fgetpos(fp, &tmppos);
        printf("書き込み後のファイル位置: %ld\n", tmppos);

        /* ファイル位置を元に設定 */
        if(fsetpos(fp, &fpos) == 0) {
                fgetpos(fp, &tmppos);
                printf("元に戻したファイル位置: %ld\n", tmppos);
                fgets(s, sizeof(s), fp);
                printf("ファイル内容： %s\n",s);
        }
        else {
                fprintf(stderr, "fsetpos 異常\n");
                exit(EXIT_FAILURE);
        }

        fclose(fp);
        return 0;
}
