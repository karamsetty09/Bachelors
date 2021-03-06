#include<stdio.h>
void quicksort(int a[30],int n);
void qsort(int a[30],int left,int right);
int median3(int a[30],int left,int right);
void main()
{
        int i,a[10],n;
        printf("\n\t Enter the number of elements in the array:");
        scanf("%d",&n);
        printf("\n\t Enter the elements of the array:");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        quicksort(a,n);
        printf("\n\t The elements after sorting are :");
        for(i=0;i<n;i++)
                printf("%d   ",a[i]);
}
void quicksort(int a[30],int n)
{
        qsort(a,0,n-1);
}
void qsort(int a[30],int left,int right)
{
        int i,j,temp,pivot;
        if(left<right)
        {
                i=left;
                j=right-1;
                pivot=median3(a,left,right);
                for( ; ; )
                {
                        while(a[i]<pivot)
                                i++;
                        while(a[j]>pivot)
                                j--;
                        if(i<j)
                        {
                                temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                        else
                                break;
                }
                temp=a[i];
 a[i]=a[right];
                a[right]=temp;
                qsort(a,0,i-1);
                qsort(a,i+1,right);
        }
}
int median3(int a[30],int left,int right)
{
        int center,temp;
        center=(left+right)/2;
        if(a[left]>a[right])
        {
                temp=a[left];
                a[left]=a[right];
                a[right]=temp;
        }
        if(a[left]>a[center])
        {
                temp=a[left];
                a[left]=a[center];
                a[center]=temp;
        }
        if(a[center]>a[right])
        {
                temp=a[center];
                a[center]=a[right];
                a[right]=temp;
        }
         temp=a[center];
         a[center]=a[right];
         a[right]=temp;
         return(a[right]);

}

