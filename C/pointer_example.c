/* pointer_example.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// struct for Example 2
typedef struct Node
{
    void *data;
    struct Node *next;
}Node;


void append(Node **head, void *data);
void printIntList(Node *head);
void removeLast(Node **head);
void freeList(Node **head);
void swap(int *a, int *b);
void modifyArray(int arr[], int size);
void modifyMatrix(int rows, int cols, int arr[rows][cols]);
void novowels(char *s);
int fakultaet(int n);


int main(void)
{
    int example_counter = 1;
    int i, j;


    // --------------------- EXAMPLE 1 --------------------------
    char filename[256];
    FILE *file;
    int ch;

    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    // read file names (including spaces)

    //printf("Input txt-file: ");
    //fgets(filename, sizeof(filename), stdin);
    strcpy(filename, "test_text.txt");

    // remove the newline character from fgets
    filename[strcspn(filename, "\n")] = '\0';

    // open file
    file = fopen(filename, "r");

    if(file == NULL)
    {
        printf("ERROR Can't open file: %s\n", filename);
        return 1;
    }

    // print file
    printf("\nprint File contents:\n");

    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    // close file
    fclose(file);

    printf("\n\n");

    // --------------------- EXAMPLE 2 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    Node *list = NULL;
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 45;

    append(&list, &a);
    append(&list, &b);
    append(&list, &c);
    append(&list, &d);
    
    printIntList(list);
    removeLast(&list);

    printIntList(list);
    freeList(&list);


    printf("\n");
    
    // --------------------- EXAMPLE 3 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    int var_a = 10;
    int var_b = 20;

    printf("Before: var_a = %d / var_b = %d\n", var_a, var_b);
    swap(&var_a, &var_b);
    printf("After: var_a = %d / var_b = %d\n\n", var_a, var_b);


    // --------------------- EXAMPLE 4 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);
    
    int array_a[] = {1, 2, 3, 4, 5};
    int size_a = sizeof(array_a) / sizeof(array_a[0]);

    modifyArray(array_a, size_a);

    for (i = 0; i < size_a; i++)
    {
        printf("%d ", array_a[i]);
    }
    printf("\n\n");

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    modifyMatrix(2, 3, matrix);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --------------------- EXAMPLE 5 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    char phrase[] = "Weg mit den Vokalen in Fredonia!";

    printf("before purge: %s\n", phrase);
    novowels(phrase);
    printf("after purge : %s\n\n", phrase);


    // --------------------- EXAMPLE 6 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    char str[20] = "Hello";
    char str2[] = " world!!!";

    char src[] = "test";
    char src2[] = "Hello world!";
    char dest[20];
    char dest2[6];

    char str_a[] = "abc";
    char str_b[] = "abc";

    char searchString[] = "You can't find me you fool!";

    printf("length: %lu\n", strlen(str));
    strcpy(dest, src);
    printf("%s\n", dest);


    strncpy(dest2, src2, 5);
    dest2[5] = '\0';   // important!
    printf("%s\n", dest2);


    strcat(str, str2);
    printf("%s\n", str);

    if(strcmp(str_a, str_b) == 0)
    {
        printf("EQUAL\n");
    }


    char *pos = strchr(searchString, 'f');

    if (pos != NULL)
    {
        printf("find it: %s\n", pos);
    }


    // --------------------- EXAMPLE 7 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    time_t now = time(NULL);
    struct tm *info = localtime(&now);

    printf("Datum: %02d.%02d.%d\n\n", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);


    // --------------------- EXAMPLE 8 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);


    srand(time(NULL));

    for (int i = 1; i <= 3; i++)
    {
        int dice = rand() % 6 + 1;

        printf("dice %d: %d\n", i, dice);
    }
    printf("\n");


    // --------------------- EXAMPLE 9 --------------------------
    printf("-------- EXAMPLE %i --------\n\n", example_counter++);

    int n = 6;

    printf("%d! = %d\n", n, fakultaet(n));


    // --------------------- END PROG --------------------------
    printf("\nEXIT PROGRAM\n");
    return 0;
}


// func for Example 2: add element
void append(Node **head, void *data)
{
    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}


// func for Example 2: print list for int
void printIntList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", *(int*)temp->data);  // cast!
        temp = temp->next;
    }
    printf("\n");
}


// func for Example 2: remove last element from list
void removeLast(Node **head)
{
    if (*head == NULL)
    {
        return; // list is empty
    }

    Node *temp = *head;
    Node *prev = NULL;

    // If only one element exists
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    // Run until the last element
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // The previous element is now before the last element.
    prev->next = NULL;

    // Release last element
    free(temp);
}


// func for Example 2: cleaning up
void freeList(Node **head)
{
    Node *temp = *head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
}


// func for Example 3: swap 2 values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// func for Example 4: modifyArray
void modifyArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= 2;   // the original will be altered

    }
}


// func for Example 4: modifyMatrix
void modifyMatrix(int rows, int cols, int arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] += 1;
        }
    }
}


// func for Example 5: show some array arithmetic
void novowels(char *s)
{
    for (; *s; s++)
    {
        switch (toupper((unsigned char)*s))
        {
            case 'A': *s = '&'; break;
            case 'E': *s = '@'; break;
            case 'I': *s = '#'; break;
            case 'O': *s = '$'; break;
            case 'U': *s = '%'; break;
        }
    }
}


// func for Example 9: recursive function for calc faculty
int fakultaet(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;   // Termination condition
    }

    return n * fakultaet(n - 1);
}