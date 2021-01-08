#include <stdio.h>
int a[50];
int partition( int lb, int ub)
{
    int temp,pivot = a[lb];
    int up = ub, down = lb;
    while(down<up)
    {
        while(a[down]<=pivot && down<ub)
            down++;
        while(a[up]>pivot)
            up--;
        if(down<up)
        {
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }
    a[lb] = a[up];
    a[up] = pivot;
    return up;
}
void quickSort(int lb, int ub)
{
    int j;
    if(lb>=ub)
        return;
    j = partition(lb,ub);
    quickSort(lb,j-1);
    quickSort(j+1,ub);
    return;
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
    quickSort(0,n-1);
    printf("\nThe Array Sorted using quick Sort is :\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}