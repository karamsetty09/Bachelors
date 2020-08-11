#include<stdio.h>
#define max 5
int stack[max];
int i;
int top=-1;
void push();
void pop();
void display();
void main()
{
        int ch;
        do
        {
                printf("\n\t Menu \n\t 1.push \n\t 2.pop \n\t 3.Display \n\t 4.Exit ");
                printf("\n\t Enter your choice :");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: push();
                                break;
                        case 2: pop();
                                break;
                        case 3: display();
                                break;
                        default : printf("\n\t Invalid option....,,,");
                }
                display();
        }while(ch<=3);
}
void push()
{
        int item;
        if(top>=max-1)
                printf("\n\t stack is full ");
        else
        {
                printf("\n\t Enter the item to push :");
                scanf("%d",&item);
                stack[++top]=item;
        }
}
void pop()
{
        int item;
        if(top==-1)

   printf("\n\t stak is empty ");
        else
        {
                item=stack[top--];
                printf("\n\t %d is detected at top",item);
                printf("\n");
        }
}
void display()
{
        int i;
        if(top==-1)
                printf("\n\t Stack is empty ");
        else
        {
                printf("\n\t top :");
                for(i=top;i>=0;i--)
                {
                        printf("%d  ",stack[i]);
                        printf("\n");
                }
        }
}

