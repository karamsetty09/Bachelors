#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node*queue;
struct node
{
        int element;
        struct node*next;
};
queue rear=NULL;
queue front=NULL;
void insert(int x);
int delete();
void display();
void exit(int x);
void main()
{
        int x,ch;
        printf("\n\t\t Menu \n\t 1.Insert \n\t 2.Delete \n\t 3.Display \n\t 4.Exit");
        while(1)
        {
                printf("\n\t Enter ur choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("\n\t Enter the value to insert :");
                                scanf("%d",&x);
                                insert(x);
                                break;
                        case 2: x=delete();
                                if(x!=1)
                                        printf("\n\t The deleted value is :%d",x);
                                break;
                        case 3: display();
                                break;
                        case 4: exit(0);
                                break;
                        default : printf("\n\t Invalid option !!!!!");
                                  break;
                }
        }
}
void insert(int x)
{
        queue newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
        newnode->element=x;
        newnode->next=NULL;
        if(rear==NULL)
                front=newnode;
        else
                rear->next=newnode;
        rear=newnode;
}
int delete()
{
        int x;
        if(front==NULL)
        {
                printf("\n\t Under flow ");
                return(-1);
        }
        x=front->element;
        front=front->next;
        if(front==NULL)
                rear=NULL;
        return(x);
}
void display()
{
        queue nd;
        if(front==NULL)
        {
                printf("\n\t Queue is empty ");
                return;
        }
        else
                printf("\n\t Queue nodes are:\n\t");
        nd=front;
        while(nd!=NULL)
        {
                printf("%d",nd->element);
                nd=nd->next;
        }
}

