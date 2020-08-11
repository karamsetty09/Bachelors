#include<stdio.h>
void shellsort(int a[],int n);
void main()
{
        int a[20],i,n;
        printf("\n\t Enter the number of elements:");
        scanf("%d",&n);
        printf("\n\t Enter elements:");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("\n\t Array before sorting is :");
        for(i=0;i<n;i++)
                printf("%5d",a[i]);
        shellsort(a,n);
        printf("\n\t Array after sorting is :");
        for(i=0;i<n;i++)
                printf("%5d",a[i]);

}
void shellsort(int a[],int n)
{
        int i,j,k,m,mid;
        for(m=n/2;m>0;m/=2)
        {
                for(j=m;j<n;j++)
                {
                        for(i=j-m;i>=0;i-=m)
                        {
                                if(a[i+m]>=a[i])
                                        break;
                                else
                                {
                                        mid=a[i];
                                        a[i]=a[i+m];
                                        a[i+m]=mid;
                                }
                        }
                }
        }
}

