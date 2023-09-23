#include <stdio.h>

int func(int arr[], int low, int high) 
{
    //calculate max value using recursion & divide and conquer 
    int mid;
    if (low == high) {
        return arr[low];
    }
    else{
        mid = (low + high) / 2;
        int left = func(arr, low, mid);
        int right = func(arr, mid + 1, high);
        if(left  > right)
        {
            return left;
        }
        else
        {
            return right;
        } 
    }  
}

int main() {
    int num,arr[100],i;
    printf("Enter the size of Array:\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Eneter %d Element",i);
        scanf("%d",&arr[i]);
    }
    int max = func(arr, 0, num - 1);
    printf("The highest value in the array is %d\n", max);
    return 0;
}
 