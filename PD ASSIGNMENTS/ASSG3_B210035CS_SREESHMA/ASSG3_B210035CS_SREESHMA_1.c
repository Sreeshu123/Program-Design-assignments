#include <stdio.h>
void insertionsort(float b[], int n)
{
    for(int j=1;j<n;j++)
    {
        float temp=b[j];
        int i=j-1;
        while(b[i]>temp && i>=0)
        {
            b[i+1]=b[i];
            i--;
        }
        b[i+1]=temp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    float a[1000],b[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
        b[i]=a[i];
    }
    insertionsort(b,n);
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (a[i]==b[j])
            {
                printf("%d ",j);
                break;
            }
        }
    }
    return 0;
}