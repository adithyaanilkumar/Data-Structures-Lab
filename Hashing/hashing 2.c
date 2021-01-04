#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 26
char hash1[SIZE][30],hash2[SIZE][30],Word[30];
void insert(char elem[30])
{   //linearprobing
    int index,flag=0;
    index = ((tolower(elem[0]) - 97) % SIZE);
    
        if(hash1[index][0]==NULL)
        {
            strcpy(hash1[index],elem);
        }
        else
        {  int i = (index+1) % SIZE;
            while(i!=index)                                                                        //while loop for linear probing
            {
                if(hash1[i][0]==NULL)
                {
                    strcpy(hash1[i],elem);
                     break;
                } 
                i = (i+1) % SIZE;
            }
        }
        //quadraticprobing
        if(hash2[index][0]==NULL)
        {
            strcpy(hash2[index],elem);
         }
        else
        { int i = (index+1) % SIZE;
            for(int j=2;i!=index;j++)                                                              //for loop for quadratic probing
            {
                if(hash2[i][0]==NULL)
                {
                    strcpy(hash2[i],elem);
                    break;
                } 
                i = (index+j*j) % SIZE;
            }
            
        }
    }
void print(char hash[][30])
{     
    for (int i = 0; i < SIZE; i++)
    {
        printf("(%d:", i);
        
        if(hash[i][0]==NULL)
            printf("-), ");
        else
            printf("%s), ",hash[i]);
    }    
}
void search()
{  int flag=0,count=1;
   int  index = ((tolower(Word[0]) - 97) % SIZE);
   if(strcmp(hash1[index],Word)==0)
    {
        printf("\nWord found at index: %d",index);
        printf("\nNo. of Key Comparisons made: %d",count);
        flag=1;   
    }
    else
    { int  i = (index+1) % SIZE;
      while(i!=index)                                                                              //while loop for linear probing
      {
        ++count;
        if(strcmp(hash1[i],Word)==0)
        {
            printf("\nWord found at index: %d",i);
            printf("\nNo. of Key Comparisons made: %d",count);
            flag = 1;
            break;
        } 
        i = (i+1) % SIZE;
      }

     if(flag==0)
     {
            printf("\nWord not found.");
            
     }}
     //quadraticprobing
     count=1,flag=0;
    if(strcmp(hash2[index],Word)==0)
    {
        printf("\nWord found at index: %d",index);
        printf("\nNo. of Key Comparisons made: %d",count);
         flag=1;    
    }
    else
    {int i = (index+1) % SIZE;  
      for(int j=2;i!=index;j++)                                                                     //for loop for quadratic probing
      {
        ++count;
        if(strcmp(hash2[i],Word)==0)
        {
            printf("\nWord found at index: %d",i);
            printf("\nNo. of Key Comparisons made: %d",count);
            flag = 1;
            break;
        } 
        i = (index+j*j) % SIZE;
      }

     if(flag==0)
     {
            printf("\nWord not found.");
     }}}

void main()
{
    int N = 0;
    char elem[30];                                                                                     
    printf("\nEnter the Number of words: ");                                                       
    scanf("%d",&N);
        printf("Enter the Text:");
    for(int i=0;i<N;i++)
    {
        scanf("%s", elem);
        insert(elem);
    }
    printf("\nhash1(linearprobing):  \n");
    print(hash1);
    printf("\nhash2(quadraticprobing):  \n");
    print(hash2);
    printf("\nEnter the word to searched: ");
    scanf("%s", Word);
    search();
}