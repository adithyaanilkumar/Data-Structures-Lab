#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef;
	int exp;
	struct node *link;
}*start=NULL,*start2=NULL,*start3=NULL;
void insert(struct node **p,int m,int n)
{
	struct node *loc;
	struct node *newnode=malloc(sizeof(struct node));
	newnode->coef=m;
	newnode->exp=n;
	newnode->link=NULL;
	loc=(*p);
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
void display(struct node *p)
{  
	struct node *loc;
	loc=p;
	
	while(loc->link!=NULL)
	{
		printf("%dx^%d +",loc->coef ,loc->exp);
		loc=loc->link;
	}
	printf("%dx^%d ",loc->coef ,loc->exp);
	
}
void multiply(int a,int b)
{
	int i,j;
	struct node *loc;
	struct node *temp;
	loc=start;
	i=0;
	while(i<a)
	{   temp=start2;
	     j=0;
		while(j<b)
		{
			insert(&start3,(loc->coef*temp->coef),loc->exp+temp->exp);
			temp=temp->link;
			j++;
		}
		loc=loc->link;
		i++;
	}

	loc=start3;
	while(loc->link!=NULL)
	{ 
	    if(loc->exp==loc->link->exp)
	 {   loc->coef=loc->coef+loc->link->coef;
	    loc->link=loc->link->link;
	    
	 }
	 loc=loc->link;
	}

	
}
void main()
{
	int a,b,t1,t2,i;
	printf("enter the number of terms of first polynomial:  ");
	scanf("%d",&a);
	printf("***first polynomial***\n");
	for(i=0;i<a;i++)
	{
		printf("enter %d coefficient:  ",i);
		scanf("%d",&t1);
		printf("enter %d exponent:  ",i);
		scanf("%d",&t2);
		insert(&start,t1,t2);
	}
	printf("the first polynomial is:    ");
	display(start);
	printf("\nenter the number of terms of second polynomial:   ");
	scanf("%d",&b);
	printf("\n*****second polynomial***\n");
	for(i=0;i<b;i++)
	{
		printf("enter %d coefficient:   ",i);
		scanf("%d",&t1);
		printf("enter %d exponent:  ",i);
		scanf("%d",&t2);
		insert(&start2,t1,t2);
	}
	printf("the second polynomial is:    ");
	display(start2);
	printf("\n*****POLYNOMIAL AFTER MULTIPLICATION***\n");
	multiply(a,b);
	display(start3);
}