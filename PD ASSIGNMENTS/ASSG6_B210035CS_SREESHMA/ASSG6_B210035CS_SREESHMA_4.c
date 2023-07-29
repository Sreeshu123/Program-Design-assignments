#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct S
{
    struct node *head;
    struct node *tail;
};
int QUEUEEMPTY(struct S *pt)
{
    if(pt->tail==NULL)
    {
        return 1;
    }
    return 0;
}
struct node * CREATE_NODE(int k)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data=k;
    link->next=NULL;
    return link;
}
void ENQUEUE(struct S *pt,int k)
{
    struct node *link=CREATE_NODE(k);
    if(pt->head==NULL)
    {
        pt->head=link;
    }
    else
    {
        pt->tail->next=link;
    }
    pt->tail=link;
}
int DEQUEUE(struct S *pt)
{
    if(QUEUEEMPTY(pt))
    {
        return 100000001;
    }
    else
    {
        int c=pt->head->data;
        if(pt->head==pt->tail)
        {
            pt->tail=NULL;
        }
        pt->head=pt->head->next;
        return c;
    }
}
int main()
{
    int k;
    char ch;
    struct S *pt=(struct S*)malloc(sizeof(struct S));
    pt->head=NULL;
    pt->tail=NULL;
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