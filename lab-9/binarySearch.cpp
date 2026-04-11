#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x)
        return binarySearch(arr, mid + 1, r, x);
    else
        return binarySearch(arr, l, mid - 1, x);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    printf("Array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter element to search: ");
    int x;
    scanf("%d", &x);
    int result = binarySearch(arr, 0, 4, x);
    if (result == -1)
        printf("Element not found in array");
    else
        printf("Element found at index %d", result);
    return 0;
}