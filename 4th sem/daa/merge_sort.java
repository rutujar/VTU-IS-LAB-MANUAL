packagemergesort;
importjava.util.Random;
importjava.util.Scanner;
public class Mergesort
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
mergesortalgo(0,n-1);
longstoptime=System.nanoTime();
longelapsedtime=stoptime-starttime;
System.out.println("sorted array ");
for(inti=0;i<n;i++)
System.out.println(a[i]+ " ");
System.out.println("\nTime Complexity (ms) for n = " + n + " is : " + (double) elapsedtime / 1000000); 
input.close();
    }
public static void mergesortalgo(intlow,int high)
    {
int mid;
if (low < high) 
    {
mid = (low + high) / 2;
mergesortalgo(low, mid);
mergesortalgo(mid + 1, high);
merge(low, mid, high);
     }
     }
public static void merge(intlow,intmid,int high)
    {
int[] b = new int[MAX];
inti,h,j,k;
     h=i=low;
     j=mid+1;
while((h<=mid)&&(j<=high))
if(a[h]<a[j])
b[i++]=a[h++];
else
b[i++]=a[j++];
if(h>mid)
for(k=j;k<=high;k++)
b[i++]=a[k];
else
for(k=h;k<=mid;k++)
b[i++]=a[k];
for(k=low;k<=high;k++)
a[k]=b[k];
    }
}
