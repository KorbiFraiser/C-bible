/* recursion_example.c */

#include <stdio.h>

int fak(int n);


int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative numbers!\n");
        return 1;
    }

    printf("%d! = %d\n", n, fak(n));

    return 0;
}


int fak(int n)
{
    if (n <= 1)
        return 1;

    return n * fak(n - 1);
}