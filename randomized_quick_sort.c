#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[],int l,int h)
{
    int up=h;
    int down=l;
    int pivotIndex = l + rand() % (h - l + 1);
	swap(&a[l],&a[pivotIndex]);
	int pivot = a[l];
    while(down<up)
    {
        while(pivot<a[up] && up>l)
        {
            up--;
        }
        while(pivot>a[down] && down<h)
        {
            down++;
        }
        if(down<up)
        {
            swap(&a[up],&a[down]);
        }
    }
    swap(&a[up],&pivot);
    return up;
}

void quick_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int p=partition(a,l,h);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,h);
    }
}

int  main()
{
    int num,arr[100];
    printf("Enter The Size Of Array");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,num-1);

    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}