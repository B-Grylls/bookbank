#include <stdio.h>
#include <stdlib.h>
//#define TRUE 1
//#define FALSE 0
#include <string.h>
#include<stdbool.h>

bool DetectFloat(char* str)
//判断是否为浮点数
{
    while(*str!='\0')
    {
        if(*str=='e'||*str=='E'||*str=='.')
            return true;
        else str++;
    }
    return false;
}
int main()
{
    FILE* fp,*fp2;
    if((fp=fopen("string.in","r"))==NULL)
    {
        printf("file open false\n");
        getchar();
        exit(1);
    }
    if((fp2=fopen("string.out","w"))==NULL)
    {
        printf("file create false\n");
        getchar();
        exit(1);
    }
    char a[20],b[20];
    fscanf(fp,"%s%s",a,b);
    printf("%s\n%s",a,b);
    if(DetectFloat(a)||DetectFloat(b))//任意一个是浮点数
    {
        double x,y;
        x=atof(a);
        y=atof(b);
        fprintf(fp2,"%.9e",x+y);
    }
    else
    {
        int x=atoi(a);
        int y=atoi(b);
        fprintf(fp2,"%d",x+y);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
