#include<stdio.h>
int main()
{
	int locks, stocks, barrels, tlocks, tstocks, tbarrels;
	float lprice, sprice, bprice, sales, comm;
             int c1,c2,c3,temp;
	lprice=45.0;  sprice=30.0;   bprice=25.0;
	tlocks=0;   tstocks=0;   tbarrels=0;
	printf(" enter the number of locks and to exit the loop enter -1 for locks");
	scanf("%d",&locks);
	while(locks!=-1)
	{
		c1=(locks<=0||locks>70);
		printf("enter the number of stocks and barrels");
		scanf("%d%d",&stocks,&barrels);
		c2=(stocks<=0||stocks>80);
		c3=(barrels<=0||barrels>90);
		if(c1)
			printf("value of locks not in the range 1..70  ");
		else
		  {
			temp=tlocks+locks;
			if(temp>70)
			printf("new total locks =%d not in the range 1..70 so old ",temp);
			else
                                	tlocks=temp;
		    }
		printf("total locks = %d\n",tlocks);	
                          if(c2)
			printf("value of stocks not in the range 1..80  ");
		else
		  { 
			temp=tstocks+stocks;
			if(temp>80)
			printf("new total stocks =%d  not in the range 1..80 so old   ",temp);
			else
			tstocks=temp;
		  }
		printf("total stocks=%d\n",tstocks);		
		if(c3)
			printf("value of barrels not in the range 1..90  ");
		else{
			temp=tbarrels+barrels;
			if(temp>90)
			printf("new total barrels =%d not in the range 1..90 so old ",temp);
			else
			tbarrels=temp;
		   } 	
		printf("total barrel=%d",tbarrels);				
		printf("\nenter the number of locks and to exit the loop enter -1 for locks\n");
		scanf("%d",&locks);
	}
             if (!(c1||c2||c3))
             {
	      printf("\ntotal locks = %d\ntotal stocks =%d\ntotal barrels =%d\n",tlocks,tstocks,tbarrels);
	      sales = lprice*tlocks+sprice*tstocks+bprice*tbarrels;
                    printf("\nthe total sales=%f\n",sales);		
             }
	if((sales > 0) && !(c1||c2||c3))
	{
		if(sales > 1800.0)
		{
			comm=0.10*1000.0;
			comm=comm+0.15*800;
			comm=comm+0.20*(sales-1800.0);
		}
		else if(sales > 1000)
		{
			comm =0.10*1000;
			comm=comm+0.15*(sales-1000);
		}
		else
			comm=0.10*sales;
			printf("the commission is=%f\n",comm);
	}
	else
	printf("there is no sales\n");
	return 0;
}
