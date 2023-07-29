#include <stdio.h>
void MAX_HEAPIFY(float A[],int i,int n)
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
        float temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        MAX_HEAPIFY(A,largest,n);
    }
}

void BUILD_MAX_HEAP(float A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        MAX_HEAPIFY(A,i,n);
    }
}

void HEAPSORT(float A[],int n)
{
    BUILD_MAX_HEAP(A,n);
    for (int i=n-1;i>=0;i--)
    {
        float temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        MAX_HEAPIFY(A,0,i);
    }
}
int main()
{
    int n,m,k;
    scanf("%d %d",&n,&k);
    m=n/k;
    float A[m][k];
    float B[m];
    for(int i=0;i<m;i++)
    {
        for (int j=0;j<k;j++)
        {
            scanf("%f",&A[i][j]);
        }
        HEAPSORT(A[i],k);
        B[i]=A[i][k-1];
    }
    for(int i=0;i<m;i++)
    {
        printf("%.2f ",B[i]);
    }
}