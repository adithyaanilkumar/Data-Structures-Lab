#include <stdio.h>
int a[50];
void merge(int lb, int mid, int ub)
{
    int k=0, l=lb, u=mid+1;
    int b[100];
    int n = ub-lb+1;
    while(l<mid+1 && u<ub+1)  //merging sublists
    {
        if(a[l]<a[u])
        {
            b[k] = a[l];
            l++;
            k++;
        }
        else
        {
            b[k] = a[u];
            k++;
            u++;
        }
    }
    while(l<mid+1)   //if elements in 1st sublist > 2nd sublist
    {               //we need to add these remaining elements into b[]
        b[k] = a[l];
        l++;
        k++;
    }
    while(u<ub+1)   //if elements in 2nd sublist < 1st sublist
    {              //we need to add these remaining elements into b[]
        b[k] = a[u];
        u++;
        k++;
    }
    l = lb;
    for(k=0; k<n; k++)  //copying sorted b[] into a[]
    {
        a[l] = b[k];
        l++;
    }
}
void mergeSort(int lb,int ub)
{
    if(lb==ub)
        return;
    else
    {
        int mid = (ub+lb)/2;
        mergeSort(lb,mid);
        mergeSort(mid+1,ub);
        merge(lb,mid,ub);
    }
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
    mergeSort(0,n-1);
    printf("\nThe Array Sorted  using Merge Sort is :\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}