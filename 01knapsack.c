#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n1,int n2,int profit[],int weight[])
{
    int selected[100]={0};
    int v[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        v[i][0]=0;
    }
    for(int j=0;j<=n2;j++)
    {
        v[0][j]=0;
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(weight[i]>j)
            {
                v[i][j]=v[i-1][j];
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[i-1][j-weight[i]]+profit[i]);
            }
        }
    }

    printf("V matrix is:\n");
    for (int i=0;i<=n1;i++) {
        for (int j=0;j<=n2;j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    printf("If Selected Then 1 Else 0:\n");
    int i=n1,j=n2;
    while(i>0&&j>0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            selected[i] = 1;
            j=j-weight[i];
        } 
        i--;        
    }

    printf("Selection array of profits (1 if selected, 0 otherwise):\n");
    for (int i = 1; i <= n1; i++)
        printf("%d ", selected[i]);
    printf("\n");
}

int main()
{
    int profit[100],weight[100];
    int num1,num2;
    printf("Enter Number Of Obj: ");
    scanf("%d",&num1);
    for(int i=1;i<=num1;i++)
    {
        printf("Enter Profit: ");
        scanf("%d",&profit[i]);
        printf("Enter Weight: ");
        scanf("%d",&weight[i]);
    }
    printf("\nEnter Max Capacity: ");
    scanf("%d",&num2);
    knapsack(num1,num2,profit,weight);
    return 0;
}
