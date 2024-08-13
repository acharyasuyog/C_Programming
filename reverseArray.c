#include <stdio.h>

int ArrayReverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main()
{
    int arr[] = {1, 3, 5, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    ArrayReverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}