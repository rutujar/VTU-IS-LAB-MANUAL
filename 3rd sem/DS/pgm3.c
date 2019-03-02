#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define STACK_SIZE 4

int power(int x,int n)
{
if(n==0) return 1;
return (x*power(x,n-1));
}
void push(int *s,int *top,int item)
{
  int i,new_size;
  if(*top==STACK_SIZE-1)
  {
printf("\n  Stack is full!!! ");
	return;
  }
  s[++(*top)]=item;
}

int pop(int *s,int *top)
{
  if(*top==-1)
  {
    printf("\n  STACK UNDERFLOW!!!!!");
    return -1;
  }
  return s[(*top)--];
}

void display(int *s,int top)
{
  int i;
  if(top==-1)
  {
    printf("\n  STACK IS EMPTY!!!!");
    return;
  }
  printf("\n  The Stack content is :");
  for(i=top;i>=0;i--)
    printf("\n  %d",s[i]);
}

//Palindrome
void palindrome(int *s,int *top,int num)
{
int count=0,rem,i,rev=0,n=num,item;
while(n!=0)
{
rem=n%10;
push(s,top,rem);
n=n/10;
count++;
}
for(i=0;i<count;i++)
{
item=pop(s,top);
rev=item*power(10,i)+rev;
}
printf("Reversed Number=%d\n",rev);
if(num==rev)
printf("Palindrome");
else
printf("Not a Palindrome");
}

void main()
{
	int s[STACK_SIZE],top=-1,ch,item,del_item,num;
	while(1)
	{
		printf("\n\n Enter the choice : \n  1:PUSH  2:POP  3:DISPLAY  4:CHECK FOR PALINDROME  5:EXIT  :   ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n  Enter the element : ");
					scanf("%d",&item);
					push(s,&top,item);
			break;
			case 2: del_item=pop(s,&top);
					if(del_item!=-1)
					printf("\n  The deleted element is %d",del_item);
					break;
			case 3: display(s,top);
					break;
			case 4: printf("\n Enter a number to check for palindrome : ");
					scanf("%d",&num);
					palindrome(s,&top,num);
					break;
		    case 5: exit(0);
		}
	}
 }
