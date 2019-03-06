package quicksort;
importjava.util.Random;
importjava.util.Scanner;
public class Quicksort 
{
static final int MAX = 10005;
staticint[] a = new int[MAX];
public static void main(String[] args)
 {
 Scanner input = new Scanner(System.in);
System.out.println(" enter max array");
int n=input.nextInt();
Random random=new Random();
for(inti=0;i<n;i++)
a[i]=random.nextInt(10000);
System.out.println("input array");
for(inti=0;i<n;i++)
System.out.println(a[i]+ " ");
longstarttime=System.nanoTime();
quicksortalgo(0,n-1);
longstoptime=System.nanoTime();
longelapsedtime=stoptime-starttime;
System.out.println("sorted array ");
for(inti=0;i<n;i++)
System.out.println(a[i]+ " ");
System.out.println("\nTime Complexity (ms) for n = " + n + " is : " + (double) elapsedtime / 1000000); 
input.close();
         }
public static void quicksortalgo(intp,int r)
 {
inti,j,pivot,temp;
if(p<r)
{
i=p;
j=r+1;
pivot=a[p];
while(true)
{
i++;
while(a[i]<pivot&&i<r)
i++;
j--;
while(a[j]>pivot)
j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
  }
else
break;
            }
a[p]=a[j];
a[j]=pivot;
quicksortalgo(p,j-1);
quicksortalgo(j+1,r);
             }
}
}
