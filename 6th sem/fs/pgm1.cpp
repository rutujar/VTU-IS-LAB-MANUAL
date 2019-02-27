#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>

class names
{
public:char name[50];
};

	//void reverse(ofstream &out,char name[255])
	//{
	//char *rev;
	//rev=name+strlen(name)-1;
	//while(rev>=name)
	//{
	//cout<<*rev;
	//out<<*rev;
	//rev--;
	//}
	//cout<<endl;
	//out<<"\n";
	//}

void main()
{
names n[10];
clrscr();
ofstream out;
out.open("file.txt",ios::out);
int m;
cout<<"enter the no. of names to be entered\n";
cin>>m;
for(int i=0;i<m;i++)
{
cout<<"enter name\n";
cin>>n[i].name;
cout<<"the name in reverse order\n";
strrev(n[i].name);
cout<<n[i].name<<"\n";
out<<n[i].name;
out<<"\n";
}
out.close();
ifstream in;
in.open("file.txt",ios::in);
ofstream outf;
outf.open("f1.txt",ios::out);
char ch[255];
cout<<"names from files\n";
while(in)
{
in.getline(ch,255);
if(in)
strrev(ch);
outf<<ch;
outf<<"\n";
cout<<ch<<"\n";

}
cout<<endl;
in.close();
outf.close();
in.open("f1.txt",ios::in);
outf.open("f2.txt",ios::out);
cout<<"reverse order from files\n";
while(in)
{
in.getline(ch,255);
if(in)
strrev(ch);
outf<<ch;
outf<<"\n";
cout<<ch<<"\n";
}
in.close();
outf.close();
getch();
}
