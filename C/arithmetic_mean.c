/* arithmetic_mean.c */

#include <stdio.h>

int sum(int arr[], int n);
double mean(int arr[], int n);


int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int s = sum(arr, n);
    double m = mean(arr, n);

    printf("sum  = %d\n", s);
    printf("mean = %.2f\n", m);

    return 0;
}


int sum(int arr[], int n)
{
    int i;
    int s = 0;

    for(i = 0; i < n; i++)
    {
        s += arr[i];
    }

    return s;
}


double mean(int arr[], int n)
{
    if (n == 0)
    {
        return 0.0;

    }

    return (double)sum(arr, n) / n;
}