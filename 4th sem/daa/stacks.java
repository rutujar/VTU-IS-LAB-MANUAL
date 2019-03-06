package stack;
importjava.util.Scanner;
class Stack1
{
	finalint size=5;
	intarr[] = new int[size];
	int top = -1;
	public void push(int item)
	{
		if(top < size-1)
		{
			top++;
			arr[top]=item;
			System.out.println("The " + item + "is pushed into the stack");	
		}
		else
		{
			System.out.println("Error !Stack Overflow ");
		}
	}
	public void pop()
	{
		if(top==-1)
		{
			System.out.println("error stack underflow");
		}
else
		{
		int item;
		item =arr[top];
		System.out.println("The " + arr[top] + " is poped out of the stack");
			top--;
		}
	}	
	public void display()
	{
		if(top==-1)
		{
			System.out.println("Stack Empty ");
		}
		else
		{
			System.out.println("Elements in stack ");
			for(inti=0;i<=top;i++)
			{
				System.out.println(arr[i]);
			}
		}	
	}
}
public static void main(String[] args) {
        Stack1 s= new Stack1();
		int x;
		Scanner sobj=new Scanner(System.in);
		intch;
		System.out.println("press 1 to push element");
		System.out.println("press 2 to pop element");
		System.out.println("press 3 to display elements");
		System.out.println("press 4 to exit ");
		do
		{
			System.out.println("Enter your choice: ");
			ch=sobj.nextInt();
			switch(ch)
			{
				case 1:		System.out.println("Enter element: ");
						x=sobj.nextInt();
						s.push(x);break;
				case 2:		s.pop();break;
				case 3:		s.display();break;
				case 4:		break;
				default: System.out.println("Invalid Choice ");	
						break;
		 }
	}
	while (ch!=4);
          }
    }
