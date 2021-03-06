#include<stdio.h>
#include<malloc.h>
typedef struct node* list;
typedef list position;
struct node
{
        int element;
        position next;
};
list create();
void display(list l);
position find(list l,int x);
void insert(list l,int x);
void deletion(list l,int x);
position findprevious(list l,int x);
void reverse(list l);
list merge(list l1,list l2);
void sort(list l);
void exit(int x);
void main()
{
        list l,l1,l2,l3;
        int x,ch;
        printf("\n\t 1.create \n\t 2.insert list \n\t 3.delete element \n\t 4.reverse list \n\t 5.display \n\t 6.sort list \n\t 7.merge list \n\t 8.exit");
        while(1)
        {
                printf("\n\t Enter ur choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: l=create();
                                break;
                        case 2: printf("\n\t Enter the value to insert:");
                                scanf("%d",&x);
                                insert(l,x);
                                break;
                        case 3: printf("\n\t Enter number to delete:");
                                scanf("%d",&x);
                                deletion(l,x);
                                break;
                        case 4: reverse(l);
                                break;
                        case 5: display(l);
                                break;
 case 6: sort(l);
                                break;
                        case 7: printf("\n\t Enter the first list in ascending order:");
                                l1=create();
                                printf("\n\t Enter the second list in ascending order:");
                                l2=create();
                                l3=merge(l1,l2);
                                printf("\n\t After merging lists:");
                                display(l3);
                                break;
                        case 8: exit(0);
                                break;
                        default : printf("\n\t Invalid option....!!!!!");
                }
        }
}
list create()
{
        int x;
        list temp,l;
        l=(struct node*)malloc(sizeof(struct node));
        l->element=0;
        l->next=NULL;
        temp=l;
        printf("\n\t Enter value for x:");
        scanf("%d",&x);
        while(x!=0)
        {
                temp->next=(struct node*)malloc(sizeof(struct node));
                temp=temp->next;
                temp->element=x;
                temp->next=NULL;
                printf("\n\t Enter the value of x:");
                scanf("%d",&x);
        }
        return(l);
}
void display(list l)
{
        list temp;
        temp=l->next;
        while(temp)
        {
                printf("\n\t %d ->",temp->element);
                temp=temp->next;
  }
        printf("\b\b");
}
position find(list l,int x)
{
        list temp;
        temp=l->next;
        while((temp->element!=x)&&(temp->next!=NULL))
                temp=temp->next;
        return(temp);
}
void insert(list l,int x)
{
        position p;
        list temp;
        int item;
        p=find(l,x);
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\n\t Enter the value of x:");
        scanf("%d",&item);
        temp->element=item;
        temp->next=p->next;
        p->next=temp;
}
void deletion(list l,int x)
{
        position p;
        p=findprevious(l,x);
        p->next=p->next->next;
        return;
}
position findprevious(list l,int x)
{
        list temp;
        temp=l->next;
        while((temp->next->element!=x)&&(temp->next!=NULL))
                temp=temp->next;
        return(temp);
}
void reverse(list l)
{
        list curr,prev,next;
        prev=NULL;
        curr=l->next;
 while(curr)
        {
                l->next=curr;
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
        }
}
list merge(list l1,list l2)
{
        list t1,t2,t3,l3;
        t1=l1->next;
        t2=l2->next;
        l3=(struct node*)malloc(sizeof(struct node));
        l3->element=0;
        l3->next=NULL;
        t3=l3;
        while(l1&&t2)
        {
                t3->next=(struct node*)malloc(sizeof(struct node));
                t3=t3->next;
                if(t1->element<t2->element)
                {
                        t3->element=t1->element;
                        t1=t1->next;
                }
                else
                {
                        t3->element=t2->element;
                        t2=t2->next;
                }
                t3->next=NULL;
        }
        if(t1!=NULL)
                t3->next=t1;
        if(t2!=NULL)
                t3->next=t2;
        return(l3);
}
void sort(list l)
{
        list min,t1,t2;
        int temp;
        t1=l->next;
 while(t1)
        {
                min=t1;
                t2=t1->next;
                while(t2)
                {
                        if(t2->element<min->element)
                                min=t2;
                        t2=t2->next;
                }
                if(min!=t1)
                {
                        temp=t1->element;
                        t1->element=min->element;
                        min->element=temp;
                }
                t1=t1->next;
        }
        return;
}
