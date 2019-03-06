import java.io.IOException;
import java.util.Scanner;
 class GreedyKnapsackDemo
{
	
		private int n;
		private int m;
		private int[][] array;
		
		public GreedyKnapsackDemo(int n, int m, int[][] array) 
		{
			this.n=n;
			this.m=m;
			this.array=array;
		}
		public void greedy()
		{
			float sum=0,max;
			inti,j=0;
			while(m>=0)  
			{  
				 max=0;  
			for(i=0;i<n;i++)  
			{  
					if(((float)array[1][i])/((float)array[0][i])>max)  
{    
            max=((float)array[1][i])/((float)array[0][i]);  
					j=i;  
				 }  
			}  
				 if(array[0][j]>m)  
			{  
				System.out.println("Quantity of item number: " +  (j+1) + " added is " +(float)m/array[0][j]);  
				 sum+=m*max;  
				 m=-1;  
			}  
				 else  
			{  
				System.out.println("Quantity of item number: " + (j+1) + " added fully ");/* + array[0][j]);*/  
				m-=array[0][j];  
				sum+=(float)array[1][j];  
				 array[1][j]=0;  
				 }  
			}  
			System.out.println("The total profit is " + sum);
		 }
	}

public class GreedyKnapsack
{
    public static void main(String args[]) throws IOException
    {  
	inti,max_qty,m,n;  
	char  ch;
	do{
		Scanner sc = new Scanner(System.in);
		int array[][]=new int[2][20];  
		System.out.println("Enter no of items");  
		n=sc.nextInt(); 
		System.out.println("Enter the weights of each items");
		for(i=0;i<n;i++)  
array[0][i]=sc.nextInt();    

		System.out.println("Enter the values of each items");
		for(i=0;i<n;i++)  
array[1][i]=sc.nextInt(); 

System.out.println("Enter maximum volume of knapsack :");  
		max_qty=sc.nextInt();  
		 m=max_qty;
		GreedyKnapsackDemogks = new GreedyKnapsackDemo(n, m, array);
		gks.greedy();

		System.out.println("Do u want to continue?Y/N");
		ch=sc.next().charAt(0);
        }while(ch=='Y');

    }  

}
