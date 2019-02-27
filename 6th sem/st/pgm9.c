#include&lt;stdio.h&gt;
int main()
{
int locks, stocks, barrels, tlocks, tstocks, tbarrels;
float lprice,sprice,bprice,lsales,ssales,bsales,sales,comm;
lprice=45.0;
sprice=30.0;
price=25.0;
tlocks=0;
tstocks=0;
tbarrels=0;
printf(&quot;\nenter the number of locks and to exit the loop enter -1 for locks\n&quot;);
scanf(&quot;%d&quot;, &amp;locks);
while(locks!=-1)
{
printf(&quot;enter the number of stocks and barrels\n&quot;);
scanf(&quot;%d%d&quot;,&amp;stocks,&amp;barrels);
tlocks=tlocks+locks;
tstocks=tstocks+stocks;
tbarrels=btarrels+barrels;
printf(&quot;\nenter the number of locks and to exit the loop enter -1 for locks\n&quot;);
scanf(&quot;%d&quot;,&amp;locks);
}
printf(&quot;\ntotal locks = %d\”,tlocks);
printf(“total stocks =%d\n”,tstocks);
printf(“total barrels =%d\n&quot;,tbarrels);
lsales = lprice*tlocks;

ssales=sprice*tstocks;
bsales=bprice*tbarrels;
sales=lsales+ssales+bsales;
if(sales &gt; 1800.0)
{
comm=0.10*1000.0;
comm=comm+0.15*800;
comm=comm+0.20*(sales-1800.0);
}
 else if(sales &gt; 1000)
{
 comm =0.10*1000;
 comm=comm+0.15*(sales-1000);
}
 else
 comm=0.10*sales;
 printf(&quot;the commission is=%f\n&quot;,comm);
 return 0;
}
