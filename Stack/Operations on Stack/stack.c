#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int a[100];
int top = -1;


int isempty(){
    if(top==-1)
        return 1;
    else 
        return 0;
}

int isfull(){
    if(top>=-MAX -1)
        return 1;
    else 
        return 0;
} 
int peek(){
    if(isempty()){
        printf("Empty Stack \n");
        return 0;
    } 
    return(a[top]);
}

int pop(){
    if(isempty()){
        printf("Empty Stack \n");
        return 0;
    }
    int data = a[top];
    top--;
    return(data);
}

void  push(int data){
    if(isfull()){
        printf("Stack Full \n");
        return;
    }
    top++;
    a[top]= data;
}
void view(){
    if(isempty()){
        printf("Empty Stack \n");
        return;
    }
    printf("stack is: \n");
    for(int i=0;i<=top;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(void) {
    int option;
    int data;
    do{
        printf("MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. View Stack \n");
        printf("Enter your option: \n");
        scanf("%d",&option);
        switch(option){
            case 1:{
                    printf("enter data to be pushed: \n");
                    scanf("%d",&data);
                    push(data);
                    printf("Pushed %d \n", data);
                    getchar();
                    break;
            }
            case 2:{
                    data = pop();
                    printf("Popped %d \n", data);
                    getchar();
                    break;
            }
            case 3:{
                    data = peek();
                    printf("The top most element is %d \n", data);
                    getchar();
                    break;
            }
            case 4:{
                    view();
                    getchar();
                    break;
            }
            default: printf("invalid input \n");     
        }
        printf("Press any key to continue \n");
        getchar();
        system("clear");
    }while(option!=5);
  return 0;
}