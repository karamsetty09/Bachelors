#include<stdio.h>
#include<malloc.h>
struct treenode;
typedef struct treenode* position;
typedef struct treenode* tree;
struct treenode
{
int element;
tree left;
tree right;
};
position findmin(tree);
position insert(int x,tree t);
tree delete(int x,tree t);
void inorder(tree t);
void preorder(tree t);
void postorder(tree t);
void  main()
{
tree t=NULL;
int ch=0,x;
printf("1.insert\n2.delete\n3.inorder\n4.preorder\n");
printf("5.postorder\n6.exit\n");
while(ch!=6)
{
printf("\n\t Enter ur option:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter element to insert\n");
scanf("%d",&x);
t=insert(x,t);
break;
case 2:
printf("enter element to delete");
scanf("%d",&x);
delete(x,t);
break;
case 3:
printf("\nthe inoder is :\n");
inorder(t);
break;
case 4:
printf("\nthe preoder is :\n");
preorder(t);
break;
case 5:
printf("\nthe postoder is :\n");
postorder(t);
break;
}
}
}
position insert(int x, tree t)
{
if(t==NULL)
{
t=(tree)malloc(sizeof(struct treenode));
if(t==NULL)
{
printf("OUT OF SPACE");
return;
}
else
{
t->element=x;
t->left=NULL;
t->right=NULL;
}
}
else if(x<t->element)
t->left=insert(x,t->left);
else if(x>t->element)
t->right=insert(x,t->right);
return(t);
}
tree delete(int x, tree t)
{
position tempcell;
if(t==NULL)
printf("Not Found");
else if(x<t->element)
t->left=delete(x,t->left);
else if(x>t->element)
t->right=delete(x,t->right);
else
{
if(t->left && t->right)
{
{
tempcell=findmin(t->right);
t->element=tempcell->element;
t->right=delete(t->element,t->right);
}
else
{
tempcell=t;
if(t->left==NULL)
t=t->right;
else
if(t->right==NULL)
t=t->left;
free(tempcell);
}
}
return t;
}
position findmin(tree t)
{
tree temp;
temp=t;
if(temp!=NULL)
while(temp->left!=NULL)
temp=temp->left;
return(temp);
}
void inorder(tree t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d\t",t->element);
inorder(t->right);
}
}
void preorder(tree t)
{
if(t!=NULL)
{
printf("%d\t",t->element);
preorder(t->left);
preorder(t->right);
}
}

void postorder(tree t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf("%d\t",t->element);
}
}


