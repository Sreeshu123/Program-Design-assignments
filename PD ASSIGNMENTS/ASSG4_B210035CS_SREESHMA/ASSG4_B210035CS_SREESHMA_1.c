#include <stdio.h>
struct S
{
    char Student_Name[30];
    int Mark;
};
int compare(char a[35],char b[35])
{
    int i=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        if(a[i]!=b[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void partition(int A[1000][2],int r,int pivot)
{
    int x=A[pivot][1];
    int i=-1,j,temp,index;
    for(j=0;j<r;j++)
    {
        if(A[j][1]<=x && j!=pivot)
        {
            i++;
            if(i==pivot)
            {
                pivot=j;
            }
            index=A[j][0];
            temp=A[j][1];
            A[j][0]=A[i][0];
            A[j][1]=A[i][1];
            A[i][0]=index;
            A[i][1]=temp;
            
            
        }
    }
    index=A[i+1][0];
    temp=A[i+1][1];
    A[i+1][0]=A[pivot][0];
    A[i+1][0]=A[pivot][0];
    A[pivot][0]=index;
    A[pivot][1]=temp;
    
}

int main()
{
    int i,n,mark,pivot;
    char name[35];
    int l[1000][2];
    scanf("%d",&n);
    struct S st[n];
    for(i=0;i<n;i++)
    {
        scanf("%s %d",st[i].Student_Name,&st[i].Mark);
        l[i][0]=i;
        l[i][1]=st[i].Mark;
    }
    scanf("%s",name);
    for(i=0;i<n;i++)
    {
        int flag=compare(name,st[i].Student_Name);
        if(flag==1)
        {
            pivot=i;
            break;
        }
    }
    partition(l,n,pivot);
    for(int i=0;i<n;i++)
    {
        int index=l[i][0];
        printf("%s ",st[index].Student_Name);
    }
}