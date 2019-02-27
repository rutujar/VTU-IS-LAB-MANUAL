#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#define nbucket 4
#define slots 3
#define recsize 31
class student
{
  char usn[5],name[10],branch[5],sem[2];
  public:void initialize();
	 void read();
	 void pack();
	 void search(char *key);
	 int hash(char *key);
};
fstream hsh,data;
void student::read()
{
 cout<<"\nUSN:";
 cin>>usn;
 cout<<"\nName:";
 cin>>name;
 cout<<"\nBranch:";
 cin>>branch;
 cout<<"\nSem:";
 cin>>sem;
}
void student::initialize()
{
  char buckt[recsize*slots];
  hsh.open("myhash.txt",ios::out);
  data.open("mydata.txt",ios::out);
  for(int i=1;i<=nbucket;i++)
  {
    for(int j=0;j<=recsize*slots-1;j++)
    {
      if(((j+1)%recsize)==0)
	buckt[j]='|';
      else
	buckt[j]='*';
    }
    buckt[j]='\0';
    data<<buckt<<endl;
    hsh<<"0\n";
  }
  data.close();
  hsh.close();
}

int student::hash(char *key)
{
  int sum=0,h;
  for(int i=0;i<=strlen(key);i++)
   sum=sum+key[i];
  h=(int)sum%nbucket;
  cout<<"\nThe hash value is : "<<h;
  return(h);
}

void student::pack()
{
  int count,hom_add,hsh_add=0,data_add=0;
  char buffer[50],bt[93],num[3];
  read();
  hom_add=hash(usn);
  for(int i=0;i<hom_add;i++)
  {
    hsh_add=hsh_add+3;
    data_add=data_add+recsize*slots;
  }
  hsh.seekg(hsh_add,ios::beg);
  hsh>>num;
  count=atoi(num);
  cout<<"\nThe filled slots = "<<count;
  if(count==3)
  {
    cout<<"\nAll slots are filled in bucket "<<hom_add;
    getch();
    return;
  }
  data.seekg(data_add+1,ios::beg);
  data.getline(bt,recsize*slots,'\0');
  strcpy(buffer,usn);
  strcat(buffer,"|");
  strcat(buffer,name);
  strcat(buffer,"|");
  strcat(buffer,branch);
  strcat(buffer,"|");
  strcat(buffer,sem);
  strcat(buffer,"|");
  int len=strlen(buffer);
  for(i=len;i<31;i++)
    strcat(buffer,"#");
  strcat(buffer,"|");
  i=count*recsize;
  for(int j=0;j<strlen(buffer);j++)
  {
    bt[i++]=buffer[j];
  }
  data.seekp(data_add,ios::beg);
  data<<bt;
  count++;
  hsh.seekp(hsh_add,ios::beg);
  hsh<<count;
}

void student::search(char *key)
{
  int count,hom_add,hsh_add=0,data_add=0;
  char buffer[93],bt[50],num[3],*ptr;
  hom_add=hash(key);
  for(int i=0;i<hom_add;i++)
  {
    hsh_add+=3;
    data_add+=recsize*slots;
  }
  hsh.seekg(hsh_add,ios::beg);
  hsh>>num;
  count=atoi(num);
  //cout<<"\nThe value of count is "<<count<<endl;
  if(count==0)
  {
    cout<<"\nRecord is not present in the file!";
    getch();
    return;
  }
  data.seekg(data_add,ios::beg);
  data.getline(buffer,recsize*slots,'\0');
  i=1;
  int k=0;
  for(i=1;i<=slots;i++)
  {
    for(int j=0;j<recsize-1;j++,k++)
    {
       bt[j]=buffer[k];
    }
    bt[j]='\0';
    ptr=strtok(bt,"|");
    if(strcmp(ptr,key)==0)
    {
      cout<<"\nSuccessful search!";
      cout<<"\nUSN : "<<ptr;
      getch();
      cout<<"\nName : "<<strtok(NULL,"|");
      cout<<"\nBranch : "<<strtok(NULL,"|");
      cout<<"\nSem : "<<strtok(NULL,"|");
      return;
    }
  }
}
void main()
{
  student s;
  char *usnno;
  int ch;
  clrscr();
  s.initialize();
  for(;;)
  {
    cout<<"\n\n1 -> Pack\n2 -> Search\n3 -> Exit\nEnter your choice : ";
    cin>>ch;
    switch(ch)
    {
      case 1:hsh.open("myhash.txt",ios::in|ios::out);
	     data.open("mydata.txt",ios::in|ios::out);
	     s.pack();
	     hsh.close();
	     data.close();
	     break;
      case 2:cout<<"\nSearching for a record\n";
	     hsh.open("myhash.txt",ios::in|ios::out);
	     data.open("mydata.txt",ios::in|ios::out);
	     cout<<"\nEnter the usn to be searched : ";
	     cin>>usnno;
	     s.search(usnno);
	     hsh.close();
	     data.close();
	     break;
      case 3:cout<<"\nEnd of program!\n";
	     exit(1);
    }
    getch();
  }
}
