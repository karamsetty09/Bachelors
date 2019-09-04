#include<stdio.h>
void lsearch(int a[],int n,int ele);
void bsearch(int a[],int n,int ele);
void sort(int a[],int n);
void read(int a[],int n);
int main()
{
        int a[50], n, op=0, ele;
        printf("\n\t 1.Linear search \n\t 2. Binary search \n\t 3. Exit");
        printf("\n\t Enter your option");
        scanf("%d",&op);
        if(op>0&&op<3)
        {
                printf("\n\t Enter the size of array :");
                scanf("%d",&n);
                read(a,n);
                printf("\n\t Enter the elements to search :");
                scanf("%d",&ele);
        }
        switch(op)
        {
                case 1: lsearch(a,n,ele);
                         break;
                case 2: bsearch(a,n,ele);
                         break;
                default: printf("\n\t Invalid Option !....");
        }
}
void read(int a[],int n)
{
        int i;
        printf("\n\t Enter the %d elements below :");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
}
void sort(int a[],int n)
{
        int i,j,temp;
        for(i=0;i<n-1;i++)
        {
                for(j=i+1;j<n;j++)
                        if(a[i]>a[j])
                        {
                                temp=a[i];
                                a[i]=a[j];
 a[j]=temp;
                        }
        }
}
void lsearch(int a[],int n,int ele)
{
        int flag=0,i;
        for(i=0;i<n;i++)
        {
                if(a[i]==ele)
                {
                        flag=1;
                        break;
                }
        }
        if(flag==1)
                printf("\n\t Element found");
        else
                printf("\n\t Element not found");
}
void bsearch(int a[],int n,int ele)
{
        int low,high,mid;
        low=0;
        high=n-1;
        while(low<=high)
        {
                mid=(low+high)/2;
                if(a[mid]<ele)
                        low=mid+1;
                else if(a[mid]>ele)
                        high=mid-1;
                else
{
printf("FOund");
                        return;
        }
        }
printf("\n\t Not found");
}

