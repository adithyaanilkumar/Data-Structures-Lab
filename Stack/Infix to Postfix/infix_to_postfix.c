#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 10
char post_stack[100], op_stack[100];
int top_post = -1, top_op = -1;


int isempty(int *top){
    if(*top==-1)
        return 1;
    else 
        return 0;
}

int peek(char stack[], int *top){
    if(isempty(top)){
        printf("Empty Stack \n");
        return 0;
    } 
    return(stack[*top]);
}

int pop(char stack[], int *top){
    if(isempty(top)){
        printf("Empty Stack \n");
        return 0;
    }
    int data = stack[*top];
    --*top;
    return(data);
}

void  push(int data, char stack[],int *top){
    ++*top;
    stack[*top]= data;
}
void view(char stack[], int *top){
    if(isempty(top)){
        printf("Empty Stack \n");
        return;
    }
    printf("stack is: \n");
    for(int i=0;i<=*top;i++){
        printf("%d ",stack[i]);
    }
}

int Precedence(char symbol){
   switch (symbol)
    {
    case '$':
        return 4;
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}
int isOpeningBracket(char symbol){
    return  symbol == '('?1:0;
}
int isClosingBracket(char symbol){
    return  symbol == ')'?1:0;
}
int main(void) {
    char string[100];
    printf("Enter the infix string \n");
    scanf("%s",string);
    printf("The entered Infix expression %s \n",string);
    for(int i=0;i<= strlen(string);i++){
        char symbol = string[i];
        if(isalpha(symbol))
            push(symbol,post_stack,&top_post);
        else if(!isOpeningBracket(symbol) && !isClosingBracket(symbol)){
            while(!isempty(&top_op) && !isOpeningBracket(peek(op_stack, &top_op)) && Precedence(symbol)<= Precedence(peek(op_stack, &top_op))){
                char popped = pop(op_stack,&top_op);
                push(popped, post_stack, &top_post);
            }
            push(symbol,op_stack,&top_op);
        }
        else if(isOpeningBracket(symbol))
            push(symbol, op_stack, &top_op);
        else if(isClosingBracket(symbol)){
            while(!isempty(&top_op) && !isOpeningBracket(peek(op_stack, &top_op) ) ){
                char popped = pop(op_stack,&top_op);
                push(popped, post_stack, &top_post);
            }
            pop(op_stack,&top_op);
        }
    }
    while(!isempty(&top_op)){
        char popped = pop(op_stack,&top_op);
        push(popped, post_stack, &top_post);
    }
    printf("The Postix expression is %s \n",post_stack);
}