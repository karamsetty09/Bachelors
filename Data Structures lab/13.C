#include<Stdio.h>
#include<conio.h>
int tos1=-1,x,n;
int tos2=5;
int s[5];

void  push1(int x,int s[])
{
   if(tos2 -tos1==1)
      printf("\nstack is full :Overflowerror");
  else
  {
     s[++tos1] = x;
     printf("\nItem added is:%d",x);
     }
}


void push2(int x,int s[])
 {
  if( tos2-tos1==1)
     printf("\nstack is full: Overflowerror");
  else
     {
      s[--tos2] = x;
       printf("\nItem added is:%d",x);
       }
}

void pop1(int s[])
{
   if(tos1<=-1)
    {
     printf("\nunderflow on pop1");
     }
   else
    {
     x=s[tos1--];

     printf("\nPopped element is:%d",x);

    }
  }

void pop2(int s[])
{
 if(tos2>=n)
   {
    printf("\nunderlow on pop2");

     }
  else
    {
    x=s[tos2++];
     printf("\nPopped element is:%d",x);
      }
    }
void display1(int s[])
{
	int p=tos1;
	while(p>-1)
	{
	printf("%d\t",s[p--]);
	}
}

void display2(int s[])
{
	int p=tos2;
	while(p<n)
	{
	printf("%d\t",s[p++]);
	}
}

void main()
{
	int ch;
	int n,s[20],x;
	clrscr();
	do
	{
	printf("\n1.Stack-1\n2.Stack-2\n3.Exit\n");
	printf("\n\t Enter ur choice:");
	scanf("%d",&ch);
	printf("\n1.Push\n2.Pop\n3.Display\n");
	printf("\n\t Enter ur choice:");
	scanf("%d",&n);
	switch(n)
	{
		case 1: printf("\nEnter element to be inserted:");
			scanf("%d",&x);
			if(ch==1)
			push1(x,s);
			else
			push2(x,s);
			break;
		case 2: if(ch==2)
			pop1(s);
			else
			pop2(s);
			break;
		case 3:
			if(ch==1)
			display1(s);
			else if(ch==2)
			display2(s);
			break;
	}
	}while(n!=3);
}