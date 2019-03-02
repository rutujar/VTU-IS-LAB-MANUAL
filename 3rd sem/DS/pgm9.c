#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
	int coef;		/* structure of each node in the  circular list */
	int powx;
	int powy;
	int powz;
	int flag;
	struct poly *link;
};
typedef struct poly *term;
term getnode()		/* Dynamic memory allocation for each term of the polynomial inserted */
{
	term x;
	x=(term)malloc(sizeof(struct poly));	
	if(x==NULL)
	{
		printf("out of memory\n");
		exit(0);
	}
	return x;
}
void display (term head)
{
	term temp;
	if( head->link==head) 	                    /* List is empty*/
	{
		printf("polynomial does not exist\n");
		return;
	}
for(temp=head->link;temp!=head;temp=temp->link)
{
	  if(temp->coef<0)
      printf("%2dx^%2dy^%2dz^%2d",temp->coef,temp->powx,temp->powy,temp->powz);
  else
     printf("+%2dx^%2dy^%2dz^%2d",temp->coef,temp->powx,temp->powy,temp->powz);
}
printf("\n");
}
/* inserting every new term of the polynomial at the rear end and linking it back to the head  node to form a circular representation */
term insertrear(int coef, int x, int y,int z,term head)
{
	term temp,cur;
	temp=getnode();
	temp->coef=coef;
	temp->powx=x;
	temp->powy=y;					
	temp->powz=z;
	temp->flag=0;
	cur=head->link;
	while(cur->link!=head)
		cur=cur->link;
		cur->link=temp;
		temp->link=head;
return head;
}
/* reading the structure of every term to be inserted */
term readpoly(term head)
{
	int i;
	int  powx,powy,powz,coef;
	head=getnode();
	head->link=head;
	printf("enter the coefficient as -999 to end the polynomial\n");
	for(i=1;;i++)
	{
		printf("Enter %d term\n",i);
		printf("coeff=");
		scanf("%d",&coef);
		if(coef==-999)	
			break;
		printf(" pow x="); 
		scanf("%d",&powx);
		printf("pow y="); 
		scanf("%d",&powy);
		printf("pow z="); 
		scanf("%d",&powz);
		head=insertrear(coef,powx,powy,powz,head);
	}
	return head;
}
int power(int x,int n)
{
if (n==0)
return 1;
return x*power(x,n-1);
}
void evaluate(term poly)
{
	term temp;
	int x,y,z,xval,yval,zval,res=0;
	temp=poly->link;
	printf("\nEnter the values x, y and z:\n");
	scanf("%d%d%d",&x,&y,&z);
	while (temp!=poly)
	{
		xval=power(x,temp->powx);
		yval=power(y,temp->powy);
		zval=power(z,temp->powz);
		res+=temp->coef*xval*yval*zval;
		temp=temp->link;
	}
	printf("\nResult=%d\n",res);
}
term addpoly(term head1,term head2,term head3) 
{
	term poly1,poly2;
	int x1,x2,y1,y2,z1,z2,coef1,coef2,coef;
	poly1=head1->link;
	while(poly1!=head1)
	{
		x1=poly1->powx;
		y1=poly1->powy;
		z1=poly1->powz;
		coef1=poly1->coef;
		poly2=head2->link;
	    while (poly2!=head2)
 		{
			x2=poly2->powx;
			y2=poly2->powy;
			z2=poly2->powz;
			coef2=poly2->coef;
			if(x1==x2 && y1==y2 && z1==z2) 
				break;
			poly2= poly2->link;
		}
		if(poly2!=head2)
		{
			coef=coef1+coef2;
			poly2->flag=1;
			if(coef!=0) 
			head3=insertrear(coef,x1,y1,z1,head3);
		}
		else
				head3=insertrear(coef1,x1,y1,z1,head3);
		poly1=poly1->link;
     }
     poly2=head2->link;
     while(poly2!=head2)
    {
	     if(poly2->flag==0)
	     {
               head3=insertrear(poly2->coef,poly2->powx,poly2->powy,poly2->powz,head3);
	     }
	     poly2=poly2->link;
     }
     return head3;
}
void main()
{
	int ch;
	term poly,head1,head2,head3;
	poly=getnode();
	head1=getnode();
	head2=getnode();
	head3=getnode();
	head3->link=head3;
	do
	{
		printf("\n\nPRESS \n 1.Represent & Evaluate a Polynomial\n 2.Add 2 Polynomial\n 3.Exit\n Your choice :");
		scanf("%d",&ch);
	    switch(ch)
		{
			case 1: printf("Enter polynomial:\n");
					poly=readpoly(poly);
					display(poly);
					evaluate(poly);
					break;
			case 2:	printf("Enter the first polynomial\n");
					head1=readpoly(head1);
					printf("Enter the second polynomial\n");
					head2=readpoly(head2);
					head3=addpoly(head1,head2,head3);
					printf("The first polynomial is\n");
					display(head1);
					printf("The second polynomial is\n");
					display(head2);
					printf(" The sum of the polynomial is\n");
					display(head3);
					break;
			case 3: printf("\n Terminating");
					break;				
			default: printf("Wrong Choice\n");
		}
	}
	while(ch!=3);
	getch();
}
