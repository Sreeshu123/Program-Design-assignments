#include <stdio.h>
#include <stdlib.h>
struct s
{
    int key;
    struct s *next;
};
struct ll
{
    struct s *head;
};
struct s * create_node(int key)
{
    struct s *link=(struct s*)malloc(sizeof(struct s));
    link->key=key;
    link->next=NULL;
    return link;
}
void insert(struct ll *pt,int val)
{
    struct s *link=create_node(val);
    if(pt->head==NULL)
    {
        pt->head=link;
    }
    else
    {
        struct s *ptr=pt->head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=link;
    }
}
int main()
{
    int a[100],val,k,n=0;
    char c;
    struct ll *pt,ptr;
    pt=&ptr;
    pt->head=NULL;
    while(1)
    {
        scanf("%d%c",&val,&c);
        insert(pt,val);
        n++;
        if(c=='\n')
        {
            break;
        }
    }
    scanf("%d",&k);
    // for(i=0;*(a+i);i++)
    // {
    //     n++;
    // }
    if(k>n)
    {
        printf("-1\n");
    }
    else
    {
        int j=1,t=n-k+1;
        struct s *ptr=pt->head;
        while(j!=t)
        {
            ptr=ptr->next;
            j++;
        }
        printf("%d\n",ptr->key);
    }
    return 0;
}
