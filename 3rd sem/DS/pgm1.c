#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
#include<ctype.h>
/*Function Prototype*/ 
void create(int a[],int n);
void display(int a[],int n); 
void insert(int a[],int *n);
void delet(int a[],int *n);
void main()
{
 int ch,a[50],n;
do
{
  printf("\n 1.CREATE\t"); 
 printf("2.DISPLAY\t"); 
 printf("3.INSERT\t");
 printf("4.DELETE\t"); 
 printf("5.EXIT\n");
 printf("\n ENTER YOUR CHOICE:\t"); 
 scanf("%d",&ch);
switch(ch)
 {
  case 1:
	printf("\nEnter the size of the array elements: "); 
	scanf("%d",&n);
	create(a,n);
	break;
  case 2: 
display(a,n); 
	break; 
  case 3:
	insert(a,&n);
	break; 
  case 4: 
	delet(a,&n); 
	break; 
  case 5: 
	exit(0); 
	break;
  default:
	printf("\nInvalid choice:\n"); 
break;
 }
}
while(ch!=5);
}
//creating an array 
void create(int a[],int n)
{
  int i;
  printf("\nEnter the elements for the array:\n");
  for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
  printf("\n creation of array is succesfully");
 }
//displaying the arrayelements 
void display(int a[],int n)
{
  int i;
  if(n==0)
  {
	printf("\n Array is Empty ");
	return;
  }
  printf("\nThe array elements are:\n"); 
  for(i=0;i<n;i++)
   {
     printf("%d\t",a[i]);
   }
 }
//inserting an element into an array 
void insert(int a[],int *n)
{
  int pos,val,i;
  printf("\nEnter the position for the new element:\t");
  scanf("%d",&pos);
  if(pos<1||pos>(*n)+1)
   {
	 printf("\nInvalid Position");
 return (0);
   }
  printf("\nEnter the element to be inserted :\t"); 
  scanf("%d",&val);
  pos--;
  for(i=(*n)-1;i>=pos;i--)
   {
     a[i+1]=a[i];
   }
  a[pos]=val;
  (*n)=(*n)+1;
 }
//deleting an array element 
void delet(int a[],int *n)
{
  int val,pos,i;
  if((*n)==0)
  {
	printf("\n Array is Empty ");
	return;
  }
  printf("\nEnter the position of the element to be deleted:\t"); 
  scanf("%d",&pos);
  if(pos<1||pos>(*n))
   {
	 printf("\nInvalid Position");
 return (0);
   }
  pos--;
  val=a[pos];
  for(i=pos;i<(*n)-1;i++)
   {
     a[i]=a[i+1];
   }
  (*n)=(*n)-1;
  printf("\nThe deleted element is =%d",val);
}
