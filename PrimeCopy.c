#include <stdio.h>

void isPrime(int arr[], int n)
{
    int primes[n];      
    int primeCount = 0; 

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int isPrime = 1;

        if (num < 2)
        {
            isPrime = 0;
        }
        else
        {
            for (int j = 2; j <= num / 2; j++)
            {
                if (num % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime)
        {
            primes[primeCount] = num;
            primeCount++;
        }
    }

    printf("Prime numbers are:\n");
    for (int i = 0; i < primeCount; i++)
    {
        printf("%d ", primes[i]);
    }
}

int main()
{
    int arr[] = {1,2,4,6,7,11,13,19,21,29,31};
    int n = sizeof(arr) / sizeof(arr[0]);

    isPrime(arr, n);

    return 0;
}
