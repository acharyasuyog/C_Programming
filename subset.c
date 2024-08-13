#include <stdio.h>

int count = 0;

void subsetSum(int arr[], int n, int sum, int sol[], int curSum, int curIndex, int solIndex)
{
    if (curSum == sum)
    {
        count++;
        printf("Subset %d: ", count);
        for (int i = 0; i < solIndex; i++)
        {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return;
    }
    
    if (curIndex == n)
    {
        return;
    }
    
    // Include the current element in the subset
    if (curSum + arr[curIndex] <= sum)
    {
        sol[solIndex] = arr[curIndex];
        subsetSum(arr, n, sum, sol, curSum + arr[curIndex], curIndex + 1, solIndex + 1);
    }
    
    // Exclude the current element from the subset
    subsetSum(arr, n, sum, sol, curSum, curIndex + 1, solIndex);
}

int main()
{
    int n = 4;
    int arr[] = {3, 4, 5, 6};
    int sum = 9;
    int sol[n];
    
    subsetSum(arr, n, sum, sol, 0, 0, 0);
    
    if (count == 0)
    {
        printf("No subset found with sum %d\n", sum);
    }
    
    return 0;
}
