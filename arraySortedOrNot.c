#include <stdio.h>
void sortedArrayOrNot(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("The array is not sorted\n");
            return;
        }
    }
    printf("The array is sorted\n");    
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortedArrayOrNot(arr, n);
    return 0;
}
