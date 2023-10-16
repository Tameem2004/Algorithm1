#include<stdio.h>

void merge(int a[],int l,int m,int h)
{
    int aux[100];
    int i=l,j=m+1,k=l;
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
        {
            aux[k++]=a[i++];
        }
        else
        {
            aux[k++]=a[j++];
        }
    }
    while(j<=h)
    {
        aux[k++]=a[j++];
    }
    while(i<=m)
    {
        aux[k++]=a[i++];
    }
    for(int k=l;k<=h;k++)
    {
        a[k]=aux[k];
    }
}

void merge_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=(h+l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,h);
        merge(a,l,m,h);
    }
}

int main()
{
    int num,arr[100];
    printf("Enter The Size Of Array");
    scanf("%d",&num);
    printf("Enter Element In Array");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }

    merge_sort(arr,0,num-1);

    printf("Array After Marge Sort");
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
}