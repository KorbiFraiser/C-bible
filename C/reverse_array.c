/* reverse_array.c */

#include <stdio.h>

void reverse(int arr[], int n);

int main(void)
{
    int i;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    reverse(arr, n);

    printf("Reversed Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}


void reverse(int arr[], int n)
{
    int i;
    
    for(i = 0; i < n / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }
}