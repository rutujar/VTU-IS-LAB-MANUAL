#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define qmax_size 5
void insert(char *q,int *r,int *f,int item)
{
	int pr=*r;
	*r=(*r+1)%qmax_size;
	if(*r==*f)
	{
		printf("queue is full ");
		*r=pr;
	}
	else
		q[(*r)]=item;
}
int delete(char *q,int *r,int *f)
{
	if(*f==*r)
	{
		printf("\n queue is empty ");
		return -1;
	}
	*f=(*f+1)%qmax_size;
	return q[(*f)];
}
void display(char *q,int r,int f)
{
	int i;
	if(f==r)
	{
		printf("\n queue is empty ");
		return;
	}
	printf("\n contents of the queue are ");
	for(i=(f+1)%qmax_size;i!=(r+1)%qmax_size;i=(i+1)%qmax_size)
	{
		printf("%c",q[i]);
	}
}
void main()
{
	int ch,r=0,f=0;
	char q[qmax_size],item;
	while(1)
	{
		printf("\n 1.insert 2.delete 3.display 4.exit ");
		printf("\n enter the choices ");
		scanf("%d",&ch);
		fflush(stdin);
		switch(ch)
		{
		case 1:printf("\n enter the element to be inserted ");
			scanf("%c",&item);
			insert(q,&r,&f,item);
			break;
		case 2:item=delete(q,&r,&f);
			if(item!=0)
				printf("\n deleted item %c ",item);
			break;
		case 3:display(q,r,f);
			break;
		case 4:exit(0);
		}
	}
	getch();
}
