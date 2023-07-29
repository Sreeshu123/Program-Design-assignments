#include <stdio.h>
#include <stdlib.h>
struct q
{
	int n;
	int a[1000];
	int head;
	int tail;
};

int isempty(struct q *pt)
{	
	if(pt->head==pt->tail)
	{
		return 1;
	}
	return -1;
}
int isfull(struct q *pt)
{
	if(pt->head==pt->tail+1||pt->head==0 && pt->tail==pt->n)
	{
		return 1;
	}
	return -1;
}
void dequeue(struct q *pt)
{
	if(isempty(pt)==1)
	{
		printf("1\n");
	}
	else
	{
		printf("%d\n",pt->a[pt->head]);
		if(pt->head==pt->n)
		{
			pt->head=0;
		}
		else
		{
			pt->head++;
		}
	}
}
void enqueue(struct q *pt,int val)
{
	if(isfull(pt)==1)
	{
		printf("1\n");
	}
	else
	{
		pt->a[pt->tail]=val;
		if(pt->tail==pt->n)
		{
			pt->tail=0;
		}
		else
		{
			pt->tail++;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
    char ch;
    struct q ptr,*pt;
    pt=&ptr;
    pt->n=n;
    pt->head=0;
    pt->tail=0;
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='i')
		{
			int val;
			scanf("%d",&val);
			enqueue(pt,val);
		}
		else if (ch=='d')
		{
			dequeue(pt);
		}
        else if(ch=='e')
        {
            printf("%d\n",isempty(pt));
        }
        else if(ch=='f')
        {
            printf("%d\n",isfull(pt));
        }
		else if(ch=='t')
		{
			break;
		}
	}
    return 0;
}