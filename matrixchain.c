#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
void matrixchain(int *p, int n, int **m, int **s)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int **s, int i, int j)
{
    if (i == j)
    {

        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int n = 6;
    int p[] = {2, 5, 3, 5, 2, 3, 5};
    int **m = (int **)malloc((n + 1) * sizeof(int *));
    int **s = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        m[i] = (int *)malloc((n + 1) * sizeof(int));
        s[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    matrixchain(p, n, m, s);
    printf("Optimal number of multiplications: %d\n", m[1][n]);
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n);
    printf("\n");

    return 0;
}