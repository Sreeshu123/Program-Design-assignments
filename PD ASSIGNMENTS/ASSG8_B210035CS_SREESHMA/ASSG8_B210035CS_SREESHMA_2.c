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
void INSERT(struct T *pt,long int k)
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
struct node * FIND_MIN(struct node *pt)
{
    while(pt->left!=NULL)
    {
        pt=pt->left;
    }
    return pt;
}
struct node * FIND_MAX(struct node *pt)
{
    while(pt->right!=NULL)
    {
        pt=pt->right;
    }
    return pt;
}
void SUCCESSOR(struct T *pt,long int k)
{
    struct node *x=SEARCH(pt->root,k);
    if(x!=NULL)
    {
        if(x->right!=NULL)
        {
            printf("%ld\n",FIND_MIN(x->right)->key);
            return;
        }
        struct node *y=x->p;
        while(y!=NULL && x==y->right)
        {
            x=y;
            y=y->p;
        }
        if(y!=NULL)
        {
            printf("%ld\n",y->key);
        }
        else
        {
            printf("NotFound\n");
        }
    }
    else
    {
        printf("NotFound\n");
    }
}
void PREDECESSOR(struct T *pt,long int k)
{
    struct node *x=SEARCH(pt->root,k);
    if(x!=NULL)
    {
        if(x->left!=NULL)
        {
            printf("%ld\n",FIND_MAX(x->left)->key);
            return;
        }
        struct node *y=x->p;
        while(y!=NULL && x==y->left)
        {
            x=y;
            y=y->p;
        }
        if(y!=NULL)
        {
            printf("%ld\n",y->key);
        }
        else
        {
            printf("NotFound\n");
        }
    }
    else
    {
        printf("NotFound\n");
    }
}
void TRANSPLANT(struct T *pt,struct node *u,struct node *v)
{
    if(u->p==NULL)
    {
        pt->root=v;
    }
    else if(u==u->p->left)
    {
        u->p->left=v;
    }
    else
    {
        u->p->right=v;
    }
    if(v!=NULL)
    {
        v->p=u->p;
    }
}
void DELETE(struct T *pt,long int k)
{
    struct node *x=SEARCH(pt->root,k),*y;
    if(x==NULL)
    {
        printf("NotFound\n");
        return;
    }
    else
    {
        printf("%ld\n",k);
        if(x->left==NULL)
        {
            TRANSPLANT(pt,x,x->right);
        }
        else if(x->right==NULL)
        {
            TRANSPLANT(pt,x,x->left);
        }
        else
        {
            y=FIND_MIN(x->right);
            if(y->p!=x)
            {
                TRANSPLANT(pt,y,y->right);
                y->right=x->right;
                y->right->p=y;
            }
            TRANSPLANT(pt,x,y);
            y->left=x->left;
            y->left->p=y;
        }
    }
}
int main()
{
    long int k;
    char ch;
    struct T *pt=(struct T*)malloc(sizeof(struct T));
    pt->root=NULL;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='a')
        {
            scanf("%ld",&k);
            INSERT(pt,k);
        }
        else if(ch=='d')
        {
            scanf("%ld",&k);
            DELETE(pt,k);
        }
        else if(ch=='c')
        {
            scanf("%ld",&k);
            SUCCESSOR(pt,k);
        }
        else if(ch=='r')
        {
            scanf("%ld",&k);
            PREDECESSOR(pt,k);
        }
        else if(ch=='p')
        {
            if(pt->root!=NULL)
            {
                PREORDER(pt->root);
                printf("\n");
            }
            else
            {
                printf("NIL\n");
            }
        }
        else if(ch=='e')
        {
            break;
        }
    }
}