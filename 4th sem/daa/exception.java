package exception;
importjava.util.Scanner;
public class Exception
{
public static void main(String[] args) {
inta,b,res;
Scanner input=new Scanner(System.in);
System.out.println("enter two numbers");
a=input.nextInt();
b=input.nextInt();
try
{
res=a/b;
System.out.println("res " +res);
 }
catch(ArithmeticException e)
{
System.out.println("exception caught division by zero"); 
}
input.close();
    }
    }
