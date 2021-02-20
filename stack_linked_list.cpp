#include<stdio.h>
#include<stdlib.h>
struct node
{
        int into;
        struct node *link;
}
*top=NULL;
void push();
void pop();
void display();
int main()
{
        int ch;
        printf ("\n\t\t MENU  \n\t 1.Push element \n\t 2. Pop element\n\t 3.Display element \n\t 4.Exit");
        while(1)
        {
                printf("\n Enter ur choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: push();
                                break;
                        case 2: pop();
                                break;
                        case 3: display();
                                break;
                        case 4: exit(0);
                                break;
                        default: printf(" \n\t Invalid Option");
                }
        }
}
void push()
{
        int n;
        struct node*tmp;
        tmp=(struct node*)malloc(sizeof(struct node));
        printf("\n\t Enter  the item :");
        scanf("%d",&n);
        tmp->into=n;
        tmp->link=top;
        top=tmp;
        return;

}
void pop()
{
        struct node*tmp;
        tmp=(struct node*)malloc(sizeof(struct node));
        if(top==NULL)
                printf("\n\t stack is empty");
        else
        {
                tmp=top;
                printf("\n\t The popped element is %d ",tmp->into);
                top=top->link;
                free(tmp);
        }
}
void display()
{
        struct node*ptr;
        ptr=top;
        if(top==NULL)
                printf("\n stack is empty");
        else
                printf("\n\t Stack elements are :");
        while(ptr!=NULL)
        {
                printf("\n\t %d ",ptr->into);
                ptr=ptr->link;
        }
}

