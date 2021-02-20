#include<stdio.h>
#include<string.h>
#include<math.h>
#define n 10
int issymbol(char x);
void infixtopost(char ine[],char pe[]);
int isopen(char x);
int isoperator(char x);
int precedence(char x);
char top(char[]);
int pop(char s[]);
void push(char s[],int x);
int tos;
char ine[50],pe[50];
void main()
{
        int i=0;
        printf("\n\t Enter infix expression :");
        gets(ine);

                infixtopost(ine,pe);

        printf("\n\t Post fix expression is :");
puts(pe);

        }

        void infixtopost(char ine[],char pe[])
        {
                int i,j,px,py;
                char x,y,s[20];
                tos=-1;
                i=j=0;
                while(ine[i]!='\0')
                {
                        x=ine[i];
                        if(!isoperator(x) && !issymbol(x))
                                pe[j++]=x;
                        else if(isoperator(x))
                        {
                                if(tos!=-1)
                                {
                                        y=top(s);
                                        if(!issymbol(y))
                                        {
 py=precedence(y);
                                                px=precedence(x);
                                                while(tos!=-1 && px<=py)
                                                {
                                                        pe[j++]=pop(s);

           y=top(s);
        py=precedence(y);
                                                }
                                        }
                                }
                                push(s,x);
                        }
                        else
                        {
                                if(isopen(x))
                                        push(s,x);
                        else
                        {
                                while(top(s)!='(')
                                        pe[j++]=pop(s);
                                pop(s);
                        }
                }
                ++i;
        }
pe[j]='\0';
}
int issymbol(char x)
{
        if((x=='(') || (x==')'))
                return(1);
        else
                return(0);
}
int isopen(char x)
{
        if(x=='(')
                return(1);
        else
                return(0);
}
int isoperator(char x)
{
        if(x=='*' || x=='+' || x=='-' || x=='/' || x=='%')
 return(1);
        else
                return(0);
}
int precedence(char x)
{
        if(x=='^')
                return(3);
        else if(x=='%' || x=='*' || x=='/')
                return(2);
        else
                return(0);
}

char top(char s[])
{
        if(tos>-1)
                return(s[tos]);
        else
                return(-1);
}

int pop(char s[])
{
        int y;
        if(tos<=-1)
                printf("\n\t under flow \n");
        else
        {
                y=s[tos];
                tos--;
        }
        return(y);
}

void push(char s[],int x)
{
        if(tos>=n-1)
                printf("Over Flow \n");
        else
        {
                tos++;
                s[tos]=x;
        }
        return;

}