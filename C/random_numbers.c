/* random_numbers.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int i;

    // set seed (important!)
    srand(time(NULL));

    printf("=== RANDOM NUMBERS DEMO ===\n\n");

    // 1. Random numbers 0 - RAND_MAX
    printf("Raw rand(): %d\n\n", rand());

    // 2. Random numbers 0 - 9
    printf("Random 0-9:\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d ", rand() % 10);
    }
    printf("\n\n");

    // 3. Random numbers 1 - 6 (dice)
    printf("Dice (1-6):\n");

    for (i = 0; i < 5; i++)
    {
        int dice = rand() % 6 + 1;
        printf("%d ", dice);
    }
    printf("\n\n");

    // 4. Random numbers in range [min, max]
    int min = 50;
    int max = 100;

    printf("Random %d - %d:\n", min, max);

    for (i = 0; i < 5; i++)
    {
        int r = rand() % (max - min + 1) + min;
        printf("%d ", r);
    }
    printf("\n\n");

    // 5. Random numbers as float (0.0 - 1.0)
    printf("Random float (0.0 - 1.0):\n");

    for (i = 0; i < 5; i++)
    {
        double f = (double)rand() / RAND_MAX;
        printf("%.3f ", f);
    }
    printf("\n");

    return 0;
}
