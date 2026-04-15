/* dynamic_arrays.c */

#include <stdio.h>
#include <stdlib.h>

/* ---------- 1D ARRAY ---------- */
int* create1D(int n);
void fill1D(int *arr, int n);
void print1D(int *arr, int n);
void free1D(int *arr);

/* ---------- 2D ARRAY ---------- */
int** create2D(int rows, int cols);
void fill2D(int **arr, int rows, int cols);
void print2D(int **arr, int rows, int cols);
void free2D(int **arr, int rows);

/* ---------- 3D ARRAY ---------- */
int*** create3D(int x, int y, int z);
void fill3D(int ***arr, int x, int y, int z);
void print3D(int ***arr, int x, int y, int z);
void free3D(int ***arr, int x, int y);


int main(void)
{
    int *arr1D;
    int **arr2D;
    int ***arr3D;

    /* ================= 1D ================= */
    printf("=== 1D ARRAY ===\n");

    arr1D = create1D(5);
    fill1D(arr1D, 5);
    print1D(arr1D, 5);
    free1D(arr1D);

    /* ================= 2D ================= */
    printf("\n=== 2D ARRAY ===\n");

    arr2D = create2D(3, 4);
    fill2D(arr2D, 3, 4);
    print2D(arr2D, 3, 4);
    free2D(arr2D, 3);

    /* ================= 3D ================= */
    printf("\n=== 3D ARRAY ===\n");

    arr3D = create3D(2, 3, 4);
    fill3D(arr3D, 2, 3, 4);
    print3D(arr3D, 2, 3, 4);
    free3D(arr3D, 2, 3);

    return 0;
}


/* ================= 1D ================= */
int* create1D(int n)
{
    int *arr = malloc(n * sizeof(*arr));

    if (!arr)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    return arr;
}


void fill1D(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = i + 1;
}


void print1D(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


void free1D(int *arr)
{
    free(arr);
}


/* ================= 2D ================= */
int** create2D(int rows, int cols)
{
    int **arr = malloc(rows * sizeof(*arr));
    int i, j;

    if (!arr)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < rows; i++)
    {
        arr[i] = malloc(cols * sizeof(*arr[i]));

        if (!arr[i])
        {
            perror("malloc failed");

            for (j = 0; j < i; j++)
                free(arr[j]);

            free(arr);
            exit(EXIT_FAILURE);
        }
    }

    return arr;
}


void fill2D(int **arr, int rows, int cols)
{
    int i, j;
    int val = 1;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            arr[i][j] = val++;
}


void print2D(int **arr, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%3d ", arr[i][j]);

        printf("\n");
    }
}


void free2D(int **arr, int rows)
{
    int i;

    for (i = 0; i < rows; i++)
        free(arr[i]);

    free(arr);
}


/* ================= 3D ================= */
int*** create3D(int x, int y, int z)
{
    int ***arr = malloc(x * sizeof(*arr));
    int i, j, k, ii, jj;

    if (!arr)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < x; i++)
    {
        arr[i] = malloc(y * sizeof(*arr[i]));

        if (!arr[i])
        {
            perror("malloc failed");

            for (k = 0; k < i; k++)
                free(arr[k]);

            free(arr);
            exit(EXIT_FAILURE);
        }

        for (j = 0; j < y; j++)
        {
            arr[i][j] = malloc(z * sizeof(*arr[i][j]));

            if (!arr[i][j])
            {
                perror("malloc failed");

                for (jj = 0; jj < j; jj++)
                    free(arr[i][jj]);

                for (ii = 0; ii < i; ii++)
                {
                    for (jj = 0; jj < y; jj++)
                        free(arr[ii][jj]);

                    free(arr[ii]);
                }

                free(arr[i]);
                free(arr);
                exit(EXIT_FAILURE);
            }
        }
    }

    return arr;
}


void fill3D(int ***arr, int x, int y, int z)
{
    int i, j, k;
    int val = 1;

    for (i = 0; i < x; i++)
        for (j = 0; j < y; j++)
            for (k = 0; k < z; k++)
                arr[i][j][k] = val++;
}


void print3D(int ***arr, int x, int y, int z)
{
    int i, j, k;

    for (i = 0; i < x; i++)
    {
        printf("Layer %d:\n", i);

        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
                printf("%3d ", arr[i][j][k]);

            printf("\n");
        }
        printf("\n");
    }
}


void free3D(int ***arr, int x, int y)
{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
            free(arr[i][j]);

        free(arr[i]);
    }

    free(arr);
}