#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<conio.h>

class coseq
{
 char list1[100][20],list2[100][20];
 int n1,n2;
 public: void load();
	 void seq_sort();
	 void match();
};
fstream f1,f2,of;
void coseq :: load()
{
 n1=n2=-1;
  while(!f1.eof())
   f1.getline(list1[++n1],20,'\n');
  while(!f2.eof())
   f2.getline(list2[++n2],20,'\n');
}
void coseq :: seq_sort()
{
 char temp[30];
 for(int i=0;i<=n1;i++)
 {
 for(int j=i+1;j<=n1;j++)
  {
   if(strcmp(list1[i],list1[j])>0)
   {
    strcpy(temp,list1[i]);
    strcpy(list1[i],list1[j]);
    strcpy(list1[j],temp);
   }
  }
 }
 for(int k=0;k<=n2;k++)
 {
  for(int l=k+1;l<=n2;l++)
  {
   if(strcmp(list2[k],list2[l])>0)
   {
    strcpy(temp,list2[k]);
    strcpy(list2[k],list2[l]);
    strcpy(list2[l],temp);
   }
  }
 }
}
void coseq :: match()
{
 int i=0,j=0;
 while((i<=n1)&&(j<=n2))
 {
  if(strcmp(list1[i],list2[j])==0)
  {
   cout<<list1[i]<<endl;
   of<<list1[i]<<endl;
   i++;
   j++;
   continue;
  }
  else if(strcmp(list1[i],list2[j])>0)
   j++;
  else
   i++;
 }
}
void main()
{
 clrscr();
 coseq cq;
 f1.open("file1.txt",ios::in);
 f2.open("file2.txt",ios::in);
 if(!f1||!f2)
 {
  cout<<"\n ERROR file dont exist";
  getch();
  exit(1);
 }
 cq.load();

 of.open("file3.txt",ios::out);
 cq.seq_sort(); cq.match();
 f1.close();
 f2.close();
 of.close();
 getch();
}
