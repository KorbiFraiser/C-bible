/*
==============================================
=                                            =
= ProgName: hash_SHA256.c                    =
=                                            =
= HINT: this program only works on linux     =
=                                            =
= for install type in console...             =
= sudo apt update                            =
= sudo apt install libssl-dev                =
=                                            =
= and for compile type...                    =
= gcc hash_SHA256.c -o hash_SHA256 -lcrypto  =
=                                            =
==============================================
*/

#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>


int main()
{
    char input[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline if present
    input[strcspn(input, "\n")] = 0;

    SHA256((unsigned char*)input, strlen(input), hash);

    printf("SHA-256 hash: ");

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }

    printf("\n");

    return 0;
}