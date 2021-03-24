#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main()
{
    int save[MAX];
    int pos=0;
    FILE *fp,*fp2;
    fp=fopen("1.in","r");
    if(!fp) exit(1);
    fp2=fopen("1.out","w");
    if(!fp2) exit(1);
    while(!feof(fp))
    {
        fscanf(fp,"%d",&save[pos]);
        pos++;
    }
    int max=save[0];
    for(int i=0;i<pos;i++)
        if(max<save[i])
        max=save[i];
    fprintf(fp2,"%d",max);
    fclose(fp);
    fclose(fp2);
    return 0;
}
