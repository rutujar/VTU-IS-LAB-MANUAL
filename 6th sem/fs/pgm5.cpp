#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>
#include<process.h>
#include<values.h>
#include<fstream.h>
#include<stdlib.h>

class record
{
public:char name[20],usn[20],branch[20],ind[5];
}rec[20];


char st_no[5];
int no;


void pack()
{
fstream fle1,fle2;
fle1.open("i.txt",ios::out);
fle2.open("r.txt",ios::out);
if((!fle1)||(!fle2))
{
cout<<"cant open either\n";
getch();
exit(0);
}
for(int i=0;i<no;i++)
{
fle1<<rec[i].usn<<"|"<< i<<"\n";
fle2<<i<<"|"<<rec[i].name<<"|"<<rec[i].usn<<"|"<<rec[i].branch<<"\n";
}
fle1.close();
fle2.close();
}


void unpack()
{
fstream fle2;
fle2.open("r.txt",ios::in);
for(int i=0;i<no;i++)
{
fle2.getline(rec[i].ind,5,'|');
fle2.getline(rec[i].name,20,'|');
fle2.getline(rec[i].usn,20,'|');
fle2.getline(rec[i].branch,20,'\n');
}
fle2.close();
}

void search()
{
char name[20],usn[20],branch[20],ind[5];
unpack();
for(int  i=0;i<no;i++)

if(strcmp(st_no,rec[i].ind)==0)
{
cout<<"search sucess\n";
cout<<"\nname="<<rec[i].name<<"usn="<<rec[i].usn<<"bran="<<rec[i].branch<<"\n";
}

}
void delete_rec(char rt_no[])
{
int flag=1;
char name[20],usn[20],branch[20];
unpack();
for(int i=0;i<no;i++)

if(strcmp(rec[i].usn,rt_no)==0)
flag=i;
if(flag==-1)
{
cout<<"error\n";
getch();
exit(0);
}
if(flag==no)
{
no--;
cout<<"deleted\n";
pack();
return;
}
for(i=flag;i<no;i++)
{
rec[i]=rec[i+1];
no--;
cout<<"deleted\n";
pack();
return;
}
}
void main()
{
char st_usn[20],rt_usn[20];
fstream fle1,fle2;
char name[20],usn[20],branch[20],ind[5];
int i,flag,ch;
clrscr();
for(;;)
{
cout<<"1:add\n2:search\n3:delete\n4:display\n";
cout<<"enter your choice\n";
cin>>ch;
switch(ch)
{
case 1:cout<<"enter the no of records\n";
cin>>no;
cout<<"enter the details of students\n";
for(i=0;i<no;i++)
{
cout<<"name "<<i+1<<"=";
cin>>rec[i].name;
cout<<"usn "<<i+1<<"=";
cin>>rec[i].usn;
cout<<"branch "<<i+1<<"=";
cin>>rec[i].branch;
}
pack();
break;
case 2:cout<<"enter thye usn u want to search\n";
cin>>st_usn;
//fstream fle1;
fle1.open("i.txt",ios::in);
if(!fle1)
{
cout<<"cant open the file\n";
getch();
exit(0);
}
flag=0;
for(i=0;i<no;i++)
{
fle1.getline(rt_usn,20,'|');
fle1.getline(st_no,5,'\n');
if(strcmp(rt_usn,st_usn)==0)
{
search();
flag=1;
}
}
if(!flag)

cout<<"not found\n";
fle1.close();
break;
case 3:cout<<"enter thye usn u want to delete\n";
cin>>st_usn;

fle1.open("i.txt",ios::in);
if(!fle1)
{
cout<<"cant open the file\n";
getch();
exit(0);
}
flag=0;
for(i=0;i<no;i++)
{
fle1.getline(rt_usn,20,'|');
fle1.getline(st_no,5,'\n');
if(strcmp(rt_usn,st_usn)==0)
{
delete_rec(rt_usn);
flag=1;
}
}
if(!flag)
cout<<"failure\n";
fle1.close();

break;
case 4:for(int i=0;i<no;i++)
{
cout<<"\n name="<<rec[i].name<<"\t usn="<<rec[i].usn<<"\t branch="<<rec[i].branch<<"\n";

}
break;
default:exit(0);
break;
}
}
}
