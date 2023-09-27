#include <stdio.h>
#include <stdlib.h>

typedef struct job
{
    char no;
    int profit;
    int deadline;
} job;

void sort(job* jobarray,int n)
{
    job key;
    for(int i=1;i<n;i++)
    {
        key=jobarray[i];
        int j=i-1;
        while(j>=0 && key.profit>jobarray[j].profit)
        {
            jobarray[j+1]=jobarray[j];
            j--;
        }
        jobarray[j+1]=key;
    }
}

void greedy(job* jobarray, int max, int n)
{
    int sequence[max];
    for (int i = 1; i <= max; i++) {
        sequence[i] = -1; // Initialize the sequence array
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        int j = jobarray[i].deadline;
        while (j >= 0) 
        {
            if (sequence[j] == -1) 
            {
                sequence[j] = jobarray[i].no;
                totalProfit += jobarray[i].profit; // Update total profit
                break;
            }
            j=j-1;
        }
    }

    // Print the job sequence
    printf("Job Sequence: ");
    for (int i = 1; i <= max; i++) {
        if (sequence[i] != -1) {
            printf("%d ", sequence[i]);
        }
    }
    printf("\n");

    printf("Total Profit: %d\n", totalProfit);
}

int main()
{
    int n;
    printf("Enter the no of jobs: ");
    scanf("%d", &n);
    
    job* jobarray=(job*)malloc(n*sizeof(job));
    
    for(int i=0;i<n;i++)
    {
        printf("Enter the job number: ");
        scanf("%d", &jobarray[i].no);
        printf("Enter the profit: ");
        scanf("%d", &jobarray[i].profit);
        printf("Enter the deadline: ");
        scanf("%d", &jobarray[i].deadline);
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t", jobarray[i].no);
        printf("%d\t", jobarray[i].profit);
        printf("%d\t", jobarray[i].deadline);
        printf("\n");
    }
   
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(max<jobarray[i].deadline)
        {
            max=jobarray[i].deadline;
        }
    }
    sort(jobarray,n);
    printf("\nSorted Jobs (by profit in descending order):\n");
    printf("Name\tProfit\tDeadline\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", jobarray[i].no);
        printf("%d\t", jobarray[i].profit);
        printf("%d\t", jobarray[i].deadline);
        printf("\n");
    }

    printf("Max deadline is: %d\n", max);

    greedy(jobarray, max, n);

    free(jobarray); // Free dynamically allocated memory
    
    return 0;
}