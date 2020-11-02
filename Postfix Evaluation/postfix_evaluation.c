#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

#define MAX 10
double operands[100];
int top_operand = -1;


int isempty(int *top){
    if(*top==-1)
        return 1;
    else 
        return 0;
}

double peek(double stack[], int *top){
    if(isempty(top)){
        printf("Empty Stack \n");
        return 0;
    } 
    return(stack[*top]);
}

double pop(double stack[], int *top){
    if(isempty(top)){
        printf("Empty Stack \n");
        return 0;
    }
    double data = stack[*top];
    --*top;
    return(data);
}

void  push(double data, double stack[],int *top){
    ++*top;
    stack[*top]= data;
}
void view(double stack[], int *top){
    if(isempty(top)){
        printf("Empty Stack \n");
        return;
    }
    printf("stack is: \n");
    for(int i=0;i<=*top;i++){
        printf("%f ",stack[i]);
    }
}

double operate(char symbol, double first, double second){
   switch (symbol)
    {
    case '^':
        return pow(first,second);
    case '/':
        return (first/second);
    case '*':
       return (first*second);
    case '+':
        return (first+second);
    case '-':
        return (first-second);
    default:
        return -1;
    }
}

int isOperator(char symbol){
    return  ( symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-' )?1:0;
}

int main(void) {
    char string[100];
    printf("Enter the Postfix expression \n");
    scanf("%s",string);
    printf("The entered Postfix expression %s \n",string);
    for(int i=0;i<strlen(string);i++){
        char symbol= string[i];
        if(isdigit(symbol)){
            push((symbol - '0'), operands, &top_operand);
        }
        else{
            double operand_1 = pop(operands, &top_operand);
            double operand_2 = pop(operands, &top_operand);
            double value = operate(symbol,operand_2,operand_1);
            push(value, operands, &top_operand);
        }
    }
    printf("The Postix expression is %f \n",pop(operands,&top_operand));
}