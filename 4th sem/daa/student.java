packagenstudent;
importjava.util.Scanner;
class Student
{
	String usn, name, branch, phone;
	void read()
	{
		Scanner sobj=new Scanner(System.in);
		System.out.println("Enter Student USN");
		usn=sobj.next();
		System.out.println("Enter Student Name:");
		name=sobj.next();
		System.out.println("Enter Student Branch:");
		branch =sobj.next();
		System.out.println("Enter Student PhoneNo:");
		phone =sobj.next();
	}
	void display()
	{
		System.out.println(usn+"  "+name+" "+ branch +" "+phone);
	}
}
public class Nstudent {
public static void main(String[] args) {
int n;
		Scanner sobj=new Scanner(System.in);
		System.out.println("Enter the Number of Students");
		n=sobj.nextInt();
		Student[] st=new Student[n];
		System.out.println("Please enter the student details");
		for(inti=0;i<st.length;i++)
		{
			st[i]=new Student();
		}
		for(inti=0;i<st.length;i++)
		{
			st[i].read();
		}
		System.out.println("USN    | Name  | Branch  |PhoneNo");
		for(inti=0;i<st.length;i++)
		{
			st[i].display();
		}
}
    }
