#include<stdio.h>
void merge(int a[],int low,int high,int mid);
void mergesort(int a[],int low,int high);
void main()
{
        int i,a[10],n;
        printf("\nEnter the nuber of elements:");
        scanf("%d",&n);
        printf("\nEnter the elements of array:");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        mergesort(a,0,n-1);
        printf("\nThe elements after sorting are:");
        for(i=0;i<n;i++)
                printf("%5d",a[i]);
        printf("\n");
}
void mergesort(int a[],int low,int high)
{
        int mid;
        if(low<high)
        {
                mid=(low+high)/2;
                mergesort(a,low,mid);
                mergesort(a,mid+1,high);
                merge(a,low,high,mid);
        }
}
void merge(int a[],int low,int high,int mid)
{
        int i,j,k,c[50];
        i=low;
        j=mid+1;
        k=low;
        while((i<=mid)&&(j<=high))
        {
                if(a[i]<a[j])
                {
                        c[k]=a[i];
                        k++;i++;
                }
                else
                {
                        c[k]=a[j];
                        k++;j++;

  }
        }
        while(i<=mid)
        {
                c[k]=a[i];
                k++;i++;
        }
        while(j<=high)
        {
                c[k]=a[j];
                k++;j++;
        }
        for(i=low;i<k;i++)
        {
                a[i]=c[i];
        }
}

