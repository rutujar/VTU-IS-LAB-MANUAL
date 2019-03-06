import java.util.Scanner;
class DP {
int max(inta,int b)
{
			if(a>b) return a;
			else return b;
}
void knapsack(int n, int m, int w[], int p[])
{
			inti, j;
			int v[][]=new int[10][10];
			int x[]=new int[10];
			for(i=0;i<=n;i++)
			{	for(j=0;j<=m;j++)
				{
					if(i==0||j==0)
						v[i][j]=0;
					else if(w[i]>j)
						v[i][j]=v[i-1][j];
					else
						v[i][j]=max(v[i-1][j], v[i-1][j-w[i]]+p[i]);
				}
			} 
System.out.println(“Optimal Solution Computation”);
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=m;j++)
				{
					System.out.print(v[i][j]+" ");
				}
				System.out.println();
			}
			System.out.println("maximum profit"+v[n][m]+"\n");
			for(i=1;i<=n;i++)
				x[i]=0;
			i=n;	
j=m;
			while(i!=0&&j!=0)
			{
				if(v[i][j]!=v[i-1][j])
				{
					x[i]=1;
					j=j-w[i];
				}
			i=i-1;
			}
			System.out.println("objects selected are\n");
			for(i=1;i<=n;i++)
			{
				if(x[i]==1)
				System.out.println("object"+i+"\n");
			}
}
}
class DPKnapsack
{
public static void main(String args[])
{      
 Scanner s=new Scanner(System.in);
		DP d=new DP();
		inti,n,m;
		int w[]=new int[10];
		int p[]=new int[10];
		System.out.println("enter the number of items\n");
		n=s.nextInt();
		System.out.println("enter the capacity of knapsack\n");
		m=s.nextInt();
		System.out.println("Enter the weight of each item\n");
		for(i=1;i<=n;i++)
			w[i]=s.nextInt();
		System.out.println("Enter the profit of each item\n");
		for(i=1;i<=n;i++)
			p[i]=s.nextInt();
		d.knapsack(n,m,w,p);
} 
}
