#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef;
	int expo;
	struct node *link;
}*start=NULL,*start2=NULL,*start3=NULL;
void display(struct node *p)
{  
	struct node *loc=NULL;
	loc=p;
	
	while(loc->link!=NULL)
	{
		printf("%dx^%d +",loc->coef ,loc->expo);
		loc=loc->link;
	}
	printf("%dx^%d ",loc->coef ,loc->expo);
	
}
void insert(struct node **p,int m,int n)
{
	struct node *loc;
	struct node *newnode=malloc(sizeof(struct node));
	newnode->coef=m;
	newnode->expo=n;
	newnode->link=NULL;
    loc=*p;
	
	if((*p)==NULL)
	{   
		newnode->link=(*p);
		(*p)=newnode;
	   	
	}
	else
	{
		while(loc->link!=NULL)
		loc=loc->link;
		loc->link=newnode;	
		
	}
   
}
void sum(struct node *loc,struct node *temp)
{   
	struct node *newnode=malloc(sizeof(struct node));
	int m;
	while(loc->link!=NULL && temp->link!=NULL)
	{  
	    
		if(loc->expo>temp->expo)
		{
			insert(&start3,loc->coef,loc->expo);
			loc=loc->link;
		}
		else if(loc->expo<temp->expo)
		{
			insert(&start3,temp->coef,temp->expo);
			temp=temp->link;
		}
		else 
		{
		    m=loc->coef+temp->coef;
		    insert(&start3,m,temp->expo);
			loc=loc->link;
			temp=temp->link;
		}
	}
	 while(loc->link!=NULL && temp->link==NULL)
    {
    	if(loc->expo==temp->expo)
    	{
    		insert(&start3,temp->coef+loc->coef,temp->expo);
    		loc=loc->link;
		}
		else
		{
				insert(&start3,loc->coef,loc->expo);
				loc=loc->link;
		}
	}
	while(loc->link==NULL && temp->link!=NULL)
	{
		if(temp->expo==loc->expo)
		{
			insert(&start3,temp->coef+loc->coef,temp->expo);
			temp=temp->link;
		}
		else
		{
			insert(&start3,temp->coef,temp->expo);
			temp=temp->link;
		}
	}
	if(temp->expo==loc->expo)
	insert(&start3,temp->coef+loc->coef,temp->expo);
	else if(temp->expo>loc->expo)
	{
	insert(&start3,temp->coef,temp->expo);
		insert(&start3,loc->coef,loc->expo);
	}
	else
	{
	insert(&start3,loc->coef,loc->expo);
	insert(&start3,temp->coef,temp->expo);

    }
}
void main()
{
	int a,b,t1,t2,i;
	printf("enter the number of terms of first polynomial :   ");
	scanf("%d",&a);
	printf("***first polynomial***\n");
	for(i=0;i<a;i++)
	{
		printf("enter %d coefficient:   ",i);
		scanf("%d",&t1);
		printf("enter %d exponent:   ",i);
		scanf("%d",&t2);
		insert(&start,t1,t2);
		
	}
	printf("the first polynomial is   ");
   	display(start);
   	printf("\nenter the number of terms of second polynomial:   ");
	scanf("%d",&b);
	printf("\n***second polynomial***\n");
	for(i=0;i<b;i++)
	{
		printf("enter %d coefficient:    ",i);
		scanf("%d",&t1);
		printf("enter %d exponent:   ",i);
		scanf("%d",&t2);
	    insert(&start2,t1,t2);
	}
	printf("the second polynomial is     ");
	display(start2);
	sum(start,start2);
	printf("\n***sum polynomial***\n");
    display(start3);
}