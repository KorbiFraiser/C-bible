/* binary_search.c */

#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x);

int main(void)
{
    int i;
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    int result;

    printf("Sorted Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Search value: ");
    scanf("%d", &x);

    result = binarySearch(arr, 0, n - 1, x);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", x, result);
    }
    else
    {
        printf("Element %d not found\n", x);
    }

    return 0;
}


int binarySearch(int arr[], int left, int right, int x)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == x)
            return mid;

        if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}