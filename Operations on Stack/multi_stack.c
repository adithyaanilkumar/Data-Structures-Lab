#include<stdio.h>
#define X_MAX 5
#define Y_MAX 5
int top_x=-1;
int top_y=10;


void push_x(int *stack){
	int data;
	if(top_x>=(X_MAX-1))
	{	
        printf("\n OverFlow ");
		return;
	}
	else{	
        printf("\n Enter The data to be push");
		scanf("%d",&data);
		top_x++;
		stack[top_x]=data;
	}
}

void push_y(int *stack){
	int data;
	if(top_y<=(Y_MAX)){
		printf("\n OverFlow");
		return;
	}
	else{
		printf("\n\nEnter The data To Push ");
		scanf("%d",&data);
		top_y--;
		stack[top_y]=data;
	}
}

void pop_x(int *stack){	
    if(top_x==-1){
		printf("\n Stack X is Underflow ");
		return;
	}
	else{
	  printf("\n Item Poped from stack X is:%d",stack[top_x]);
	  top_x--;
	}
}

void pop_y(int *stack){	
    if(top_y==10){
        printf("\n Stack y is Underflow ");
	    return;
	}
	else{ 
        printf(" \n Item Poped from stack Y is:%d",stack[top_y]);
	    top_y++;
	}
}

void display_x(int *stack){
	int i;
	if(top_x==-1){
		printf("\n Stack X is Empty ");
		return;
	}
	else{ 
        for(i=top_x;i>=0;i--)
	    {
            printf("%d,",stack[i]);
        }
	        printf("\n");
	}
}

void display_y(int *stack){
	int i;
	if(top_y==10){
        printf("\n Stack Y is Empty ");
		return;
    }
	else
	{
        for(i=top_y;i<=9;i++){
		    printf("%d,",stack[i]);
	    }
	   printf("\n");
	}	
}

int main(){	
    int choice;
	char ch;
	int stack[X_MAX+Y_MAX];
    do{   
        printf("\n 1.Push X ");
        printf("\n 2.Push_Y ");
		printf("\n 3.Pop_X");
        printf("\n 4.Pop_Y");
		printf("\n 5.Display_X");
        printf("\n 6.Display_Y");
		printf("\n 7.Exit");
		printf("\n Enter Choice \n");
		scanf("%d",&choice);
		switch(choice){
			case 1: push_x(stack);
                    break;
			case 2: push_y(stack);
                    break;

			case 3: pop_x(stack);
                    break;
			case 4: pop_y(stack);
                    break;
			case 5: display_x(stack);
                    break;
			case 6: display_y(stack);
                    break;
			case 7: break;
			default: printf("\n Invalid Option..");
		}
	}while(choice!=7);
}
