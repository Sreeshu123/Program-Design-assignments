#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct S
{
    struct node *top;
};
struct node * CREATE_NODE(int k)
{
    struct node * link=(struct node*)malloc(sizeof(struct node));
    link->data=k;
    link->next=NULL;
    return link;
}
void print(struct S *pt)
{
    struct node *ptr=pt->top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int STACK_EMPTY(struct S *pt)
{
    if(pt->top==NULL)
    {
        return 1;
    }
    return 0;
}
void PUSH(struct S *pt,int k)
{
    struct node * link=CREATE_NODE(k);
    link->next=pt->top;
    pt->top=link;
    // if(pt->top==NULL)
    // {
    //     pt->top=link;
    // }
    // else
    // {
    //     struct node *ptr=pt->top;
    //     while(ptr->next!=NULL)
    //     {
    //         ptr=ptr->next;
    //     }
    //     ptr->next=link;
    // }
}
int POP(struct S *pt)
{
    if(pt->top==NULL)
    {
        return 100000001;
    }
    // 
    else
    {
        int c=pt->top->data;
        pt->top=pt->top->next;
        return c;
    }
}
int main()
{
    struct S *pt=(struct S*)malloc(sizeof(struct S));
    pt->top=NULL;
    char ch;
    int k;
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
        else if(ch=='e')
        {
            int c=STACK_EMPTY(pt);
            if(c==1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
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