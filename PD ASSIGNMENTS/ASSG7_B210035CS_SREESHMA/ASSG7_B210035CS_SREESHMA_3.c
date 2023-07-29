#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int A[10000];
};
int ISOP(char k)
{
    if(k=='+'||k=='-'||k=='*'||k=='/')
    {
        return 1;
    }
    return 0;
}
int POP(struct stack *pt)
{
    if(pt->top==-1)
    {
        return -100000001;
    }
    else
    {
        pt->top--;
        return pt->A[pt->top+1];
    }
}
void PUSH(struct stack *pt,int k)
{
    pt->A[++pt->top]=k;
}
int CONVERT(char s[])
{
    int k;
    sscanf(s,"%d",&k);
    //printf("%d\n",k);
    return k;
}
int EVALUATE(int a,int b,char op)
{
    if(op=='+')
    {
        return a+b;
    }
    else if(op=='-')
    {
        return a-b;
    }
    else if(op=='*')
    {
        return a*b;
    }
    else if(op=='/')
    {
        return a/b;
    }
}
int EVALUATEPOSTFIX(struct stack *pt,char e[])
{
    int i,j,c;
    for(i=0;e[i]!='\0';i++)
    {
        //printf("%c\n",e[i]);
        int check=ISOP(e[i]);
        //printf("%d\n",check);
        if (check==1)
        {
            int b=POP(pt);
            int a=POP(pt);
            c=EVALUATE(a,b,e[i]);
            PUSH(pt,c);
            i++;
        }
        else
        {
            //printf("entered\n");
            char s[5];
            for(j=0;j<5;j++)
            {
                s[j]='\0';
            }
            //j=i;
            int q=0;
            while(e[i]!=' ')
            {
                s[q]=e[i];
                q++;
                i++;
            }
            //printf("printing s\n");
            //printf("%s\n",s);
            int a=CONVERT(s);
            PUSH(pt,a);
            //i=j;
        }
    }
    return c;
}
int main()
{
    struct stack ptt,*pt;
    pt=&ptt;
    pt->top=-1;
    int n;
    scanf("%d",&n);
    int i,j,out[n];
    char e[10000];
    for(i=0;i<10000;i++)
    {
        e[i]='\0';
    }
    getchar();
    for(j=0;j<n;j++)
    {
        fgets(e,sizeof(e),stdin);
        //printf("%s",e);
        out[j]=EVALUATEPOSTFIX(pt,e);
    }
    for(j=0;j<n;j++)
    {
        printf("%d\n",out[j]);
    }
}