import java.util.Scanner;
 class queue
{
    int f=0,r=0,size,q[];
    void insert(int n)
    {
        Scanner scan=new Scanner(System.in);
        q=new int[10];
        for(inti=0;i<n;i++)
        {
            System.out.println("enter "+i+"element");
            intele=scan.nextInt();
            if(r+1>10)
            {
                System.out.println("q is full \n lost packet "+ele);
                break;
            }
            else
            {
                r++;
                q[i]=ele;
            }
        }
    }
    void deleting()
    {
        Scanner in=new Scanner(System.in);
        Thread t=new Thread();
        if(r==0)
        {
            System.out.println("q is empty");
        }
        else
        {
            for(inti=f;i<r;i++)
            {
                try
                {
                    t.sleep(1000);
                }
                catch(Exception e)
                {
                }
                System.out.println("leaked packet"+q[i]);
                f++;
            }
        }
    }
} 
public class leaky1 extends Thread
{
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        queue q=new queue();
        System.out.println("enter the no of packets");
        int n=in.nextInt();
        q.insert(n);
        q.deleting();
    }
}
