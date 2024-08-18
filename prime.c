#include <stdio.h>

int main()
{
    int i, j, num = 6, temp = 0;

    for (i = 2; i <= num; i++)
    {
        for (j = 2; j < i / 2; j++)
        {
            if (i % j == 0)
            {
                temp++;
                break;
            }
        }
    }
    if (temp == 0)
    {
        printf("prime");
    }
    else
    {
        printf("not prime");
    }

    return 0;
}