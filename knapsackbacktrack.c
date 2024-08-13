#include <stdio.h>
int maxProfit = 0;
int count = 0;
void knapsack(int weight[], int profit[], int n, int capacity, int curWeight, int curProfit, int curIndex)
{
    if (curWeight <= capacity && curProfit > maxProfit)
    {
        maxProfit = curProfit;
        count++;

        printf("Knapsack %d: ", count);
        for (int i = 0; i < curIndex; i++)
        {
            printf("%d ", weight[i]);
        }
        printf("\n");
    }
    if (curIndex == n)
    {
        return;
    }
    if (curWeight + weight[curIndex] <= capacity)
    {
        knapsack(weight, profit, n, capacity, curWeight + weight[curIndex], curProfit + profit[curIndex], curIndex + 1);
    }
    knapsack(weight, profit, n, capacity, curWeight, curProfit, curIndex + 1);
}
int main()
{
    int n = 4;
    int weight[] = {2, 3, 4, 5};
    int profit[] = {3, 5, 6, 10};
    int capacity = 8;
    knapsack(weight, profit, n, capacity, 0, 0, 0);
    if (count == 0)
    {
        printf("No subset found with sum %d\n", capacity);
    }
    return 0;
}
