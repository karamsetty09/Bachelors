#include<stdio.h>
#define max 50
int queue[max];
int rear = -1;
int front = -1;
void insert();
void del();
void display();
void main()
{
        int ch;
        do
        {
                printf("\n\t Menu \n\t 1.Insert \n\t 2.Delete \n\t 3.Display \n\t 4.exit ");
                printf("\n\tEnter your choice : ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1 :insert();
                                break;
                        case 2 :del();
                                break;
                        case 3:display();
                                break;
                        case 4:return;
                                break;
                        default:printf("\n\t Invalid option.....,,");
                }
                display();
        }while(ch<=3);
}
void insert()
{
        int item;
        if (rear==max-1)
                printf("Queue Overflow\n");
        else
        {
                if (front==-1)
                        front=0;
                printf("Enter the item to insert : ");
                scanf("%d", &item);
                rear=rear+1;
                queue[rear] = item ;
        }
}

void del()
{
        if (front == -1 || front > rear)
        {
                printf("\n\tQueue Underflow\n");
                return ;
        }
        else
        {
                printf("Element deleted from queue is : %d\n", queue[front]);
                front=front+1;
        }
}
void display()
{
        int i;
        if (front == -1)
                printf("Queue is empty\n");
        else
        {
                printf("Queue is :\n");
                for(i=front;i<= rear;i++)
                {
                        printf("%d ",queue[i]);
                        printf("\n");
                }
        }

}

