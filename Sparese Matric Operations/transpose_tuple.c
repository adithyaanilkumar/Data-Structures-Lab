#include <stdio.h>
struct tupple{
    int row;
    int column;
    int value;
};

void output(int n, int m,int arr[][100], int transpose){
    printf("entered matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(transpose==0)
                printf("%d ",arr[i][j]);
            else
                printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
}

  
void output_tupple(struct tupple arr[],int non_zero, int transpose){
    printf("Row     Column      Value\n");
    for(int i=0;i<=non_zero;i++){
    if(transpose==0)
        printf("%d      %d          %d \n",arr[i].row,arr[i].column,arr[i].value);
    else
        printf("%d      %d          %d \n",arr[i].column,arr[i].row,arr[i].value);
    }
}

void transpose(struct tupple arr[],struct tupple b2[],int non_zero)
{
	//struct tupple b2[100];
	b2[0].row=arr[0].column;
	b2[0].column=arr[0].row;
	b2[0].value=arr[0].value;
	int k=1;
	int n=arr[0].value;
	
	for(int i=0;i<arr[0].column;i++)
		for(int j=1;j<=n;j++)
			//if a column number of current triple==i then insert the current triple in b2
			if(i==arr[j].column)
			{
				b2[k].row=i;
				b2[k].column=arr[j].row;
				b2[k].value=arr[j].value;
				k++;
			}
    //arr=b2;
    //printf("inside transpose \n");
    //output_tupple(b2,b2[0].value,0);
    //return b2;
} 

void convert_tupple(int n1, int n2, int arr[100][100],struct tupple a_func[100], int non_zero){
    int indext =1;
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++){
            if(arr[i][j]!=0){
                a_func[indext].row = i;
                a_func[indext].column = j;
                a_func[indext].value = arr[i][j];
                indext++;
            }
        }

    a_func[0].value= non_zero;
    printf("tupple form of the matrix is: \n");
    output_tupple(a_func,non_zero,0);
    
}



int main()
{   struct tupple a[100],b[100];
    int arr[100][100], arr2[100][100];
    int n1=0,n2=0,i=0,non_zero_a=0,non_zero_b=0;
    int n3=0,n4=0;
    printf("enter no of rows of matrix 1\n");
    scanf("%d",&n1);
    printf("enter no of colums of matrix 1\n");
    scanf("%d",&n2);
    a[0].row=n1;
    a[0].column=n2;
    printf("enter array 1 rowise \n");
    for(i=0;i<n1;i++)
        for(int j=0;j<n2;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0)
                non_zero_a++;
        }
    output(n1,n2,arr,0);
    convert_tupple(n1,n2,arr,a,non_zero_a);
    struct tupple k[100];
    printf("the transpose of the ");
    output(n1,n2,arr,1);
    transpose(a,k,non_zero_a);
    output_tupple(k,non_zero_a,0);
}