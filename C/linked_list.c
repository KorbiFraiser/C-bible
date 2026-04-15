/* linked_list.c */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


Node* createNode(int value);
void insert(Node **head, int value);
void deleteValue(Node **head, int value);
Node* search(Node *head, int value);
void printList(Node *head);
void freeList(Node **head);


int main(void)
{
    Node *head = NULL;

    printf("=== Linked List Demo ===\n\n");

    /* INSERT */
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("After inserts: ");
    printList(head);

    /* SEARCH */
    int x = 30;
    Node *found = search(head, x);

    if (found != NULL)
        printf("Search: %d found!\n", x);
    else
        printf("Search: %d not found!\n", x);

    /* DELETE */
    deleteValue(&head, 20);
    printf("After deleting 20: ");
    printList(head);

    deleteValue(&head, 10);
    printf("After deleting 10: ");
    printList(head);

    /* CLEANUP */
    freeList(&head);

    printf("\nProgram finished.\n");

    return 0;
}


/* ---------- Node erstellen ---------- */
Node* createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}


/* ---------- INSERT ---------- */
void insert(Node **head, int value)
{
    Node *newNode = createNode(value);

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


/* ---------- DELETE ---------- */
void deleteValue(Node **head, int value)
{
    if (*head == NULL)
        return;

    Node *temp = *head;
    Node *prev = NULL;

    /* Falls erstes Element */
    if (temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}


/* ---------- SEARCH ---------- */
Node* search(Node *head, int value)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
            return temp;

        temp = temp->next;
    }

    return NULL;
}


/* ---------- PRINT ---------- */
void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


/* ---------- FREE MEMORY ---------- */
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
