#include <stdio.h>
#include <stdlib.h>
struct s
{
	int n;
	int *a;
	int p;
};
int isempty(struct s *pt)
{
	if(pt->p==-1)
	{
		return 1;
	}
	return 0;
}
int isfull(struct s *pt)
{
	if(pt->p==pt->n-1)
	{
		pt->n=2*pt->n;
		return 1;
	}
	return 0;
}
void push(struct s *pt,int val)
{
	if(isfull(pt))
	{
		printf("1\n");
		int *b=(int*)malloc(pt->n*sizeof(int));
		for(int i=0;i<=pt->p;i++)
		{
			b[i]=pt->a[i];
		}
		pt->a=b;
		pt->a[++pt->p]=val;
	}
	else
	{
		pt->a[++pt->p]=val;
	}
}
void delete(struct s *pt)
{
	if(isempty(pt))
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",pt->a[pt->p--]);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	struct s ptr,*pt;
	pt=&ptr;
	pt->a=a;
	pt->p=-1;
	pt->n=n;
	char ch;
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='i')
		{
			int val;
			scanf("%d",&val);
			push(pt,val);
		}
		else if (ch=='d')
		{
			delete(pt);
		}
		else if(ch=='t')
		{
			break;
		}
	}
	return 0;
}