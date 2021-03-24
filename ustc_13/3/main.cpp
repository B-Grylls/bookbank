#include<stdio.h>
#include<stdlib.h>
#include<stack>


int main()
{
    int number,res;
    std::stack <int> s;
    FILE *fp,*fp2;
    fp=fopen("3.in","r");
    if(!fp) exit(1);
    fp2=fopen("3.out","w");
    if(!fp2) exit(1);
    fscanf(fp,"%d",&number);
    while(number)
    {
        res=number%2;
        s.push(res);
        number/=2;
    }
    while(!s.empty()){
        fprintf(fp2,"%d",s.top());
        s.pop();
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
