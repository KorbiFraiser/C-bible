/* max_and_min.c */

#include <stdio.h>

int max(int arr[], int n);
int min(int arr[], int n);

int main(void)
{
    int i;
    int arr[] = {12, 5, 78, 3, 99, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Max = %d\n", max(arr, n));
    printf("Min = %d\n", min(arr, n));

    return 0;
}


int max(int arr[], int n)
{
    int i;

    if (n <= 0)
        return 0;

    int m = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}


int min(int arr[], int n)
{
    int i;

    if(n <= 0)
    {
        return 0;
    }

    int m = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] < m)
        {
            m = arr[i];
        }
    }
    return m;
}
