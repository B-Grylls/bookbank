#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
    int n=0,m=0,a,b,k,flag;//flagΪ�˴ι�Ʊ�ɹ����1�ɹ���0ʧ��
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
    for(int i=0; i<MAX; i++) station[i]=m; //����ÿ����վ�ؿ�������
    for(int i=0; i<n; i++)
    {
        flag=1;//����Ĭ�Ϲ�Ʊ�ɹ�
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
