#include<iostream.h>
#include<string.h>
#include<math.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
class records
{
   public: int flag;
    char name[20],usn[20];
};
records rec[10];
int no,k;
int hash(int m)
{   int r,q;
    r=m%10;
q=rand()/10;
    q=m/10;
    k=(q+r+7)%10; //because 7 is our fav number #CR7
    return k;
}
void unpack()
{   int i=0;
    fstream in;
    in.open("abc.txt",ios::in);
    while(!in.eof())
    {
      in.getline(rec[i].name,20,'|');
      in.getline(rec[i].usn,20,'\n');
      i++;
    }
    in.close();
}
void search()
{
 int m,i,f=0;
 char usn[15];
    cout<<endl;
    cout<<"enter usn:";
    cin>>usn;
    m=atoi(usn);
    k=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[k%10].usn,usn))==0)
      {
      cout<<"\n found at "<<k<<": ";
      cout<<rec[k].usn<<"\t"<<rec[k].name<<"\n";
      f=1;
      }
      k=k+1;
    }
    if(f!=1)
    cout<<"\n not found \n";
    return;
 }
void main()
{
    clrscr();
    int m;
    char usn[20],name[20];
    cout<<"Enter no of records";
    cin>>no;
    if(no<=10)
    {
    for(int l=0;l<10;l++)
    rec[l].flag=0;
    for(int i=0;i<no;i++)
    {
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter usn: ";
	cin>>usn;
	m=atoi(usn);
	k=hash(m);
	cout<<"address: "<<k<<"\n";
	if(rec[k].flag==0)
	{
	    strcpy(rec[k].name,name);
	    strcpy(rec[k].usn,usn);
	    rec[k].flag=1;
	}
	else
	{
	    for(int j=k+1;j%10<10;j++)
	    {
		if(rec[j%10].flag==0)
		 {
			strcpy(rec[j%10].name,name);
			strcpy(rec[j%10].usn,usn);
			rec[j%10].flag=1;
			break;
		}
	    }
	}
    }
    cout<<"The file output is: \n";
    for(i=0;i<10;i++)
    {
    if(rec[i].flag==1)
    cout<<rec[i].name<<"\t"<<rec[i].usn<<"\n";
    else
    cout<<"## \n";
    }
    fstream f1;
    f1.open("abc.txt",ios::out);
    for(i=0;i<10;i++)
	{
	    if(rec[i].flag==0)
	    f1<<"#|#"<<"\n";
	    else
	    f1<<rec[i].name<<"|"<<rec[i].usn<<"\n";
	}
    f1.close();
    int ch=1;
    while(ch==1)
    {
    cout<<"\n to search the file enter 1:";
    cin>>ch;
    if(ch==1)
    search();
    }
    }
    else
    cout<<"out of range";
    getch();
}
