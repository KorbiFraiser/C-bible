/* linear_search.c */

#include <stdio.h>

int linearSearch(int arr[], int n, int x);

int main(void)
{
    int i;
    int arr[] = {10, 25, 3, 42, 7, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    int result;

    printf("Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Search value: ");
    scanf("%d", &x);

    result = linearSearch(arr, n, x);

    if(result != -1)
    {
        printf("Element %d found at index %d\n", x, result);
    }
    else
    {
        printf("Element %d not found\n", x);
    }

    return 0;
}


int linearSearch(int arr[], int n, int x)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}