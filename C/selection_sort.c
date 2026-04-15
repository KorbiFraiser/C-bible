/* selection_sort.c */

#include <stdio.h>

void selectionSort(int arr[], int n);

int main(void)
{
    int i;
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    selectionSort(arr, n);

    printf("Sorted array:   ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}


void selectionSort(int arr[], int n)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        int min = i;

        for(j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}