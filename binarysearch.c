#include <stdio.h>
int BinarySearch(int a[], int key, int l, int h)
{
    int mid;
    mid = (l + h) / 2;
    if (l > h)
    {
        return -1;
    }
    if (a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] > key)
    {
        return BinarySearch(a, key, l, mid - 1);
    }
    else
    {
        return BinarySearch(a, key, mid + 1, h);
    }
}
void main()
{
    int arr[100], n, key, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int result = BinarySearch(arr, key, 0, n - 1);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else

    {
        printf("Element found at index %d\n", result);
    }
}
