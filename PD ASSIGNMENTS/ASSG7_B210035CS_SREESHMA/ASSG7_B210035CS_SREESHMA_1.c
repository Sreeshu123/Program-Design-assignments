#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    char A[10000];
};
void PRINT(struct stack *pt)
{
    for(int i=0;i<pt->top+1;i++)
    {
        printf("%c ",pt->A[i]);
    }
    printf("\n");
}
char POP(struct stack *pt)
{ 
    //printf("check\n");
    char ch = pt->A[pt->top];
    pt->top = pt->top-1;
    return ch;
}
void PUSH(struct stack *pt,char k)
{
    pt->top++;
    pt->A[pt->top]=k;
}
char * INFIXTOPOSTFIX(struct stack *pt,char e[])
{
    //printf("Here");
    int k=0,p=0;
    char post[10000];
    while(e[k]!='\0')
    {
        char c=e[k];
        //printf("%c\n",c);
        if(c>='a' && c<='z')
        {
            post[p]=c;
            p++;
        }
        else if(c=='*'||c=='/')
        {
            // printf("H");
            while(1)
            {
                char t=pt->A[pt->top];
                if(t=='*'||t=='/')
                {
                    POP(pt);
                    post[p++]=t;
                }
                else
                {
                    break;
                }
            }
            PUSH(pt,c);
        }
        else if(c=='+'||c=='-')     
        {
            //printf("pluss");
          //top element in stack
            //printf("%c",t);
            while(1)
            {
                char t=pt->A[pt->top];
                //printf("%c",t);
                //printf("m");
                if(t!='#' && t!='(')
                {
                    POP(pt);
                    post[p++]=t;
                }
                else
                {
                    break;
                }
                //printf("%c   %d",t,  pt->top);
            
            }
            PUSH(pt,c);
        }
        else if(c==')')
        {
            while(1)
            {
                char t=pt->A[pt->top];
                //printf("%c\n",t);
                if(t=='(')
                {
                    break;
                }
                else
                {
                    POP(pt);
                    post[p++]=t;
                }
                    //printf("%c\n",t);
            }
            POP(pt);
            //printf("%c\n",x);
        }
        else if(c=='(')
        {
            PUSH(pt,c);
        }
        k++;
        //printf("%s\n",post);
        //PRINT(pt);
    }
    char t=pt->A[pt->top];
    while(t!='#')
    {
        post[p++]=POP(pt);
        t=pt->A[pt->top];
    }
    char *po=post;
    return po;
}
int main()
{
    // struct stack *pt=(struct stack*)malloc(sizeof(struct stack));
    int i,j,n;
    scanf("%d",&n);
    char exp[n][10000];
    struct stack ptt, *pt;
    pt=&ptt;
    pt->top=-1;
    char e[10000];
    for(int i=0; i<10000; i++){
        e[i]='\0';
    }
    PUSH(pt,'#');
    for(i=0;i<n;i++)
    {    scanf("%s",e);
        //printf("%s",e);
        char *post=INFIXTOPOSTFIX(pt,e);
        for(j=0;post[j]!='\0';j++)
        {
            exp[i][j]=post[j];
        }
        while(j<10000)
        {
            exp[i][j]='\0';
            j++;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n",exp[i]);
    }
    return 0;
}