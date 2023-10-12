#include<stdio.h>

#define N_MAX 20

int board[N_MAX]; 
int col[N_MAX];   
int ld[N_MAX]; 
int rd[N_MAX];
int solution_count = 0; // To count the number of solutions

void display(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", board[i]);
    }
    printf("\n");
}

void place_queen(int N, int i)
{
    for (int j = 1; j <= N; j++)
    {
        if (col[j] == 0 && ld[i + N - j] == 0 && rd[i + j - 1] == 0)
        {
            board[i] = j;
            col[j] = 1;
            ld[i + N - j] = 1;
            rd[i + j - 1] = 1;
            if (i == N)
            {
                display(N);
            }
            else
            {
                place_queen(N, i + 1);
            }
            col[j] = 0, ld[i + N - j] = 0, rd[i + j - 1] = 0;
        }
    }
}

int main()
{
    int num;
    printf("Enter Number Of Queen:");
    scanf("%d", &num);
    place_queen(num, 1);
    return 0;
}