#include <stdio.h>
#define  MAX 100

int min(int x,int y)
{
	if(x<y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void floyd_warshall(int n,int w[][MAX])
{
	int d[MAX][MAX];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			d[i][j]=w[i][j];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				d[i][j]=min((d[i][k]+d[k][j]),d[i][j]);
			}
		}
	}
	printf("D matrix is:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int w[MAX][MAX];
	int n;
	printf("Enter Row number:");
	scanf("%d",&n);
	printf("For Infinite Input Put A Large Value Compare To Your Other Array Input:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("W[%d][%d]:",i+1,j+1);
			scanf("%d",&w[i][j]);
		}
	}
	floyd_warshall(n,w);
}