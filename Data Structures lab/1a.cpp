#include<stdio.h>


int main()
{
        int i,j,n,sum,a[20];
        int alg4(int[],int);
        printf("\n\t Enter n value:");
        scanf("%d",&n);
        printf("\n\t Enter array values:");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        sum=alg4(a,n);
        printf("\n\t sum of linear algorithams is %d",sum);
}
int alg4(int a[20],int n)
{
        int j,maxsum,thissum;
        thissum=0;
        maxsum=0;
        for(j=0;j<n;j++)
        {
                thissum+=a[j];
                if(thissum>maxsum)
                        maxsum=thissum;
                else if(thissum<0)
                        thissum=0;
        }
        return maxsum;
}