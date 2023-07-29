#include <stdio.h>
 
void MAX_HEAPIFY(int A[],int i,int n)
{
    int l,r,largest=i;
    l=2*i+1;
    r=2*i+2;
    if (l<n && A[l]>A[i])
    {
        largest=l;
    }
    if (r<n && A[r]>A[largest])
    {
        largest=r;
    }
    if (largest!=i)
    {
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        MAX_HEAPIFY(A,largest,n);
    }
}
void BUILD_MAX_HEAP(int A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        MAX_HEAPIFY(A,i,n);
    }
}
int INSERT_PROCESS(int Q[],int k,int m)
{
    Q[m]=k;
    m++;
    if(m!=1)
    {
        BUILD_MAX_HEAP(Q,m);
    }
}
int EXTRACT(int Q[],int n)
{
    if(n==0)
    {
        return -1;
    }
    else
    {
        int temp=Q[0];
        Q[0]=Q[n-1];
        Q[n-1]=temp;
        n--;
        for(int i=n/2-1;i>=0;i--)
        {
            MAX_HEAPIFY(Q,0,n);
        }
        return temp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int Q[1000],P[1000],u[1000][2];
    int m=0,k;
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        int flag=0;
        if(i!=0)
        {
            for(int j=0;j<m;j++)
            {
                if (u[j][0]==A[i])
                {
                    u[j][1]+=1;
                    Q[j]+=1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0 || i==0)
        {
            u[m][0]=A[i];
            Q[m]=A[i];
            Q[m]=1;
            u[m][1]=1;
            m++;
        }
    }
    for(int i=0;i<m;i++)
    {
        INSERT_PROCESS(P,Q[i],i);
    }
    for(int i=0;i<k;i++)
    {
        int max=EXTRACT(P,m);
        for(int j=0;j<m;j++)
        {
            if(u[j][1]==max)
            {
                printf("%d ",u[j][0]);
                for(int p=j+1;p<m;p++)
                {
                    u[p-1][0]=u[p][0];
                    u[p-1][1]=u[p][1];
                }
                m--;
                break;
            }
        }
    }
    
}