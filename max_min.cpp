#include <stdio.h>

// Function to find minimum and maximum elements in an array
void findMinMax(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    // Traverse array elements
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    // Print minimum and maximum elements
    printf("min-%d max-%d\n", min, max);
}

int main()
{
    // Input array
    int arr[] = { 1, 423, 6, 46, 34, 23, 13, 53, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find minimum and maximum elements
    findMinMax(arr, n);

    return 0;
}
