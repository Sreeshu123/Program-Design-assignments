#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int FIND_INDEX(char s[],int b,int e)
{
    char st[100];
    int top=-1;
    if(b>e)
    {
        return -1;
    }
    for(int i=b;i<=e;i++)
    {
        if(s[i]=='(')
        {
            s[++top]=s[i];
        }
        else if(s[i]==')')
        {
            if(s[top]=='(')

            {
                top--;
            }
            if(top==-1)
            {
                return i;
            }
        }
    }
    return -1;
}
struct node *  BUILD_TREE(char s[],int b,int e)
{
   if(b>e || e==b+2)
    {
        //printf("yes\n");
        return NULL;
    }
    //char s1[6];
    //int i=0;
    // while(i<6)
    // {
    //     s1[i]='\0';
    //     i++;
    // }
    long int num=0;
    int t=b+2,i,mul=1;
    if(s[t]=='-')
    {
        mul=-1;
        t=b+3;
    }
    for(i=t;s[i]!=' ';i++)
    {
        num=10*num+((s[i]-48));
    }
    t=i;
    num=num*mul;
    //printf("%ld ",num);
    struct node *temp=CREATE_NODE(num);
    int index=-1;
    if(t+1<e && s[t+1]=='(')
    {
        index=FIND_INDEX(s,t+1,e);
        //printf("index=%d e=%d ",index,e);
    }
    if(index!=-1)
    {
        temp->left=BUILD_TREE(s,t+1,index);
        temp->right=BUILD_TREE(s,index+2,e-2);
    }
    return temp;
}
void PRINT(struct node *pt)
{
    if(pt!=NULL)
    {
        PRINT(pt->left);
        PRINT(pt->right);
        printf("%ld ",pt->key);
    }
    else
    {
        return;
    }
}
int main()
{
    char s[1000];
    for(int i=0;i<1000;i++)
    {
        s[i]='\0';
    }
    fgets(s,sizeof(s),stdin);
    //printf("%s\n",s);
    struct T ptt,*pt=(struct T*)malloc(sizeof(struct T));
    pt=&ptt;
    //printf("%c\n",s[strlen(s)-2]);
    pt->root=BUILD_TREE(s,0,strlen(s)-2);
    //printf("built\n");
    if(pt->root!=NULL)
    {
        PRINT(pt->root);
    }
    return 0;
}