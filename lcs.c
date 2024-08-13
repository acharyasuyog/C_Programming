#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void LCS(char *X, char *Y, int m, int n, char **b, int **c)
{
    for (int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            }
            else
            {
                if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 'u';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'l';
                }
            }
        }
    }
}

void printLCS(char **b, char *X, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == 'd')
    {
        printLCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 'u')
    {
        printLCS(b, X, i - 1, j);
    }
    else
    {
        printLCS(b, X, i, j - 1);
    }
}

int main()
{
    char X[100];
    char Y[100];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);

    int n = strlen(Y);

    int **c = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
    {
        c[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    char **b = (char **)malloc((m + 1) * sizeof(char *));
    for (int i = 0; i <= m; i++)
    {
        b[i] = (char *)malloc((n + 1) * sizeof(char));
    }
    printf("X=%s\n", X);
    printf("Y=%s\n", Y);

    LCS(X, Y, m, n, b, c);
    printf("Lenght of Longest Common Subsequence: %d\n", c[m][n]);
    printf("Longest Common Subsequence: ");
    printLCS(b, X, m, n);
    printf("\n");

    return 0;
}
