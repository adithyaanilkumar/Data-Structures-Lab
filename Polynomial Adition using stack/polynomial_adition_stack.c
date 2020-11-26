#include<stdio.h>
struct polynomial
{
	int coeff;
	int exp;
}poly[100];
int main()
{
	int t1,t2,i,j,k,p;
	printf("********************\n");
	printf("enter the number of terms for first polynomial\n");
	scanf("%d",&t1);
	for(i=0;i<t1;i++)
	{
		printf("enter term %d: ",i);
		scanf("%d",&poly[i].coeff);
		printf("enter the corresponding exponent for %d term: ",i);
		scanf("%d",&poly[i].exp);
	}
	printf("********************\n");
	printf("enter the number of terms for second polynomial\n");
	scanf("%d",&t2);
	for(i=t1;i<t1+t2;i++)
	{
		printf("enter term %d: ",i);
		scanf("%d",&poly[i].coeff);
		printf("enter the corresponding exponent for %d term: ",i);
		scanf("%d",&poly[i].exp);
	}
	printf("********************\n");
	k=t1+t2;i=0;j=t1;
    while(i<t1 && j<t1+t2)
    {
	       if(poly[i].exp>poly[j].exp)
			{
				poly[k].coeff=poly[i].coeff;
				poly[k].exp=poly[i].exp;
				k++;
				i++;
			}
			else if(poly[i].exp<poly[j].exp)
			{
				poly[k].coeff=poly[j].coeff;
				poly[k].exp=poly[j].exp;
				k++;
				j++;
			}
			else
			{
				poly[k].coeff=poly[i].coeff+poly[j].coeff;
				poly[k].exp=poly[j].exp;
				k++;
				i++;
				j++;
			}
		
	}
	while(i<t1)
    {
    	poly[k].coeff=poly[i].coeff;
		poly[k].exp=poly[i].exp;
		k++;
		i++;
	}
	while(j<t1+t2)
	{
		poly[k].coeff=poly[j].coeff;
		poly[k].exp=poly[j].exp;
		k++;
		j++;
	}
	printf("the sum of the 2 polynomials \n");
	printf("%dx^(%d)",poly[t1+t2].coeff,poly[t1+t2].exp);
	for(p=t1+t2+1;p<k;p++)
	{
		printf("+ %dx^(%d)",poly[p].coeff,poly[p].exp);
		
	}
	
}