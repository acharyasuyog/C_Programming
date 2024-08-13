#include <stdio.h> 
#include <stdlib.h>

typedef struct Job
{
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b)
{
    return ((Job *)b)->profit - ((Job *)a)->profit;
}
void jobSequencing(Job jobs[], int n)
{
    qsort(jobs, n, sizeof(Job), compare);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }
    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
    {
        slot[i] = -1;
    }
    int count = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = jobs[i].id;
                count++;
                profit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Total jobs: %d\n", count);
    printf("Total profit: %d\n", profit);
    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i] != -1)
        {
            printf("%d ", slot[i]);
        }
    }
    printf("\n");
}
int main()
{
    int n = 5;
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};

    jobSequencing(jobs, n);
    return 0;
}
