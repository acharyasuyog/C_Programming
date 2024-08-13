#include <stdio.h>
void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k;
    int b[100];
    for (k = l; k <= r; k++)
    {
        if (i > m)
        {
            b[k] = a[j++];
        }
        else if (j > r)
        {
            b[k] = a[i++];
        }
        else if (a[i] < a[j])
        {
            b[k] = a[i++];
        }
        else
        {
            b[k] = a[j++];
        }
    }
    for (k = l; k <= r; k++)
    {
        a[k] = b[k];
    }
}
void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void main()
{
    int a[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
