#include <stdio.h>
int count=0;
void MAX_HEAPIFY(int A[],int i,int n)
{
    int l,r,largest=i;
    l=2*i+1;
    r=2*i+2;
    if (l<n && A[l]>A[i])
    {
        largest=l;
        count++;
    }
    else if(l<n)
    {
        count++;
    }
    if (r<n && A[r]>A[largest])
    {
        count++;
        largest=r;
    }
    else if(r<n)
    {
        count++;
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


void HEAPSORT(int A[],int n)
{
    BUILD_MAX_HEAP(A,n);
    for (int i=n-1;i>=0;i--)
    {
        int temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        MAX_HEAPIFY(A,0,i);
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
    HEAPSORT(A,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n%d",count);
}