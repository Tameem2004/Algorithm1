#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void counting_sort(int arr[],int max,int num)
{
	int c[100];
	int b[100];
	for(int i=1;i<=max;i++)
	{
		c[i]=0;
	}
	for(int i=1;i<=num;i++)
	{
		c[arr[i]] = c[arr[i]] + 1;
	}
	for(int i=2;i<=max;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(int i=num;i>0;i--)
	{
		b[c[arr[i]]]=arr[i];
		c[arr[i]]--;
	}
	for (int i = 1; i <=num; i++) {
        arr[i] = b[i];
    }
	for (int i = 1; i <=num; i++) {
       printf("%d ", arr[i]); 
    }
}

int main()
{
    int num;
    printf("Enter The Size Of Array");
    scanf("%d",&num);
    int arr[num];
    
    printf("Enter Number In Array");
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

    counting_sort(arr,max,num);
}
