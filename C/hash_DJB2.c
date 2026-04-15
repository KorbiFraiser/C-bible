/* hash_DJB2.c */

#include <stdio.h>

unsigned long simple_hash(const char *str);


int main()
{
    char input[256];

    printf("Enter a string: ");
    scanf("%255s", input);

    printf("Hash value: %lu\n", simple_hash(input));

    return 0;
}


unsigned long simple_hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}