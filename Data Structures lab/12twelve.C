#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node * nptr;
struct node
{
	int data;
	nptr next;
};
nptr createhead()
{
	nptr t;
	t=(nptr)malloc(sizeof(struct node));
	t->next=NULL;
	return t;
}
nptr * createht(int m)
{
	nptr * HT;
	int i;
	HT=(nptr *)malloc(sizeof(nptr)*m);
	for(i=0;i<m;i++)
	HT[i]=createhead();
	return HT;
 }
void insert(nptr h,int x)
{
	nptr temp=(nptr)malloc(sizeof(struct node));
	temp->data=x;temp->next=h->next;h->next=temp;
}
void htins(nptr *HT,int x,int m)
{
	int b=x%m;
	insert(HT[b],x);
}
void print(nptr h)
{
	nptr t=h->next;
	if(t==NULL)
	printf("Empty");
	else
	{
		while(t!=NULL)
		{
			printf("%d->",t->data);
			t=t->next;
    }

	}
}
int main()
{
	int m,x,i;
	nptr *H;
	clrscr();
	printf("\nEnter size of Hash table");
	scanf("%d",&m);
	 H=createht(m);
	printf("Enter elements:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		htins(H,x,m);
	}
	printf("Hash Table is:\n");
	for(i=0;i<m;i++)
	{
		printf("%d: ",i);
		print(H[i]);
		printf("\n");
	}
	return 0;

}
