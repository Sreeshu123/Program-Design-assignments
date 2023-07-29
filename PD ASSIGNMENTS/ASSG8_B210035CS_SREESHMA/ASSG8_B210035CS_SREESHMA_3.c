#include <stdio.h>
#include <stdlib.h>
struct node
{
    long int key;
    struct node *p;
    struct node *left;
    struct node *right;
};
struct T
{
    struct node *root;
};
struct node * CREATE_NODE(long int k)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=k;
    temp->p=NULL;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node * INSERT(struct T *pt,long int k)
{
    struct node *temp=CREATE_NODE(k);
    struct node *x=pt->root;
    struct node *y=NULL;
    while(x!=NULL)
    {
        y=x;
        if(k<x->key)
        {
            x=x->left;
        }
        else
        {
            x=x->right;
        }
    }
    temp->p=y;
    if(y==NULL)
    {
        pt->root=temp;
    }
    else if(temp->key<y->key)
    {
        y->left=temp;
    }
    else
    {
        y->right=temp;
    }
}
void PRINT(struct node *pt)
{
    printf("( ");
    if(pt!=NULL)
    {
        printf("%ld ",pt->key);
        PRINT(pt->left);
        PRINT(pt->right);
    }
    printf(") ");
}
int main()
{
    char ch;
    long int k;
    struct T *pt=(struct T*)malloc(sizeof(struct T));
    pt->root=NULL;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%ld",&k);
            INSERT(pt,k);
        }
        else if(ch=='p')
        {
            PRINT(pt->root);
            printf("\n");
        }
        else if(ch=='e')
        {
            break;
        }
    }
    return 0;
}