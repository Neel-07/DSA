#include <bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of an element in a
// sorted array
int firstOcc(int* arr, int l, int h, int x)
{
    if (h >= l) {
        int mid = (l + h) / 2;

        // Check if the element is present at the middle or
        // if the element is present in the left half (if
        // the element is greater than the middle element)
        if ((mid == 0 || x > arr[mid - 1])
            && arr[mid] == x) {
            return mid;
        }
        else if (x > arr[mid]) {

            // Search in the right half
            return firstOcc(arr, (mid + 1), h, x);
        }
        else {

            // Search in the left half
            return firstOcc(arr, l, (mid - 1), x);
        }
    }
    return 0;
}

// Function to find the last occurrence of an element in a
// sorted array
int lastOcc(int arr[], int n, int l, int h, int x)
{
    if (h >= l) {
        int mid = (l + h) / 2;

        // Check if the element is present at the middle or
        // if the element is present in the right half (if
        // the element is smaller than the middle element)
        if ((mid == n - 1 || x < arr[mid + 1])
            && arr[mid] == x) {
            return mid;
        }
        else if (x < arr[mid]) {

            // Search in the left half
            return lastOcc(arr, n, l, (mid - 1), x);
        }
        else {

            // Search in the right half
            return lastOcc(arr, n, (mid + 1), h, x);
        }
    }
    return -1;
}

// Function to count the occurrences of an element in a
// sorted array
int countOccurrences(int arr[], int n, int x)
{

    // Find the first and last occurrences of the element
    int idxFirst = firstOcc(arr, 0, n - 1, x);

    // If the element does not exist, return -1
    if (idxFirst == -1) {
        return -1;
    }
    int idxLast = lastOcc(arr, n, idxFirst, n - 1, x);

    // Return the difference between the last and first
    // occurrences + 1 to get the total count
    return idxLast - idxFirst + 1;
}

int main()
{
    int arr[] = { 1, 1, 2, 2, 2, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    int occurrences = countOccurrences(arr,n,  x);

    cout << "Number of occurrences of " << x << ": "
         << occurrences << std::endl;

    return 0;
}
