/* c_strings.c */

#include <stdio.h>
#include <string.h>

int main(void)
{
    // basis-strings 
    char str1[50] = "Hello";
    char str2[] = " World!";
    char copy[50];
    char buffer[50];

    printf("=== STRING MANIPULATION DEMO ===\n\n");

    // 1. strlen
    printf("1) strlen\n");
    printf("Length of str1 = %lu\n\n", strlen(str1));

    // 2. strcpy
    printf("2) strcpy\n");
    strcpy(copy, str1);
    printf("copy = %s\n\n", copy);

    // 3. strncpy
    printf("3) strncpy\n");
    strncpy(buffer, "C Programming", 5);
    buffer[5] = '\0';
    printf("buffer = %s\n\n", buffer);

    // 4. strcat
    printf("4) strcat\n");
    strcat(str1, str2);
    printf("str1 = %s\n\n", str1);

    // 5. strcmp
    printf("5) strcmp\n");
    char a[] = "abc";
    char b[] = "abc";
    char c[] = "abd";

    printf("abc vs abc = %d\n", strcmp(a, b)); // 0 = equal
    printf("abc vs abd = %d\n\n", strcmp(a, c)); // <0 or >0

    // 6. strchr
    printf("6) strchr\n");
    char text[] = "Hello World";
    char *pos = strchr(text, 'W');

    if (pos != NULL)
    {
        printf("Found 'W': %s\n\n", pos);
    }

    // 7. strstr
    printf("7) strstr\n");
    char text2[] = "I love programming in C";
    char *sub = strstr(text2, "program");

    if (sub != NULL)
    {
        printf("Substring found: %s\n\n", sub);
    }

    // 8. strtok
    printf("8) strtok\n");
    char sentence[] = "C is fast and powerful";
    char *token = strtok(sentence, " ");

    while(token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    printf("\n=== END ===\n");

    return 0;
}