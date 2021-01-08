#include <stdio.h>
int a[50];
void insertionsort(int n)
{int temp,j;
 for(int i=1; i<n; i++)
   {
    temp = a[i];
    j = i-1;
    while(temp<a[j] && j>=0)
     {
       a[j+1] = a[j];
       j = j-1;
     }
    a[j+1] = temp;
    }
  printf("\nAfter sort \n ");
  for(int i=0;i<n;i++)
      printf("%d ",a[i]);  
}

void main()
{
 
  int n;
  printf("enter the number of element you enter:   ");
  scanf("%d",&n);
  printf("enter the elements\n ");
  for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
  printf("before sort \n ");
  for(int i=0;i<n;i++)
      printf("%d ",a[i]);
    insertionsort(n);
  
}