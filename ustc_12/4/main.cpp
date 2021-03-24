#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
    int n=0,m=0,a,b,k,flag;//flag为此次购票成功与否，1成功，0失败
    int station[MAX];
    FILE *fp=NULL,*fp2=NULL;
    if((fp=fopen("ticket.in","r"))==NULL)
    {
        printf("fail to open file");
        getchar();
        exit(1);
    }
    if((fp2=fopen("ticket.out","w"))==NULL)
    {
        printf("fail to save file");
        getchar();
        exit(1);
    }
    fscanf(fp,"%d%d",&n,&m);
    for(int i=0; i<MAX; i++) station[i]=m; //设置每个车站载客量上限
    for(int i=0; i<n; i++)
    {
        flag=1;//首先默认购票成功
        fscanf(fp,"%d%d%d",&a,&b,&k);
        for(int j=a; j<b; j++)
            if(k>station[j])
                flag=0;
        if(flag)
            for(int j=a; j<b; j++)
                station[j]-=k;
        fprintf(fp2,"%d\n",flag);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
