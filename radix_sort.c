#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void counting_sort(int arr[],int num,int pos)
{
    int b[100];
    int c[100];
    for(int i=1;i<=10;i++)
    {
        c[i]=0;
    }
    for(int i=1;i<=num;i++)
    {
        c[(arr[i]/pos)%10]=c[(arr[i]/pos)%10]+1;
    }
    for(int i=1;i<=10;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int i=num;i>0;i--)
    {
        b[c[(arr[i]/pos)%10]]=arr[i];
        c[(arr[i]/pos)%10]--;
    }
    for (int i = 1; i <=num; i++) 
    {
        arr[i] = b[i];
    }
	for (int i = 1; i <=num; i++) 
    {
       printf("%d ", arr[i]); 
    }
    printf("\n");
}

void radix_sort(int arr[],int num,int max)
{
    for(int pos=1;max/pos>0;pos=pos*10)
    {
        counting_sort(arr,num,pos);
    }
}

int main()
{
    int num,arr[100];
    printf("Enter The Size Of Array");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        scanf("%d",&arr[i]);
    }

    int max=INT_MIN;
    for(int i=1;i<=num;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    radix_sort(arr,num,max);
}