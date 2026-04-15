/* c_arrays.c */

#include <stdio.h>

void print1D(int arr[], int n);
void print2D(int rows, int cols, int arr[rows][cols]);
void print3D(int x, int y, int z, int arr[x][y][z]);

int sum1D(int arr[], int n);
int sum2D(int rows, int cols, int arr[rows][cols]);


int main(void)
{
    /* ---------------- 1D ARRAY ---------------- */
    printf("=== 1D ARRAY ===\n");

    int arr1D[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1D) / sizeof(arr1D[0]);

    print1D(arr1D, n1);
    printf("Sum = %d\n\n", sum1D(arr1D, n1));


    /* ---------------- 2D ARRAY ---------------- */
    printf("=== 2D ARRAY (Matrix) ===\n");

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print2D(2, 3, matrix);
    printf("Sum = %d\n\n", sum2D(2, 3, matrix));


    /* ---------------- 3D ARRAY ---------------- */
    printf("=== 3D ARRAY ===\n");

    int cube[2][2][3] = {
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {7, 8, 9},
            {10, 11, 12}
        }
    };

    print3D(2, 2, 3, cube);

    return 0;
}


/* ---------- 1D ---------- */
void print1D(int arr[], int n)
{
    int i;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int sum1D(int arr[], int n)
{
    int i;
    int sum = 0;

    for(i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}


/* ---------- 2D ---------- */
void print2D(int rows, int cols, int arr[rows][cols])
{
    int i, j;
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int sum2D(int rows, int cols, int arr[rows][cols])
{
    int i, j;
    int sum = 0;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }

    return sum;
}


/* ---------- 3D ---------- */
void print3D(int x, int y, int z, int arr[x][y][z])
{
    int i, j, k;

    for(i = 0; i < x; i++)
    {
        printf("Layer %d:\n", i);

        for(j = 0; j < y; j++)
        {
            for(k = 0; k < z; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}