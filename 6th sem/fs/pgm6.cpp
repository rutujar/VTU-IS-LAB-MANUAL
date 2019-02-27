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

	    public: char name[20], usn[20], branch[20], ind[5];
} rec[20];

char st_no[5];
int no=0,no1;
record re[20]={NULL};
record re1[20]={NULL};
void primsort()
{
   fstream fle1;
     fle1.open("i.txt",ios::out);
    for(int i=0;i<no;i++)
	   re[i]=rec[i];
     record temp;
  for(i=0;i<=no-2;i++)
   for(int j=0;j<=no-2-i;j++)
   if(strcmp(re[j].usn,re[j+1].usn)>0)
   {
      temp=re[j];
      re[j]=re[j+1];
      re[j+1]=temp;
   }
   for(j=0;j<no;j++)
   {
     i=0;
       while(strcmp(re[j].usn,rec[i].usn)!=0)
       i++;
       if(strcmp(re[j].usn,rec[i].usn)==0)
	  fle1<<re[j].usn<<"|"<<i<<"\n";
   }
       fle1.close();
}
void secsort()
{
   fstream fle2;
     fle2.open("s.txt",ios::out);
   for(int i=0;i<no;i++)
	re1[i]=rec[i];
     record temp;
  for(i=0;i<=no-2;i++)
   for(int j=0;j<=no-2-i;j++)
   if(strcmp(re1[j].name,re1[j+1].name)>0)
   {
      temp=re1[j];
      re1[j]=re1[j+1];
      re1[j+1]=temp;
   }
   for(j=0;j<no;j++)
   {
	  fle2<<re1[j].name<<"|"<<re1[j].usn<<"\n";
   }
   fle2.close();
}
void pack()

{
	   fstream fle1,fle2,fle3;

	  fle2.open("r.txt",ios::out);
	       if(!fle2)
	     {
		  cout<<"Cant open either\n";
		     getch();
		   exit(0);
	      }
	     for(int i=0;i<no;i++)
	  {
	      fle2<<i<<"|"<<rec[i].name<<"|"<<rec[i].usn<<"|"<<rec[i].branch<<"\n";
	   }
	    fle2.close();
	    primsort();
	    secsort();
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
	    for(int i=0;i<no;i++)
	    if(strcmp(st_no,rec[i].ind)==0)
	    {
	    cout<<"Search success\n";
	    cout<<"name="<<rec[i].name<<"\tusn="<<rec[i].usn<<"\tbranch="<<rec[i].branch<<"\n";
	    return;
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
			cout<<"Error\n";
			getch();
			exit(0);
	    }
	    if(flag==no-1)
	    {
			no--;
	    }
	    else
	    {
	      for(i=flag;i<no;i++)
	       rec[i]=rec[i+1];
		  no--;
	    }
	     cout<<"Deleted\n";
		pack();
	       return;
}
void main()
{
    char st_name[20],rt_usn[20],st_usn[20];
    fstream fle1,fle2,fle3;
    char name[20],usn[20],branch[20],ind[5];
    int i=0, flag, ch;
    clrscr();
    for(;;)
    {
       cout<<"1:add\n2.search\n3.delete\n4.display\n";
       cout<<"Enter your choice\n";
	cin>>ch;
	switch(ch)
	{
	    case 1: cout<<"Enter the details of students\n";
		     cout<<"name=";
		     cin>>rec[i].name;
		      cout<<"usn=";
		      cin>>rec[i].usn;
		       cout<<"branch=";
		       cin>>rec[i].branch;
		      for(int j=0;j<i;j++)
		      {
			if(strcmp(rec[i].usn,rec[j].usn)==0)
			{
			 printf("\n duplicate entry of usn");
			 break;
			}
		       }
		      if(j==i)
		      {
		       no++;
		       i++;
		       pack();
		      }
		     break;

	case 2: cout<<"Enter the name you want to search\n";
		cin>>st_name;
		fle3.open("s.txt",ios::in);
		fle1.open("i.txt",ios::in);
		if(!fle1)
		{
		cout<<"Cant open the file\n";
		getch();
		exit(0);
		}
		 flag=0;
		  for(j=0;j<no;j++)
		 {
		   fle3.getline(name,20,'|');
		   fle3.getline(usn,20,'\n');
		   if(strcmp(st_name,name)==0)
		   {
		    for(int k=0;k<no;k++)
		    {
		     fle1.getline(rt_usn,20,'|');
		     fle1.getline(st_no,5,'\n');
		     if(strcmp(usn,rt_usn)==0)
		      {
			search();
			flag=1;
		       //	break;
		       }
		    }
		  }
		}
		      if(!flag)
		     cout<<"Not found\n";
		    fle3.close();
		 fle1.close();
		   break;

       case 3: cout<<"Enter the usn you want to delete\n";
		cin>>usn;
		fle3.open("s.txt",ios::in);
		fle1.open("i.txt",ios::in);
		if(!fle1||!fle3)
	       {
		 cout<<"Cant open the file\n";
		 getch();
		 exit(0);
		}
		flag=0;
		for(j=0;j<no;j++)
		{
		    fle3.getline(name,20,'|');
		    fle3.getline(st_usn,20,'\n');
		    if(strcmp(usn,st_usn)==0)
		    {
			  for(int k=0;k<no;k++)
			 {
			     fle1.getline(rt_usn,20,'|');
			     fle1.getline(st_no,5,'\n');
			     if(strcmp(rt_usn,usn)==0)
			     {
				delete_rec(rt_usn);
				  i--;
				flag=1;
			      }
			   }
			}
		    }

		    if(!flag)
		    cout<<"Failure\n";
		    fle1.close();
		    fle3.close();
		    break;
	 case 4: for(int k=0;k<no;k++)
		  cout<<"name="<<rec[k].name<<"\tusn="<<rec[k].usn<<"\tbranch="<<rec[k].branch<<"\n";
		  break;
	  default:exit(0);
		   break;
	  }
      }

}
