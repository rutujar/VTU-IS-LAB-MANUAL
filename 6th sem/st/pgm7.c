#include<stdio.h>
int main()
{
	int a,b,c;
	int istriangle=0;
	printf("enter 3 integers which are sides of triangle\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("a=%d\t,b=%d\t,c=%d",a,b,c);
	// to check is it a triangle or not
	if( a<b+c && b<a+c && c<a+b )
		istriangle=1;
	else
		istriangle =0;
	; 
	if (istriangle==1)
		if ((a==b) && (b==c))
			printf("equilateral triangle\n");
		else if ((a!=b) && (a!=c) && (b!=c))
			printf("scalene triangle\n");
		   else
			printf("isosceles triangle\n");
	else
		printf("Not a triangle\n");
	return 0;
}
