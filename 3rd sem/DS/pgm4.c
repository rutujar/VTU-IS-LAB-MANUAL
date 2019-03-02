#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_SIZE 300

void push(char *s,int *top,char item)
{
  if(*top==STACK_SIZE-1)
  {
    printf("\n  Stack is full!!! ");
	return;
  }
  s[++(*top)]=item;
}

char pop(char *s,int *top)
{
  if(*top==-1)
  {
   printf("\n  STACK UNDERFLOW!!!!!");
    return 0;
  }
  return s[(*top)--];
}

int precedence(char sym)
{
    switch(sym)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^':
        case '$': return 3;
        default: return 0;
    }
}
    
void infixtopostfix(char *Q,char *P)
{
    int i,j=0,len,top=-1;
	char s[STACK_SIZE],sym;
   push(s,&top,'(');
	len=strlen(Q);
	Q[len]=')';
	Q[len+1]='\0';
	len=strlen(Q);
	for(i=0;i<len;i++)
	{
	    sym=Q[i];
	    
sym=Q[i];
	    
	    if(sym=='+' || sym=='-' || sym=='*' || sym=='/' || sym=='%' || sym=='^' || sym=='$')
	    {
	        while(precedence(s[top])>= precedence(sym))
	                P[j++]=pop(s,&top);
	        push(s,&top,sym);
	       
	    }
	    else if(sym==')')
	    {
	         while(s[top]!='(')
	        {
	            P[j++]=pop(s,&top);
	        }
	       pop(s,&top);
	    }
	    else if(sym=='(')
			push(s,&top,sym);
		else
	        P[j++]=sym;
	        
	}
	P[j]='\0';
}

void main()
{
	char Q[50],P[50];
	printf("\n Enter the infix expression : ");
	scanf("%s",Q);
	infixtopostfix(Q,P);
	printf("\n The postfix expression is  : %s",P);
    getch();
}
