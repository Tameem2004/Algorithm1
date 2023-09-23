#include <stdio.h>

int func(int a[], int n){
    int max;
    ////calculate max value using recursion
    if(n == 1)
    {
        return a[0];
    }  
    else
    {
        max=func(a, n-1);
        if(a[n-1] > max)
        {
            return a[n-1];
        }
        else
        {
            return max;
        } 
    }
}

int main()
{
    int num,arr[100],i;
    printf("Enter the size of Array:\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Eneter %d Element",i);
        scanf("%d",&arr[i]);
    }
    int x = func(arr, num);
    printf("The highest value in the array is:%d", x);
    return 0;
}