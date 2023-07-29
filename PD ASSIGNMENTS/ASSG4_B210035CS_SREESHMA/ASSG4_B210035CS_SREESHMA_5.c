#include <stdio.h>
int len=0;
void INSERTIONSORT(int A[])
{
    int i,j,temp;
    for(j=1;j<len;j++)
    {
        temp=A[j];
        i=j-1;
        while(i>=0 && A[i]>temp)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=temp;
    }
}

void MIN_HEAPIFY(int A[],int i,int n)
{
    int l,r,smallest=i;
    l=2*i+1;
    r=2*i+2;
    if (l<n && A[l]<A[i])
    {
        smallest=l;
    }
    if (r<n && A[r]<A[smallest])
    {
        smallest=r;
    }
    if (smallest!=i)
    {
        int temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        MIN_HEAPIFY(A,smallest,n);
    }
}


void BUILD_MIN_HEAP(int A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        MIN_HEAPIFY(A,i,n);
    }
}


int GET_NEXT_PROCESS(int Q[])
{
    if(len==0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",Q[0]);
    }
}

int EXTRACT_NEXT_PROCESS(int Q[])
{
    if(len==0)
    {
        return -1;
    }
    else
    {
        int temp=Q[0];
        Q[0]=Q[len-1];
        Q[len-1]=temp;
        len--;
        for(int i=len/2-1;i>=0;i--)
        {
            MIN_HEAPIFY(Q,0,len);
        }
        return temp;
    }
}

int INSERT_PROCESS(int Q[],int k)
{
    Q[len]=k;
    len++;
    if(len!=1)
    {
        BUILD_MIN_HEAP(Q,len);
    }
}

void DISPLAY_QUEUE(int Q[])
{
    int A[1000];
    if(len==0)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            A[i]=Q[i];
        }
        INSERTIONSORT(A);
        for(int i=0;i<len;i++)
        {
            printf("%d ",A[i]);
        }
        printf("\n");
    }
}

void CHANGE_PRIORITY(int Q[],int k,int x)
{
    for(int i=0;i<len;i++)
    {
        if(Q[i]==k)
        {
            Q[i]=x;
            break;
        }
    }
    for(int i=len/2-1;i>=0;i--)
    {
        MIN_HEAPIFY(Q,0,len);
    }
}

int main()
{
    int Q[1000],A[1000];
    while(1)
    {
        int k,x;
        char c;
        scanf("%c",&c);
        if (c=='s')
        {
            break;
        }
        else if(c=='i')
        {
            scanf("%d",&k);
            INSERT_PROCESS(Q,k);
        }
        else if(c=='c')
        {
            scanf("%d",&k);
            scanf("%d",&x);
            CHANGE_PRIORITY(Q,k,x);
        }
        else if(c=='e')
        {
            printf("%d\n",EXTRACT_NEXT_PROCESS(Q));
        }
        else if(c=='m')
        {
            GET_NEXT_PROCESS(Q);
        }
        else if(c=='d')
        {
            DISPLAY_QUEUE(Q);
        }

    }
}