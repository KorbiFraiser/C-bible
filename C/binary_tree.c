/* binary_tree.c */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;


Node* createNode(int value);
Node* insert(Node *root, int value);
void inorder(Node *root);
void preorder(Node *root);

void postorder(Node *root);
void freeTree(Node *root);
void printTree(Node *root, int space);

int main()
{
    Node *root = NULL;

    int values[] = {5, 3, 8, 1, 4, 7, 9};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    printf("Inorder (sorted): ");
    inorder(root);
    printf("\n");

    printf("Preorder        : ");
    preorder(root);
    printf("\n");

    printf("Postorder       : ");
    postorder(root);
    printf("\n");

    printf("\nASCII Tree:\n");
    printTree(root, 0);

    freeTree(root);

    return 0;
}


Node* createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


Node* insert(Node *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}


void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


void freeTree(Node *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


void printTree(Node *root, int space)
{
    if (root == NULL)
        return;

    space += 5;

    // right subtree (top)
    printTree(root->right, space);

    // current node
    printf("\n");

    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    // left subtree (bottom)
    printTree(root->left, space);
}