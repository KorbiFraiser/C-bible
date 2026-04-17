/* input_money.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    int euros, cents;
    
    int totalCents;
    int valid = 0;

    while(!valid)
    {
        printf("Enter amount of money: ");

        if(fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input error.\n");
            continue;
        }

        // Remove newline
        input[strcspn(input, "\n")] = '\0';

        // Check: Format "xx.yy"
        if(sscanf(input, "%d.%d", &euros, &cents) != 2)
        {
            printf("Invalid format. Use format like 32.12\n");
            continue;
        }

        // Prevent negative values
        if(euros < 0 || cents < 0)
        {
            printf("Negative values are not allowed.\n");
            continue;
        }

        // Check cent range (0–99)
        if(cents > 99)
        {
            printf("Invalid cents (must be 00–99).\n");
            continue;
        }

        totalCents = euros * 100 + cents;
        valid = 1;
    }

    printf("You entered: %d.%02d\n", totalCents / 100, totalCents % 100);
    printf("Stored as integer (cents): %d\n", totalCents);

    return 0;
}