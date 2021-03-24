#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main()
{
    int save[MAX];
    int pos=0;
    FILE *fp,*fp2;
    fp=fopen("2.in","r");
    if(!fp) exit(1);
    fp2=fopen("2.out","w");
    if(!fp2) exit(1);
    while(!feof(fp))
    {
        fscanf(fp,"%d",&save[pos]);
        pos++;
    }
    int sum=0;
    for(int i=0;i<pos;i++)
        sum+=save[i];
    fprintf(fp2,"%d",sum);
    fclose(fp);
    fclose(fp2);
    return 0;
}
