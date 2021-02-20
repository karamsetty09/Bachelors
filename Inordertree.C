#include<conio.h>
#include<stdio.h>
typedef struct treenode *trptr;
struct treenode
{
trptr lptr;
int data;
trptr rptr;
};
int tos;
void push(trptr s[],trptr);
trptr pop(trptr s[]);
void recpreorder(trptr);
trptr insertbst(trptr,int);
void recpostorder(trptr);
void recinorder(trptr);
void nonrecpreorder(trptr);
void nonrecpostorder(trptr);
void nonrecinorder(trptr);
void main()
{
trptr t;
int x,ch;
clrscr();
t=NULL;
printf("\n\t Enter -1 to stop:");
while(1)
{
printf("\n\t Enter the element");
scanf("%d",&x);
if(x==-1)
break;
else
t=insertbst(t,x);
}
nonrecinorder(t);
getch();
}
trptr insertbst(trptr t,int x)
{
if(t==NULL)
{
t=(trptr)malloc(sizeof(struct treenode));
if(t==NULL)
printf("\nOut of space");
else
{
t->data=x;
t->lptr=t->rptr=NULL;
}
}
else if(x<t->data)
t->lptr=insertbst(t->lptr,x);
else
t->rptr=insertbst(t->rptr,x);
return(t);
}
void push(trptr s[30],trptr p)
{
if(tos>=29)
printf("\nOverflow on push");
else
{
tos++;
s[tos]=p;
}
}
trptr pop(trptr s[])
{
trptr y;
if(tos<=-1)
{
printf("\nUnderflow on pop");
return(NULL);
}
else
{
y=s[tos--];
return(y);
}
}
void nonrecinorder(trptr t)
{
trptr s[30],p;
tos=-1;
if(t==NULL)
{
printf("\nTree is empty");
return;
}
else
{
push(s,t);
p=t->lptr;
while(tos>=-1)
{
while(p!=NULL)
{
push(s,p);
p=p->lptr;
}
if(tos!=-1)
{
p=pop(s);
printf("\t%d",p->data);
p=p->rptr;
}
else
break;
}
}
}