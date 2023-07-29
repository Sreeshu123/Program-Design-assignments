#include <stdio.h>
int subarray(int A[],int m,int k,int x)
{
    int i,j,l,count=0,arr[m][k];
    l=0;
    for(i=0;i<m;i++)
    {
        int flag=0;
        for(j=0;j<k;j++)
        {
            arr[i][j]=A[l];
            if(A[l]==x)
            {
                flag=1;
            }
            l++;
        }
        if (flag==1)
        {
            count+=1;
        }
    }
    return count;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int m,count,x,A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&x);
    m=n/k;
    count=subarray(A,m,k,x);
    printf("%d",count);
    return 0;
}