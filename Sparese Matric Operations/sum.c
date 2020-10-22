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

void sum_tupple(struct tupple first[],struct tupple second[],int count_1, int count_2){
    int non_zero;
    struct tupple sum[100];
    sum[0].row = ((first[0].row > second[0].row) ? first[0].row : second[0].row);
    sum[0].column = ((first[0].column > second[0].column )? first[0].column : second[0].column);
    int first_pos=1,second_pos=1,sum_pos=1;
    while( first_pos<=count_1 && second_pos<=count_2 ){
        if(first[first_pos].row<second[second_pos].row || (first[first_pos].row == second[second_pos].row && first[first_pos].column < second[second_pos].column )){
            sum[sum_pos].row = first[first_pos].row;
            sum[sum_pos].column = first[first_pos].column;
            sum[sum_pos].value = first[first_pos].value;
            first_pos++; 
            sum_pos++;
        }
        else
        if(first[first_pos].row>second[second_pos].row || (first[first_pos].row == second[second_pos].row && first[first_pos].column > second[second_pos].column )){
            sum[sum_pos].row = second[second_pos].row;
            sum[sum_pos].column = second[second_pos].column;
            sum[sum_pos].value = second[second_pos].value;
            second_pos++; 
            sum_pos++;
        }
        else{
            sum[sum_pos].row = second[second_pos].row;
            sum[sum_pos].column = second[second_pos].column;
            sum[sum_pos].value = second[second_pos].value +  first[first_pos].value;
            sum_pos ++;
            first_pos ++;
            second_pos ++;
        }
    }
    while(first_pos<=count_1){
        sum[sum_pos].row = first[first_pos].row;
        sum[sum_pos].column = first[first_pos].column;
        sum[sum_pos].value = first[first_pos].value;
        first_pos++; 
        sum_pos++;
    }
    while(second_pos<=count_2){
        sum[sum_pos].row = second[second_pos].row;
        sum[sum_pos].column = second[second_pos].column;
        sum[sum_pos].value = second[second_pos].value;
        second_pos++; 
        sum_pos++;
    }
    sum[0].value = sum_pos-1;
    non_zero = sum_pos;
    printf("sum of matrix in tupple form is: \n");
    output_tupple(sum, non_zero-1, 0);
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
    //output(n1,n2,arr,0);
    convert_tupple(n1,n2,arr,a,non_zero_a);

    printf("enter no of rows of matrix 2\n");
    scanf("%d",&n3);
    printf("enter no of colums of matrix 2\n");
    scanf("%d",&n4);
    b[0].row=n3;
    b[0].column=n4;
    printf("enter array 2 rowise \n");
    for(i=0;i<n3;i++)
        for(int j=0;j<n4;j++){
            scanf("%d",&arr2[i][j]);
            if(arr[i][j]!=0)
                non_zero_b++;
        }
    //output(n3,n4,arr2,0);
    convert_tupple(n3,n4,arr2,b,non_zero_b);
    sum_tupple(a,b,non_zero_a,non_zero_b);

}