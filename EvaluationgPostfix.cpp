#include<stdio.h>
#include<string.h>
#define max 10
int tos=-1;
int postfixvalue(char pe[50]);
void push(char s[],char x);
int pop(char s[]);
int isoperator(char x);
void main()
{
        int l,p;
        char a[50];
        printf("\n\t Enter postfix notation:");
        scanf("%s",&a);
        l=strlen(a);
        a[l]='\0';
        p=postfixvalue(a);
        printf("\n\t The evaluted value is: %d",p);
}
int postfixvalue(char pe[50])
{
        int i,x,y,z;
        char s[50];
        i=0;
        while(pe[i]!='\0')
        {
                if(isoperator(pe[i]))
                {
                        y=pop(s);
                        x=pop(s);
                        switch(pe[i])
                        {
                                case '*': z=x*y;
                                          break;
                                case '/': z=x/y;
                                          break;
                                case '+': z=x+y;
                                          break;
                                case '-': z=x-y;
                                          break;
                                case '%': z=x%y;
                                          break;
                        }
                        push(s,z);
                }
  else
                {
                        printf("\n\t Enter value of %c ",pe[i]);
                        scanf("%d",&x);
                        push(s,x);
                }
                ++i;
        }
        return (s[tos]);
}
int isoperator(char x)
{
        if(x=='+' || x=='-' || x=='/' || x=='%')
                return(1);
        else
                return(0);
}
void push(char s[],char x)
{
        if(tos==max-1)
        {
                printf("\n\t Over flow");
                return;
        }
        else
                s[++tos]=x;
}
int pop(char s[])
{
        int y;
        if(tos==-1)
        {
                printf(" Under flow");
                return;
        }
        else
        {
                y=s[tos--];
                return(y);
        }
}

