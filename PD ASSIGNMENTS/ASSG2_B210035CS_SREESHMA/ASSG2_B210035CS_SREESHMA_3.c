#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],largest,check=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if (i==0)
        {
            largest=A[i];
        }
        else
        {
            if (A[i]>largest)
            {
                largest=A[i];
            }
        }
    }
    int sl;
    int i=0;
    while(i<n)
    {
        if(A[i]!=largest)
        {
            sl=A[i];
            check=1;
            break;
        }
        i++;
    }
    if (check==1)
    {
        for(int j=0;j<n;j++)
        {
            if(A[j]>sl && A[j]!=largest)
            {
                sl=A[j];
            }
        }
        for(int i=0;i<n;i++)
        {
            if (A[i]==sl)
            {
                for(int j=i;j<n-1;j++)
                {
                    A[j]=A[j+1];
                }
                n--;
                i--;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        printf("%d ",A[j]);
    }
    return 0; 
}