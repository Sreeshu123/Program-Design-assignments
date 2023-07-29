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
struct node * SEARCH(struct node *pt,long int k)
{
    //struct node *ptr=pt;
    if(pt==NULL)
    {
        return NULL;
    }
    else if(pt->key==k)
    {
        return pt;
    }
    else if(pt->key>k)
    {
        SEARCH(pt->left,k);
    }
    else if(pt->key<k)
    {
        SEARCH(pt->right,k);
    }
}
long int FIND_MIN(struct T *pt)
{
    if(pt->root==NULL)
    {
        return 0;
    }
    else 
    {
        struct node *ptr=pt->root;
        while(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        return ptr->key;
    }
}
long int FIND_MAX(struct T *pt)
{
    if(pt->root==NULL)
    {
        return 0;
    }
    else 
    {
        struct node *ptr=pt->root;
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        return ptr->key;
    }
}
void INORDER(struct node *pt)
{
    if(pt!=NULL)
    {
        INORDER(pt->left);
        printf("%ld ",pt->key);
        INORDER(pt->right);
    }
    else
    {
        return;
    }
}
void POSTORDER(struct node *pt)
{
    if(pt!=NULL)
    {
        POSTORDER(pt->left);
        POSTORDER(pt->right);
        printf("%ld ",pt->key);
    }
    else
    {
        return;
    }
}
void PREORDER(struct node *pt)
{
    if(pt!=NULL)
    {
        printf("%ld ",pt->key);
        PREORDER(pt->left);
        PREORDER(pt->right);
    }
    else
    {
        return;
    }
}
int main()
{
    struct T *pt=(struct T*)malloc(sizeof(struct T));
    pt->root=NULL;
    char ch;
    long int k;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='a')
        {
            scanf("%ld",&k);
            INSERT(pt,k);
        }
        else if(ch=='s')
        {
            scanf("%ld",&k);
            if(SEARCH(pt->root,k)!=NULL)
            {
                printf("Found\n");
            }
            else
            {
                printf("NotFound\n");
            }
        }
        else if(ch=='x')
        {
            k=FIND_MAX(pt);
            if(k==0)
            {
                printf("NIL\n");
            }
            else
            {
                printf("%ld\n",k);
            }
        }
        else if(ch=='n')
        {
            k=FIND_MIN(pt);
            if(k==0)
            {
                printf("NIL\n");
            }
            else
            {
                printf("%ld\n",k);
            }
        }
        else if(ch=='i')
        {
            if(pt->root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                INORDER(pt->root);
                printf("\n");
            }
        }
        else if(ch=='p')
        {
            if(pt->root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                PREORDER(pt->root);
                printf("\n");
            }
        }
        else if(ch=='t')
        {
            if(pt->root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                POSTORDER(pt->root);
                printf("\n");
            }
        }
        else if(ch=='e')
        {
            break;
        }
    }
}