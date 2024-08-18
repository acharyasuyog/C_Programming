#include <stdio.h>
void reverseArray(int arr[], int n)
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
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, n);

    printf("Reversed Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
/*Since the loop iterates from 0 to n/2 the time complexity is O(n/2), the constant are ignored so, the
actual time complexity is O(n).*/