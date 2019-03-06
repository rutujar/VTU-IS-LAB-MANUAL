package customer;
importjava.util.Scanner;
importjava.util.StringTokenizer;
classCust
{
String cname,dob;
 Scanner sobj=new Scanner(System.in);
void read()
 {
System.out.println("customer name");
cname=sobj.next();
System.out.println("dob in dd/mm/yyyy");
dob=sobj.next();
}
void display()
{
StringTokenizerst=new StringTokenizer(dob, "/");
System.out.println(cname+ ",");
while(st.hasMoreTokens())
    {
        String s=st.nextToken();
System.out.println(s+ ",");
    }
}
}
public class Customer {
public static void main(String[] args) {
Custcobj=new Cust();
cobj.read();
System.out.println(" customer details");
cobj.display();
                    }
    }
