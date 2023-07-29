#include <stdio.h>
#include <stdlib.h>
struct S
{
    int head;
    int tail;
    int n;
    int A[100000];
};
int QUEUEEMPTY(struct S *pt)
{
    if(pt->head==pt->tail)
    {
        return 1;
    }
    return 0;
}
// int QUEUEEMPTY(struct S *pt,int n)
// {
//     if(pt->tail!=0 && pt->A[pt->tail-1]=='\0')
//     {
//         return 1;
//     }
//     else if(pt->tail==0 && pt->A[n-1]=='\0')
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
int QUEUEFULL(struct S *pt)
{
    //printf("%d %d\n",pt->head,pt->tail);
    if((pt->head==pt->tail+1)||(pt->head==0 && pt->tail==pt->n-1))
    {
        return 1;
    }
    return 0;
}
void ENQUEUE(struct S *pt,int k)
{
    if(QUEUEFULL(pt))
    {
        printf("Full\n");
    }
    else
    {
        //printf("entered\n");
        pt->A[pt->tail]=k;
        if(pt->tail==pt->n-1)
        {
            pt->tail=0;
        }
        else
        {
            pt->tail++;
        }
    }
}
int DEQUEUE(struct S *pt)
{
    if(QUEUEEMPTY(pt))
    {
        //printf("yes\n");
        return 100000001;
    }
    else
    {
        int c=pt->A[pt->head];
        if(pt->head==pt->n-1)
        {
            pt->head=0;
        }
        else
        {
            pt->head++;
        }
        return c;
    }
}
int main()
{
    char ch;
    int k,n;
    scanf("%d",&n);
    struct S *pt=(struct S*)malloc(sizeof(struct S));
    pt->head=0;
    pt->tail=0;
    pt->n=n;
    // for(int i=0;i<n;i++)
    // {
    //     pt->A[i]='\0';
    // }
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&k);
            ENQUEUE(pt,k);
        }
        else if(ch=='d')
        {
            scanf("%d",&k);
            while(k!=0)
            {
                int c=DEQUEUE(pt);
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
            if(QUEUEFULL(pt))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if(ch=='e')
        {
            if(QUEUEEMPTY(pt))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if(ch=='t')
        {
            return 0;
        }
    }
}