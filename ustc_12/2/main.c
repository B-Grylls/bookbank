#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* fp,*fp2;
    int n;
    if((fp=fopen("number.in","r"))==NULL)
    {
        printf("failure to open file\n");
        getchar();
        exit(1);
    }
    if((fp2=fopen("number.out","w"))==NULL)
    {
        printf("failure to output data\n");
        getchar();
        exit(1);
    }
    fscanf(fp,"%d",&n);
    int number[n];//存储n个整数
    int max,min;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&number[i]);
    }
    min=max=number[0];
    for(int i=0;i<n;i++)//找出最大最小值
    {
        if(number[i]>max)
            max=number[i];
        if(number[i]<min)
            min=number[i];
    }
    int p=max,q=min,r;//准备辗转相除法求最大公约数
    do{
        r=p-p/q*q;
        p=q;
        q=r;
    }while(r!=0);
    fprintf(fp2,"%d %d %d",min,max,p);
    fclose(fp);
    fclose(fp2);
    return 0;
}
