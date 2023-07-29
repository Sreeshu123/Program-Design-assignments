#include <stdio.h>
int greater(char a[100],char b[100])
{
    int i=0,flag=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        if (a[i]>b[i])
        {
            flag=1;
            break;
        }
        else if(b[i]>a[i])
        {
            flag=2;
            break;
        }
        i++;
    }
    if(flag==0 && a[i]!='\0')
    {
        flag=1;
    }
    else if(flag==0 && b[i]!='\0')
    {
        flag=2;
    }
    return flag;
}
void Merge(char B[100][100],int index[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    char L[100][100],R[100][100];
    int l1[100],r1[100];
    int j;
    for(int i=0;i<n1;i++)
    {
        l1[i]=index[p+i];
        for(j=0;B[p+i][j]!='\0';j++)
        {
            L[i][j]=B[p+i][j];
        }
        while(j<100)
        {
            L[i][j]='\0';
            j++;
        }
    }
    for(int i=0;i<n2;i++)
    {
        r1[i]=index[q+i+1];
        for(j=0;B[q+i+1][j]!='\0';j++)
        {
            R[i][j]=B[q+i+1][j];
        }
        while(j<100)
        {
            R[i][j]='\0';
            j++;
        }
    }
    int i=0,k=p,m;
    j=0;
    while(i<n1 && j<n2)
    {
        int flag=greater(L[i],R[j]);
        if(flag==0 || flag==1)
        {
            index[k]=r1[j];
            for(m=0;R[j][m]!='\0';m++)
            {
                B[k][m]=R[j][m];
            }
            while(m<100)
            {
                B[k][m]='\0';
                m++;
            }
            j++;
        }
        else
        {
            index[k]=l1[i];
            for(m=0;L[i][m]!='\0';m++)
            {
                B[k][m]=L[i][m];
            }
            while(m<100)
            {
                B[k][m]='\0';
                m++;
            }
            i++;
        }
        k++;
    }
    while(i<n1)
    {
        index[k]=l1[i];
        for(m=0;L[i][m]!='\0';m++)
        {
           B[k][m]=L[i][m]; 
        }
        while(m<100)
            {
                B[k][m]='\0';
                m++;
            }
        i++;
        k++;
    }
    while(j<n2)
    {
        index[k]=r1[j];
        for(m=0;R[j][m]!='\0';m++)
        {
            B[k][m]=R[j][m];
        }
        while(m<100)
            {
                B[k][m]='\0';
                m++;
            }
        j++;
        k++;
    }
}
void Mergesort(char B[100][100],int index[],int p,int r)
{
    if(r>p)
    {
        int q=(r+p)/2;
        Mergesort(B,index,p,q);
        Mergesort(B,index,q+1,r);
        Merge(B,index,p,q,r);
    }
}
int main()
{
    int n;
    char A[100][100],B[100][100];
    scanf("%d",&n);
    getchar();
    int index[n];
    int p=0,r=n-1;
    for(int i=0;i<n;i++)
    {
        index[i]=i;
        scanf("%[^\n]s",A[i]);
        getchar();
        int k=0;
        while(A[i][k]!='\0')
        {
            char t=A[i][k];
            if(t>=65 && t<=90)
            {
                t+=32;
            }
            B[i][k]=t;
            k++;
        }
    }
    Mergesort(B,index,p,r);
    for(int i=0;i<n;i++)
    {
        int j=index[i];
        fputs(A[j],stdout);
        printf("\n");
    }
    return 0;
}