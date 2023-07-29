#include <stdio.h>
int Binarysearch(int A[],int n,int t)
{
    int mid,a=0,b=n-1,flag=0;
    while(b>=a)
    {
        mid=(a+b)/2;
        if (A[mid]==t)
        {
            flag=1;
            return mid;
        }
        else if(A[mid]>t)
        {
            b=mid-1;
        }
        else
        {
            a=mid+1;
        }
    }
    if (flag==0)
    {
        return -1;
    }
}

int main()
{
    int n,t,d,check=0;
    scanf("%d %d",&n,&t);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int c=Binarysearch(A,n,t);
    printf("%d\n",c);
    if (c!=-1)
    {
        for(int j=c;j<n;j++)
        {
            if(A[j]!=t)
            {
                printf("%d ",j);
                check=1;
            }
        }
    }
    if (check==0)
    {
        printf("%d",-1);
    }
    return 0;
}