#include<stdio.h>
void insertion(int a[20],int n);
int main()
{
        int n,i,a[20];
        printf("\n\t Enter the values of n:");
        scanf("%d",&n);
        printf("\n\t Enter the elements:");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("\n\t The sorted list is:");
        insertion(a,n);
}
void insertion(int a[20],int n)
{
        int p,j,temp,i;
        for(p=1;p<n;++p)
        {
                temp=a[p];
                for(j=p;a[j-1]>temp&&j>0;j--)
                        a[j]=a[j-1];
                        a[j]=temp;
        }
        for(i=0;i<n;i++)
                printf("%d   ",a[i]);
}


