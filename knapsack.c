#include <stdio.h> 
#include <stdlib.h>
void Knapsack(int W, int n, int *v, int *wt, int **c)
{
    int w, i;
    for (w = 0; w <= W; w++)
    {
        c[0][w] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        c[i][0] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        for (w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                if (v[i - 1] + c[i - 1][w - wt[i - 1]] > c[i - 1][w])
                {
                    c[i][w] = v[i - 1] + c[i - 1][w - wt[i - 1]];
                }
                else

                {
                    c[i][w] = c[i - 1][w];
                }
            }
            else
            {
                c[i][w] = c[i - 1][w];
            }
        }
    }
}
void viewKnapsack(int **c, int n, int W, int *wt)
{
    int i = n;
    int j = W;
    printf("Selected items (1-based index): ");
    while (i > 0 && j > 0)
    {
        if (c[i][j] != c[i - 1][j])
        {
            printf("%d ", i);
            j = j - wt[i - 1];
        }
        i--;
    }
    printf("\n");
}
int main()
{
    int n = 4;
    int W = 5;
    int v[] = {3, 4, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int **c = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        c[i] = (int *)malloc((W + 1) * sizeof(int));
    }
    Knapsack(W, n, v, wt, c);
    printf("Maximum value that can be obtained: %d\n", c[n][W]);
    viewKnapsack(c, n, W, wt);
    return 0;
}
