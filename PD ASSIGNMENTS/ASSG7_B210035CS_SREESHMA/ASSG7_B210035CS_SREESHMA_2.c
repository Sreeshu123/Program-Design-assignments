#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct T
{
    struct node *root;
};
struct node * POP(struct T *pt)
{
    struct node *temp=pt->root;
    pt->root=pt->root->next;
    return temp;
}
void PUSH(struct T *pt,struct node *link)
{
    link->next=pt->root;
    pt->root=link;
}
struct node * CREATE_TREE_NODE(char k)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data=k;
    link->left=NULL;
    link->right=NULL;
    link->next=NULL;
    return link;
}
int ISOP(char k)
{
    if(k=='+'||k=='-'||k=='*'||k=='/')
    {
        return 1;
    }
    return 0;
}
struct node * CONSTRUCT_TREE(struct T *pt,char e[])
{
    int i=0;
    struct node *temp;
    while(e[i]!='#')
    {
        temp=CREATE_TREE_NODE(e[i]);
        if(ISOP(e[i]))
        {
            temp->right=POP(pt);
            temp->left=POP(pt);
        }
        PUSH(pt,temp);
        i++;
    }
    return temp;
}
void INORDER(struct node *pt)
{
    if(pt!=NULL)
    {
        INORDER(pt->left);
        printf("%c",pt->data);
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
        printf("%c",pt->data);
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
        printf("%c",pt->data);
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
    struct T *pt,ptt;
    pt=&ptt;
    pt->root=NULL;
    char e[10000],s[10000];
    int i,j;
    for(i=0;i<10000;i++)
    {
        e[i]='\0';
        s[i]='\0';
    }
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='e')
        {
            scanf(" %s",s);
            printf("%s\n",s);
            for(i=0;s[i]!='\0';i++)
            {
                e[i]=s[i];
            }
            e[i]='#';
            for(j=i+1;j<10000;j++)
            {
                e[j]='\0';
            }
            printf("%s\n",e);
            CONSTRUCT_TREE(pt,e);
            //printf("created\n");
        }
        else if(ch=='i')
        {
            INORDER(pt->root);
            printf("\n");
        }
        else if(ch=='p')
        {
            PREORDER(pt->root);
            printf("\n");
        }
        else if(ch=='s')
        {
            POSTORDER(pt->root);
            printf("\n");
        }
        else if(ch=='t')
        {
            break;
        }  
    }
    return 0;  
}