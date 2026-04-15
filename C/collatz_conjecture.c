/* 
=====================================================
=                                                   =
= ProgName: collatz_conjecture.c                    =
= mathematic Problem                                =
= https://en.wikipedia.org/wiki/Collatz_conjecture  =
=                                                   =
=====================================================
*/

#include <stdio.h>

int main()
{
    long long n;
    long long steps = 0;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    if (n <= 0)
    {
        printf("Please enter a positive integer only.\n");
        return 1;
    }

    printf("Collatz sequence:\n");

    while (n != 1)
    {
        printf("%lld\n", n);

        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }

        steps++;
    }

    printf("1\n");
    steps++;

    printf("\nNumber of steps: %lld\n", steps);

    return 0;
}