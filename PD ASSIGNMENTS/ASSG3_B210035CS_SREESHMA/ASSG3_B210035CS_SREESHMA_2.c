#include <stdio.h>
void adding(int a[], int b[], int c[], int m, int n)
{
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else if(a[i]>b[j])
        {
            c[k]=b[j];
            j++;
            k++;
        }
        else
        {
            c[k]=a[i];
            c[k+1]=b[j];
            i++;
            j++;
            k+=2;
        }
    }
    if(i==m)
    {
        while(j<n)
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    else
    {
       while(i<m)
        {
            c[k]=a[i];
            i++;
            k++;
        } 
    }
}

int main()
{
    int m,n,t;
    scanf("%d %d",&m,&n);
    int a[10000],b[10000],c[10000];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    scanf("%d",&t);
    adding(a,b,c,m,n);
    int pos=-1;
    for(int i=0;i<m+n;i++)
    {
        if(c[i]==t)
        {
            pos=i;
            break;
        }
    }
    printf("%d",pos);
    return 0;
}