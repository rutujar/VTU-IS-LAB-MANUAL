#include<stdio.h>
#include<conio.h>

void readstr(char* str,char* pat,char* rep)
{
  printf("\n  Enter Main String : "); //reading main string
  gets(str);
  printf("\n  Enter Pattern String : ");
  gets(pat);
  printf("\n  Enter Replace String : ");
  gets(rep);
}
void patmatrep(char* str,char* pat,char* rep,char* ans) // patter matching and replacing function
{
int i,m,c,j,k,flag=0;
	
    i = m = c = j = 0;
	while ( str[c] != '\0')
	{
		if ( str[m] == pat[i] ) // ...... matching
		{
			i++;
			m++;
		    if ( pat[i] == '\0') //.....found occ
		     {
		       //.. copy replace string in ans string ..
		       for(k=0; rep[k] != '\0';k++,j++)
			   ans[j] = rep[k];
			   i=0;
	   c=m;
			   flag=1;
		     }
		}
		else //... mismatch
		{
			ans[j] = str[c];
			j++;
			c++;
			m = c;
			i=0;
		}
	}//while
	ans[j] = '\0';
	if(flag==0)
printf("\n  PATTERN DOES NOT EXIST IN STRING \n");
}
void main()
{
 int ch;
 char str[20],pat[20],rep[20],ans[30];
 readstr(str,pat,rep);
 patmatrep(str,pat,rep,ans);
 printf("\n  The resultant string is : %s",ans);
 getch();
}
