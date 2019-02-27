#include<stdio.h>
void quicksort(int x[10],int first,int last)
{
   	int temp,pivot,i,j;
	if(first<last)
	{
            	 pivot=first;
          	 	 i=first;
            	 j=last;
   	 	 while(i<j)
		    {
          			while(x[i]<=x[pivot] && i<last)
      				i++;
	       	          while(x[j]>x[pivot])
				j--;
	              	  if(i<j)
			{
	                  		  temp=x[i];
	                   		  x[i]=x[j];
	                   		  x[j]=temp;
			}
          	 	   }	
	            temp=x[pivot];
	      	x[pivot]=x[j];
	           x[j]=temp;
  	          quicksort(x,first,j-1);
   	          quicksort(x,j+1,last);
    	}
}   
// main program
int main()
{
  	int a[20],i,key,n;
  	printf("enter the size of the array");
	scanf("%d",&n);
	if(n>0)
	{
		printf("enter the elements of the array");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	
        		quicksort(a,0,n-1);
		printf("the elements in the sorted array is:\n");
        for(i=0;i<n;i++)
       		 printf("%d\t",a[i]);
	}
	else
	{
		printf(“size of array is invalid\n”);
}     
