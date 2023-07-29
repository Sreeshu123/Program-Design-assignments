#include <stdio.h>
void insertionsort(int A[],int B[],int n)
{
    for(int j=1;j<n;j++)
    {
        int temp=A[j];
        int index=B[j];
        int i=j-1;
        while(A[i]>temp && i>=0)
        {
            A[i+1]=A[i];
            B[i+1]=B[i];
            i--;
        }
        A[i+1]=temp;
        B[i+1]=index;
    }
}
void read_and_store(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    while(i<1000)
    {
        A[i]='\0';
        i++;
    }
}
void print(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int digit_sum(int k)
{
    int sum=0;
    while(k!=0)
    {
        sum+=k%10;
        k/=10;
    }
    return sum;
}
int digit_sort(int A[],int n)
{
    int B[100000],C[100000];
    for(int i=0;i<n;i++)
    {
        C[i]=digit_sum(A[i]);
        B[i]=i;
    }
    insertionsort(C,B,n);
    for(int i=0;i<n;i++)
    {
        int j=B[i];
        C[i]=A[j];
    }
    for(int j=0;j<n;j++)
    {
        A[j]=C[j];
    }
}
int main()
{
    int check=1;
    char input[5];
    while(check!=0)
    {
        char c;
        int n,d,A[100000];
        fgets(input,sizeof(input),stdin);
        c=input[0];
        if (input[2]!='\0')
        {
            sscanf(input,"%c %d",&c,&d);
        }
        else
        {
           sscanf(input,"%c",&c); 
        }
        if(c=='t')
        {
            printf("-1");
            check=0;
        }
        else if(c=='r')
        {
            n=d;
            read_and_store(A,d);
        }
        else if(c=='p')
        {
            print(A,n);
        }
        else if(c=='d')
        {
            int sum=digit_sum(A[d]);
            printf("%d\n",sum);
        }
        else if(c=='s')
        {
            digit_sort(A,n);
        }
    }
    return 0;
}