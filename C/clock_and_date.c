/* clock_and_date.c */

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t currentTime;

    time(&currentTime);

    printf("Seconds since 1.01.1970: %ld\n", (long)currentTime);

    struct tm *nowUTC = gmtime(&currentTime);

    if (nowUTC == NULL)
    {
        printf("Error converting time\n");
        return 1;
    }

    printf("UTC: %02d:%02d:%02d\n", nowUTC->tm_hour, nowUTC->tm_min, nowUTC->tm_sec);

    printf("asctime(): %s", asctime(nowUTC));
    printf("ctime()  : %s", ctime(&currentTime));

    return 0;
}