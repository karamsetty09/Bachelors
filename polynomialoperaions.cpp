#include<stdio.h>
#include<malloc.h>
struct poly
{
        int coeff;
        int exp;
        struct poly *next;
};
typedef struct poly *poly;
poly create();
void display(poly l);
poly polyadd(poly p1,poly p2);
poly polysub(poly p1,poly p2);
void main()
{
        poly p1,p2,p3,p4;
        printf("\n enter 1st polynomial:");
        p1=create();
        printf("\n enter 2nd polynomial:");
        p2=create();
        printf("\n polynomial addition is:");
        display(p1);
        display(p2);
        p3=polyadd(p1,p2);
        display(p3);
        printf("\n polynomial subtarction is:");
        p4=polysub(p1,p2);
        display(p4);
        return;
}
poly create()
{
        int coeff;
        int exp;
        poly temp,l;
        l=(struct poly*)malloc(sizeof(struct node*));
        l->coeff=0;
        l->exp=0;
        l->next=NULL;
        temp=l;
        printf("\n enter value of coeff and exp:");
        scanf("%d",&coeff);
        scanf("%d",&exp);
        while(coeff!=0)
        {
 temp->next=(struct poly*)malloc(sizeof(struct node*));
                temp=temp->next;
                temp->coeff=coeff;
                temp->exp=exp;
                temp->next=NULL;
                printf("\n enter the value of coeff,exp:");
                scanf("%d",&coeff);
                scanf("%d",&exp);
        }
        return(l);
}

void display(poly l)
{
        poly temp;
        temp=l->next;
        while(temp)
        {
                printf("%dx%d->",temp->coeff,temp->exp);
                temp=temp->next;
        }
}

poly polyadd(poly p1,poly p2)
{
        poly t1,t2,t3,p3;
        t1=p1->next;
        t2=p2->next;
        p3=(struct poly*)malloc(sizeof(struct poly));
        p3->coeff=0;
        p3->exp=0;
        t3=p3;
        while(t1 && t2)
        {
                t3->next=(struct poly*)malloc(sizeof(struct poly));
                t3=t3->next;
                if(t1->exp > t2->exp)
                {
                        t3->exp=t1->exp;
                        t3->coeff=t1->coeff;
                        t1=t1->next;
                }
                else if(t1->exp < t2->exp)
                {
                        t3->exp=t2->exp;
  t3->coeff=t2->coeff;
                        t2=t2->next;
                }
                else if(t1->exp==t2->exp)
                {
                        t3->coeff=t1->coeff + t2->coeff;
                        t3->exp=t2->exp;
                        t1=t1->next;
                        t2=t2->next;
                }
                t3->next=NULL;
        }
        if(t1!=NULL)
                t3->next=t1;
        if(t2!=NULL)
                t3->next=t2;
        return(p3);
}
poly polysub(poly p1,poly p2)
{
        poly p3,t1,t2,t3;
        t1=p1->next;
        t2=p2->next;
        p3=(struct poly*)malloc(sizeof(struct poly*));
        p3->coeff=p3->exp=0;
        t3=p3;
        while(t1&&t2)
        {
                t3->next=(struct poly*)malloc(sizeof(struct poly));
                t3=t3->next;
                if(t1->exp>t2->exp)
                {
                        t3->exp=t1->exp;
                        t3->coeff=t1->coeff;
                        t1=t1->next;
                }
                else if(t2->exp>t1->exp)
                {
                        t3->exp=t2->exp;
                        t3->coeff=t2->coeff;
                        t2=t2->next;
                }
                else
                {
                        t3->exp=t1->exp;
 t3->coeff=t1->coeff-t2->coeff;
                        t1=t1->next;
                        t2=t2->next;
                }
        }
        if(t1!=NULL)
                t3->next=t1;
        while(t2!=NULL)
        {
                t3->next=(struct poly*)malloc(sizeof(struct poly));
                t3->coeff=-(t2->coeff);
                t3->exp=t2->exp;
        }
        t3->next=NULL;
        return(p3);
