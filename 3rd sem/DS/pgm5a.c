#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int power(int x,int n)
{
if(n==0) return 1;
return (x*power(x,n-1));
}

/*Func To Push*/
 void push(int *s,int *top,int opnd)
 {
   s[++(*top)]=opnd;
 }

/*Func To Pop*/
int pop(int *s,int *top)
 {
   return(s[(*top)--]);
 }

 int evaluate(int A,int B,char sym)
 {
	 switch(sym)
	 {
	 case '+': return (B+A);
	 case '-': return (B-A);
	 case '*': return (B*A);
	 case '/': if(A!=0) 
				return (B/A);
			   else
			   {
				   printf("\n Divide by Zero Error ");
				   getch();
				   exit(0);
			   }

     case '%': if(A!=0) 
				return (B%A);
			   else
			   {
				   printf("\n Divide by Zero Error ");
				   getch();
				   exit(0);
			   }
	case '^': 
	case '$': return power(B,A);
	default: printf("\n Invalid operator");
	 }
 }

void main()
{
  int top=-1,s[100],A,B,i=0,item,val;
  char P[50],sym;
  printf("enter valid suffix exp\n");
  scanf("%s",P);
  while(P[i]!='\0')
  {
	  sym=P[i++];
       if(isdigit(sym))
		{
			/* Check to see if the symbol is digit or not */
			item=sym-'0';  // ASCII conversion
            push(s,&top,item);
	   }
       else
	   {
		   A=pop(s,&top);
		   B=pop(s,&top);
		   val=evaluate(A,B,sym);
		   push(s,&top,val);
	   }
  }
  printf("\n The result of the postfix is : %d",s[top]);
  getch(); 			 
}      /*End Of Main*/
