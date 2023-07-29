#include <stdio.h>
#include <stdlib.h>
struct S
{
    int top;
    int A[100000];
    int n;
};
int STACK_EMPTY(struct S *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    return 0;
}
void print(struct S *st)
{
    for(int i=0;i<st->top+1;i++)
    {
        printf("%d ",st->A[i]);
    }
    printf("\n");
}
int STACK_FULL(struct S *st)
{
    if(st->top==st->n-1)
    {
        return 1;
    }
    return 0;
}
int POP(struct S *st)
{
    if(STACK_EMPTY(st))
    {
        return 100000001;
    }
    else
    {
        st->top-=1;
        //printf("%d\n",st->A[st->top+1]);
        return st->A[st->top+1];
    }
}
void PUSH(struct S *st,int k)
{
    if(STACK_FULL(st))
    {
        printf("Full\n");
    }
    else
    {
        st->top+=1;
        st->A[st->top]=k;
        //printf("%d\n",st->top);
    }
}
int main()
{
    struct S *pt=(struct S*)malloc(sizeof(struct S));
    pt->top=-1;
    char ch;
    int k,n;
    scanf("%d",&n);
    pt->n=n;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&k);
            PUSH(pt,k);
        }
        else if(ch=='d')
        {
            scanf("%d",&k);
            while(k!=0)
            {
                int c=POP(pt);
                if(c==100000001)
                {
                    printf("Empty ");
                }
                else
                {
                    printf("%d ",c);
                }
                k--;
            }
            printf("\n");
        }
        else if(ch=='f')
        {
            int c=STACK_FULL(pt);
            if(c==0)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
        else if(ch=='e')
        {
            int c=STACK_EMPTY(pt);
            if(c==0)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
        else if(ch=='p')
        {
            print(pt);
        }
        else if(ch=='t')
        {
            return 0;
        }
    }
}