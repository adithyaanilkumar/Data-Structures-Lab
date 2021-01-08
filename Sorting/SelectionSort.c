#include <stdio.h>
int a[50];
void selectsort(int n)
{   int small,temp ;
     for(int i=0;i<n;i++)
    {
        small = i;
        for(int j = i+1;j<n;j++)
            if(a[j]<a[small])
                small = j;   
        temp = a[i];
        a[i] = a[small];
        a[small] = temp;
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
    selectsort(n);
  
}