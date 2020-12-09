#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int a[100];
int front=-1;
int rear=-1;


int isempty(){
    if( front==-1 || rear==-1 )
        return 1;
    else 
        return 0;
}

int isfull(){
    if((front == 0 && rear == MAX-1) || (front == rear+1))
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
        printf("Empty queue \n");
        return 0;
    }
    int data = a[front];
    if(front == rear)
    {
        front = -1;
        rear=-1;
    }
    else
    {
        if(front == MAX-1)
            front = 0;
        else
        front++;
    }
    return(data);
}

void  enqueue(int data){
    if(isfull()){
        printf("queue Full \n");
        return;
    }
    
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else
    rear =  (rear % MAX) +1;
    a[rear] = data ;
}
void view(){
    if(isempty()){
        printf("Empty queue \n");
        return;
    }
    int front_pos = front,rear_pos = rear;
    if( front_pos <= rear_pos )
        while(front_pos <= rear_pos){
            printf("%d ",a[front_pos]);
            front_pos++;
        }
    else{
        while(front_pos <= MAX-1){
            printf("%d ",a[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {
            printf("%d ",a[front_pos]);
            front_pos++;
        }
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