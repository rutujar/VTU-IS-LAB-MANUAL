#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    char name[30];
    char usn[10];
    char branch[4];
    int sem;
    int phno;
    struct node *link;
};
typedef struct node *element;
element insert_front(element start)
{
    element temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the name: ");
    scanf("%s",&temp->name);
    printf("\n Enter the usn: ");
    scanf("%s",&temp->usn);
    printf("\n Enter the branch: ");
    scanf("%s",&temp->branch);
    printf("\n Enter the sem: ");
    scanf("%d",&temp->sem);
    printf("\n Enter the phone no: ");
    scanf("%d",&temp->phno);
    temp->link=NULL;
    temp->link=start;
    return temp;
}
element insert_rear(element start)
{
    element temp,cur;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the name: ");
    scanf("%s",&temp->name);
    printf("\n Enter the usn: ");
    scanf("%s",&temp->usn);
    printf("\n Enter the branch: ");
    scanf("%s",&temp->branch);
    printf("\n Enter the sem: ");
    scanf("%d",&temp->sem);
    printf("\n Enter the phone no: ");
    scanf("%d",&temp->phno);
    temp->link=NULL;
    if(start==NULL)
    {
        return temp;
    }
    cur=start;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return start;
}
element delete_front(element start)
{
    element temp;
    if(start==NULL)
    {
        printf("\n list is empty!!!!!!");
        return start;
    }
    else
    {
        temp=start;
        start=start->link;
        printf("\n The deleted students info:\n name:%s\n usn:%s\n branch:%s\n sem:%d\n phno:%d\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
        free(temp);
        return start;
    }
}
element delete_rear(element start)
{
    element temp,prev;
    temp=start;
    if(start==NULL)
    {
        printf("\n List is empty!!!!!");
        return start;
    }
    prev=NULL;
    temp=start;
    while(temp->link!=NULL)
    {
        prev=temp;
        temp=temp->link;
    }
    printf("\n The deleted student info:\n name:%s\n usn:%s\n branch:%s\n sem:%d\n phno:%d\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
    if(temp==start)
    {
        start=NULL;
    }
    else
    {
        prev->link=NULL;
    }
    free(temp);
    return start;
}
void display(element start)
{
    element temp;
	int count = 0;
    if(start==NULL)
    {
        printf("\n List is empty!!!!!!!");
        return ;
    }
    temp=start;
    printf("\n contents of singly linked list are:\n");
    while(temp!=NULL)
    {
         printf("[%s,%s,%s,%d,%d]->",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
         temp=temp->link;
		 count++;
    }
	printf("\n number of nodes in sll %d",count);
}
element stack(element start)
{
    int ch;
    while(1)
    {
          printf("1.push\n 2.pop\n 3.display\n 4.exit");
          printf("\n Enter the choice:");
          scanf("%d",&ch);
          switch(ch)
          {
                case 1:start=insert_front(start);
                break;
                case 2:start=delete_front(start);
                break;
                case 3:display(start);
                break;
                default:return start;
          }
     }
}
element queue(element start)
{
    int ch;
    while(1)
    {
        printf("\n 1.insert\n 2.delete\n 3.display\n 4.exit");
        printf("\n enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:start=insert_front(start);
            break;
            case 2:start=delete_rear(start);
            break;
            case 3:display(start);
            break;
            default:return queue;
        }
    }
}
void main()
{
    element start=NULL;
    int ch,n,i;
    while(1)
    {
         printf("\n --------SLL operations-----------");
         printf("\n 1.create \n 2.insertfront \n 3.insertrear \n 4.deletefront \n 5.deleterear \n 6.display \n 7.stack \n 8.queue \n 9.exit");
         printf("\n Enter your choice: \n");
         scanf("%d",&ch);
         switch(ch)
         {
              case 1:printf("\n enter the number of students ");
              scanf("%d",&n);
              for(i=1;i<=n;i++)
              {
                    printf("\n enter %d students",i);
                    start=insert_front(start);
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
              case 7:start=stack(start);
                 break;
              case 8:start=queue(start);
                 break;
              case 9:exit(0);
              getch();
         }
    }
}
