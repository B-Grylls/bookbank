#include<stdio.h>
#include<stdlib.h>

void findprime(int max,int *prime);
int main()
{
    int number,typenum=0;
    int div1,div2;
    FILE *fp,*fp2;
    fp=fopen("4.in","r");
    if(!fp) exit(1);
    fp2=fopen("4.out","w");
    if(!fp2) exit(1);
    fscanf(fp,"%d",&number);
    int prime[number];
    for(int i=0;i<number;i++)
        prime[i]=0;
    findprime(number,prime);
    int k=1;
    for(int i=0;i<5;i++)
        printf("%d ",prime[i]);
    while(k<=prime[0] && prime[k]<=number/2)
    {
        div1=prime[k];
        div2=number-div1;
        for(int i=1; i<=prime[0]; i++)
            if(div2==prime[i])
                typenum++;
        k++;
    }
    fprintf(fp2,"%d",typenum);
    fclose(fp);
    fclose(fp2);
    return 0;
}
void findprime(int max,int *prime)//找出max以内所有素数并按顺序存放，并返回该数组
{
    int k=1;
    int math[max+1];
    for(int i=2; i<=max; i++) math[i]=1;
    math[1]=0;
    for(int i=1; i<=max; i++)
        if(math[i]!=0)
            for(int j=i+1; j<=max; j++)
                if(j%i==0) math[j]=0;
    for(int i=1; i<=max; i++)
        if(math[i]!=0)
        {
            prime[k++]=i;
            prime[0]++;
        }
}
