#include<stdio.h>
#include<conio.h>
#define maxstack 10
struct details
{
	int number;
	char beg,aux,end;
};
struct stack
{
	int top;
	struct details item[maxstack];
};
void push(struct stack *s,struct details *current)
{
	if(s->top==maxstack-1)
	{
		printf("overflow");
		exit(0);
	}
	else
		s->item[++(s->top)]=*current;
	return;
}
void popandtest(struct stack *s,struct details *current,int *flag)
{
	if(s->top==-1)
	{
		*flag=1;
		return;
	}
	*flag=0;
	*current=s->item[(s->top)--];
}
void tower(int n,char begpeg,char auxpeg,char endpeg)
{
	struct stack s;
	struct details current;
	char temp;
	int flag;
	current.number=n;
	current.beg=begpeg;
	current.end=endpeg;
	current.aux=auxpeg;
	s.top=-1;
	while(1)
	{
		while(current.number!=1)
		{
			push(&s,&current);
			--current.number;
			temp=current.end;
			current.end=current.aux;
			current.aux=temp;
		}
		printf("\n move disc 1 from %c to %c",current.beg,current.end);
		popandtest(&s,&current,&flag);
		if(flag==1)
			return;
	printf("\n move disc %d from %c to %c",current.number,current.beg,current.end);
	--current.number;
			temp=current.beg;
			current.beg=current.aux;
			current.aux=temp;
	}
}
void main()
{
	int n;
	printf("\n enter the number of disc");
	scanf("%d",&n);
	tower(n,'B','A','E');
	getch();
}
