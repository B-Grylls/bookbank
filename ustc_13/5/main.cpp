#include <stdio.h>
#include<stdlib.h>
int N;
int count=0;//记录排列总数
bool IsPlaceOk(int *pos,int row,int col)
{
    for(int i=1; i<row; i++)
        if(pos[i]==col || pos[i]-i==col-row ||pos[i]+i == col+row)
            return false;
    return true;
}
void addQueen(int *pos,int row)
{
    if(row>N)
    {
        count++;
        return;
    }
    for(int i=1;i<=N;i++)
        if(IsPlaceOk(pos,row,i))
    {
        pos[row]=i;
        addQueen(pos,row+1);
    }
}
int main()
{

    FILE *fp,*fp2;
    fp=fopen("5.in","r");
    if(!fp) exit(1);
    fp2=fopen("5.out","w");
    if(!fp2) exit(1);
    fscanf(fp,"%d",&N);
    int pos[N+1];//pos[i]为第i行皇后所在列数
    addQueen(pos,1);
    fprintf(fp2,"%d",count);
    fclose(fp);
    fclose(fp2);
    return 0;
}
