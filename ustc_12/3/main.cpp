#include<stdio.h>
#include<stdlib.h>
#include<stack>
#define MAX 100
using namespace std;
int main()
{
    stack <int> s;
    int indegree[MAX]= {0};
    int matrix[MAX][MAX]= {0};
    int work[MAX]= {0};
    int pos=0,max=0;
    char ch;
    FILE *fp,*fp2;
    fp=fopen("task.in","r");
    if(!fp) exit(1);
    fp2=fopen("task.out","w");
    if(!fp2) exit(1);
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
        if(ch=='k')
        {
            fscanf(fp,"%d",&work[pos]);
            if(work[pos]>max) max=work[pos];
            if(pos>0)
            {
                matrix[work[0]][work[pos]]=1;
                indegree[work[pos]]++;
            }
            pos++;
        }
        if(ch=='\n')
            pos=0;
    }
    for(int i=0; i<=max; i++)
        if(indegree[i]==0) s.push(i);
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        fprintf(fp2,"Task%d ",temp);
        for(int i=0;i<=max;i++){
            if(matrix[temp][i]==1)
                if(--indegree[i]==0)
                    s.push(i);
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
