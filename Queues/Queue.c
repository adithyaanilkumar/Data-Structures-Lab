#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int a[100];
int front=-1;
int rear=-1;


int isempty(){
    if( front==-1 || rear==-1 || front>rear )
        return 1;
    else 
        return 0;
}

int isfull(){
    if(rear>=MAX -1)
        return 1;
    else 
        return 0;
} 
int peek(){
    if(isempty()){
        printf("Empty Queue \n");
        return 0;
    } 
    return(a[front]);
}

int dequeue(){
    if(isempty()){
        printf("Empty Stack \n");
        return 0;
    }
    int data = a[front];
    front++;
    return(data);
}

void  enqueue(int data){
    if(isfull()){
        printf("Stack Full \n");
        return;
    }
    if(front==-1){
        front++;
        rear++;
    }
    else
    rear++;
    a[rear]= data;
}
void view(){
    if(isempty()){
        printf("Empty Stack \n");
        return;
    }
    printf("Queue is: \n");
    for(int i=front;i<=rear;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(void) {
    int option;
    int data;
    do{
        printf("MENU\n");
        printf("1. En Queue\n");
        printf("2. De Quque\n");
        printf("3. Peek\n");
        printf("4. View Queue \n");
        printf("Enter your option: \n");
        scanf("%d",&option);
        switch(option){
            case 1:{
                    printf("enter data to be pushed: \n");
                    scanf("%d",&data);
                    enqueue(data);
                    printf("enqueued %d \n", data);
                    getchar();
                    break;
            } 
            case 2:{
                    data = dequeue();
                    printf("dequeued %d \n", data);
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