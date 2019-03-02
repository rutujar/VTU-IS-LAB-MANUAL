#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int ssn;
    char name[20];
    char dept[20];
    char desg[20];
    int sal;
    int phno;
    struct node *llink;
    struct node *rlink;
};
typedef struct node * element;
element getnode()
{
	element x;
	x=(element)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\n out of memory");
		exit(0);
	}
    printf("\n enter the details of EMPLOYEES DATA");
    printf("\n ssn: ");
    scanf("%d",&x->ssn);
    printf("\n name: ");
    scanf("%s",x->name);
    printf("\n dept: ");
    scanf("%s",x->dept);
    printf("\n desg: ");
    scanf("%s",x->desg);
    printf("\n sal: ");
    scanf("%d",&x->sal);
    printf("\n phno: ");
    scanf("%d",&x->phno);
	x->llink=x->rlink=NULL;
	return x;
}
element insert_front(element start)
{
    element temp;
    temp=getnode();
    if(start==NULL)
    return temp;
    temp->rlink=start;
    start->llink=temp;
    return start;
}
element insert_rear(element start)
{
    element temp,cur;
	temp=getnode();
    if(start==NULL)
    return temp;
    cur=start;
	while(cur->rlink!=NULL)
		cur=cur->rlink;
	cur->rlink=temp;
	temp->llink=cur;
	return start;
}
element delete_front(element start)
{
    element temp;
    if(start==NULL)
    {
        printf("\n no nodes");
        return start;
    }
    temp=start;
    start=start->rlink;
    printf("\n del students info:\n ssn:%d \n name:%s \n dept:%s\n desg:%s \n sal:%d\n phno:%d\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
    free(temp);
    return start;
}
element delete_rear(element start)
{
    element temp,cur;
    if(start==NULL)
    {
        printf("\n no nodes");
        return start;
    }
    temp=start;
    while(temp->rlink!=NULL)
    temp=temp->rlink;
    cur=temp->llink;
    if(cur)
    cur->rlink=NULL;
	else
    start=NULL;
    printf("\n del students info:\n ssn:%d \n name:%s \n dept:%s\n desg:%s \n sal:%d\n phno:%d\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
    free(temp);
    return start;
}
void display(element start)
{
    element temp;
    temp=start;
    if(start==NULL)
    {
        printf("\n no nodes");
        return;
    }
    printf("\n contents of DLL are ");
    while(temp!=NULL)
    {
        printf("[%d,%s,%s,%s,%d,%d]->",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
        temp=temp->rlink;
    }
}
void main()
{
    element start=NULL;
    int ch,n,i;
    while(1)
    {
		printf("-----DLL OPERATIONS-----");
        printf("\n 1.create \n 2.insert_front \n 3.insert_rear \n 4.delete_front \n 5.delete_rear \n 6. display\n 7.double ended queue \n8.EXIT");
        printf("\n enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("\n enter the number of employees ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                start=insert_rear(start);
            }
            break;
        case 2:start=insert_front(start);
            break;
        case 3:start=insert_rear(start);
            break;
       
        case 4:start=delete_front(start);
            break;
        case 5:start=delete_rear(start);
            break;
        case 6:display(start);
            break;
        case 7:printf("\n  DOUBLE ENDED QUEUE ");
               printf("\n Insert front and delete rear");
               printf("\n How Many Nodes ");
               scanf("%d",&n);
               for(i=1;i<=n;i++)
               start=insert_front(start);
               display(start);
               while(start!=NULL)
               {
                    printf("\n Press  1 to delete 2 to exit ");
                    getch();
                    start=delete_rear(start);
               }
               printf("\n\n Press any key to see other ended queue \n");
               getch();
               printf("\n Insert rear and delete front");
               printf("\n How Many Nodes ");
               scanf("%d",&n);
               for(i=1;i<=n;i++)
               start=insert_rear(start);
               display(start);
               while(start!=NULL)
               {
				   printf("\n Press  1 to delete 2 to exit ");
                    getch();
                    start=delete_front(start);
			   }
			   break;
        case 8: exit(0);
            getch();
        }
    }
}
