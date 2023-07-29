#include <stdio.h>
int countfunc(char str[],char arr[],int count[])
{
    int i=0,j=0;
    while(str[i]!='\0')
    {
        int flag=0;
        for(int k=0;arr[k]!='\0';k++)
        {
            if (arr[k]==str[i])
            {
                flag=1;
                count[k]+=1;
                break;
            }
        }
        if (flag==0)
        {
            arr[j]=str[i];
            count[j]=1;
            j++;
        }
        i++;

    }
    return j;
}

int main()
{
    char str[1000];
    fgets(str,sizeof(str),stdin);
    char arr[1000];
    int count[1000];
    long long int p=1;
    int j=countfunc(str,arr,count);
    for(int i=0;i<j;i++)
    {
        p*=count[i];
    }
    printf("%lld",p);
    return 0;
}
