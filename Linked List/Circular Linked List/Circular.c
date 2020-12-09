#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *link1;
    int data;
    struct node *link2;
}*start=NULL,*last=NULL;
void insert(int item)
{
	int ele;
	struct node *newnode=malloc(sizeof(struct node));
	struct node *loc;
	loc=start;
	newnode->link1=NULL;
	newnode->link2=NULL;
	newnode->data=item;
	if(start==NULL)
	{
	    start=newnode;
    	newnode->link2=start;  
    	last=newnode;
    	newnode->link1=last;
	}
	else{
	    printf("after which element the data should be inserted:  ");
	    scanf("%d",&ele);
	    while(loc->link2!=start)
	    {   if(loc->data==ele)
	           break;
			loc=loc->link2;
	    }	
        newnode->link1=loc;
        newnode->link2=loc->link2;
        loc->link2=newnode;
        if(newnode->link2==start)
        {
            last=newnode;
            start->link1=last;
        }

	}

}
void delete(int item)
{
	struct node *loc,*prev;
	loc=start;
	if(start->data==item)
	{   if(start->link2==start)
	       start=NULL;
	    else
		{  
		   start=loc->link2;
     	   start->link1=last;
     	   last->link2=start;
		}
        return;
	 }
	while(loc->data!=item)
	{   prev=loc;
  		loc=loc->link2;
	}
	if(loc->link2!=start)
	{
	    loc->link2->link1=loc->link1;
	    prev->link2=loc->link2;
	}
	else if(loc->link2==start)
	{   last=prev;
	    prev->link2=start;
	    start->link1=last;
	}
	else
	printf("element not found\n");
}
void display()
{
	struct node *loc;
	loc=start;
	printf("list: ");
	if(start==NULL)
	 { printf("list is empty");
	   return;
     }
	while(loc->link2!=start)
	{
		printf("%d ->",loc->data);
		loc=loc->link2;
	}
	printf("%d \n",loc->data);
}
int main()
{
	int ch,elt;
	printf("1.Insertion after a particular element\n2.Deletion an element\n3.display\n4.exit\n");
	do
	{
		printf("enter choice:   ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter element : ");
				scanf("%d",&elt);
				insert(elt);
				break;
			case 2:
				printf("enter element to be deleted: ");
				scanf("%d",&elt);
				delete(elt);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("exiting\n");
				exit(0);
				break;
			default:
				printf("wrong choice\n");
				break;
		}
		
	}
	while(1);
}