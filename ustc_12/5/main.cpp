#include <stdio.h>
#include<stdlib.h>
#define INFINITY 500
#include<stack>

using namespace std;
void Dijkstra(int **adj,int n,int begin,int*&pre,int *&length);

int main()
{
    stack <int> S;
    int **adj,*length,*pre;
    int n,m,s,t;
    int begin,end,weight;//begin与end之间的path
    FILE *fp,*fp2;
    fp=fopen("road.in","r");
    if(!fp) exit(1);
    fp2=fopen("road.out","w");
    if(!fp2) exit(1);
    fscanf(fp,"%d%d%d%d",&n,&m,&s,&t);
    adj=(int **)malloc(n*sizeof(int*));
    if(!adj) exit(1);
    for(int i=0;i<n;i++)
        if(!(adj[i]=(int*)malloc(n*sizeof(int))))
            exit(1);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adj[i][j]=INFINITY;
    for(int i=0; i<m; i++)
    {
        fscanf(fp,"%d%d%d",&begin,&end,&weight);
        adj[begin][end]=weight;
        adj[end][begin]=weight;
    }
    length=(int *)malloc(n*sizeof(int));
    if(!length) exit(1);
    pre=(int *)malloc(n*sizeof(int));
    if(!pre) exit(1);
    for(int i=0;i<n;i++)
        pre[i]=s;
    Dijkstra(adj,n,s,pre,length);
    for(int k=end;k!=INFINITY;k=pre[k])
        S.push(k);
    while(!S.empty())
    {
        fprintf(fp2,"%d ",S.top());
        S.pop();
    }
    free(adj);
    free(length);
    free(pre);
    fclose(fp);
    fclose(fp2);
    return 0;
}
void Dijkstra(int **adj,int n,int begin,int* &pre,int *&length)
{
    bool final[n]= {false};
    pre[begin]=INFINITY;
    for(int i=0; i<n; i++)
        length[i]=adj[begin][i];
    length[begin]=0;//begin点归入集合
    final[begin]=true;
    for(int i=1; i<n; i++)//仅仅代表n-1次
    {
        int min=INFINITY;//当前离begin点最近距离
        int v;//下个准备合并的点
        for(int w=0; w<n; w++)
            if(!final[w] && length[w]<min)
            {

                v=w;
                min=length[w];
            }
        final[v]=true;//v点归入
        for(int w=0; w<n; w++) //更新最短距离表
            if(!final[w] && (min+adj[v][w]<length[w]))
            {
                length[w]=min+adj[v][w];
                pre[w]=v;
            }

    }
}
