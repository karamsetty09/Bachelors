#include<stdio.h>
#include<malloc.h>
typedef struct node* list;
typedef list position;
struct node
{
        int element;
        position next;
        position prev;
};
list create();
void display(list l);
position find(list l,int x);
void insert(list l,int x);
void delete(list l,int x);
void sort(list l);
list doublemerge(list l1,list l2);
void reverse(list l);
void exit(int x);
void main()
{
        list l,l1,l2,l3;
        int x,ch=0;
        printf("\n\t 1.create \n\t 2.insert \n\t 3.delete \n\t 4.reverse \n\t 5.display \n\t 6.sort \n\t 7.merge \n\t 8.exit");
        while(1)
        {
                printf("\n\t Enter ur option:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: l=create();
                                break;
                        case 2: printf("\n\t Enter the value to insert:");
                                scanf("%d",&x);
                                insert(l,x);
                                break;
                        case 3: printf("\n\t Enter the num to delete:");
                                scanf("%d",&x);
                                delete(l,x);
                                break;
                        case 4: reverse(l);
                                break;
                        case 5: display(l);
                                break;
 case 6: sort(l);
                                break;
                        case 7: printf("\n\t Enter first list in order:");
                                l1=create();
                                printf("\n\t Enter second list in order:");
                                l2=create();
                                l3=doublemerge(l1,l2);
                                printf("\n\t After merging:");
                                display(l3);
                                break;
                        case 8: exit(0);
                                break;
                        default : printf("\n\t Invalid option...!!!");
                }
        }
}
list create()
{
        list l,temp,newnode;
        int x;
        l=(struct node*)malloc(sizeof(struct node));
        l->element=0;
        l->next=NULL;
        l->prev=NULL;
        temp=l;
        printf("\n\t Enter value of x:");
        scanf("%d",&x);
        while(x!=0)
        {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->element=x;
                newnode->next=NULL;
                temp->next=newnode;
                newnode->prev=temp;
                temp=temp->next;
                printf("\n\t Enter the value:");
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
                printf("\n\t %d->",temp->element);
                temp=temp->next;
        }
        printf("\b\b");
}
position find(list l,int x)
{
        list temp;
        temp=l->next;
        while((temp->element!=x)&&(temp!=NULL))
                temp=temp->next;
        return temp;
}
void insert(list l,int x)
{
        list newnode,p;
        int item;
        printf("\n\t Enter the element after which u want to insert:");
        scanf("%d",&item);
        p=find(l,item);
        newnode=malloc(sizeof(struct node));
        newnode->element=x;
        newnode->next=p->next;
        newnode->prev=p;
        p->next->prev=newnode;
        p->next=newnode;
}
void delete(list l,int x)
{
        position p;
        p=find(l,x);
        p->next->prev=p->prev;
        p->prev->next=p->next;
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
list doublemerge(list l1,list l2)
{
        list t1,t2,t3,l3,newnode;
        t1=t1->next;
        t2=t2->next;
        l3=(struct node*)malloc(sizeof(struct node));
        l3->element=0;
        l3->next=NULL;
        l3->prev=NULL;
        t3=l3;
        while(t1&&t2)
        {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->prev=t3;
                t3->next=newnode;
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
                if(next==NULL)
                        curr->prev=l;
                else
                        curr->prev=next;
                prev=curr;
                curr=next;
        }
}

