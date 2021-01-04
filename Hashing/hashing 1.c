#include<stdio.h>
#include<stdlib.h>

#define size 13

int h[size]={0};


void insert(int el)
{   
    int key = el % size;
    
    if(h[key] == 0)
    {   
        h[key] = el;
        printf("%d inserted at hash[%d]  ", el,key);
    }
    else
    {   
         int k = key;
    do
    {
        k = (k+1)%size;    //collision resolution
        if(h[k] == 0)
        {
            h[k] = el;
            printf("%d inserted at hash[%d]  ", el,k);
            return;
        }
    }while(k!=key);
    }
}


void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("hash[%d] = %d\n",i,h[i]);
}

int main()
{int el,count = 0;
    char c = 'y';
    printf("Size of Hash Table = %d",size);
    do
    {
        count+=1;   //can store upto 13 elements
        if(count > size)
        {
            printf("\nHash Table is full!");
            print();
            exit(0);
        }
        printf("\nEnter the element to be stored in the hash table:  ");
        scanf("%d",&el);
        insert(el);
        printf("\nDo you want to continue storing elements?(y/n): ");
        scanf(" %c",&c);
        if(c == 'n')
            print();
    }while(c=='y');
}