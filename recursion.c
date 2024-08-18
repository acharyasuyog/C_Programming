// #include <stdio.h>

// int factorial(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }
// int main()
// {
//     int result = factorial(5);
//     printf("The facatorial is %d ", result);

//     return 0;
// }

// #include <stdio.h>

// int factorial(int n)
// {
//     int result = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         result = result * i;
//     }
//     return result;
// }

// int main()
// {
//     int result = factorial(5);
//     printf("%d", result);

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int i, n, fact = 1;
//     printf("Enter any number \n");
//     scanf("%d", &n);

//     for (i = 1; i <= n; i++)
//     {
//         fact = fact * i;
//     }

//     printf("The factorial of %d is %d", n, fact);

//     return 0;
// }

#include <stdio.h>

int factorial(int n)
{
    return n * factorial(n - 1);
}

int main()
{
    int result = factorial(5);
    printf("%d", result);
    return 0;
}