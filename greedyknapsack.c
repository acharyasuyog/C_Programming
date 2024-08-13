#include <stdio.h>
#include <stdlib.h>

void knapsack(int W, int n, float weight[], float x[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    float tempW = W;
    for (i = 0; i < n; i++)
    {
        if (weight[i] > tempW)
        {
            break;
        }
        x[i] = 1.0;
        tempW -= weight[i];
    }
    if (i < n)
    {
        x[i] = tempW / weight[i];
    }
}

void printKnapsack(int n, float weight[], float profit[], float x[])
{
    float totalProfit = 0.0;
    printf("Item\tWeight\tProfit\tSelected\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, weight[i], profit[i], x[i]);
        totalProfit += x[i] * profit[i];
    }
    printf("Total profit: %.2f\n", totalProfit);
}

int main()
{
    int n = 5, W = 60;
    float weight[] = {5, 10, 20, 30, 40};
    float profit[] = {30, 20, 100, 90, 160};
    float x[n];
    float ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
    knapsack(W, n, weight, x);
    printKnapsack(n, weight, profit, x);
    return 0;
}
