/* own_timer.c */

#include <stdio.h>
#include <time.h>

int main(void)
{
    int seconds;

    printf("Enter waiting time in seconds: ");
    scanf("%d", &seconds);

    printf("Timer start:\n");

    time_t start = time(NULL);

    int printed = 0;

    while (printed < seconds)
    {
        time_t now = time(NULL);

        if (now - start >= 1)
        {
            printf("*");
            fflush(stdout);

            start = now;   // start new second
            printed++;
        }
    }

    printf("\nfinished!\n");

    return 0;
}