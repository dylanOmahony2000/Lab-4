#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>

// Node struct
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// create Node
void createNode(struct Node **newNode, int data)
{
    *newNode = (struct Node *)malloc(sizeof(struct Node));
    (*newNode)->data = data;
    (*newNode)->left = NULL;
    (*newNode)->right = NULL;
}

// insert function
void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        insert(&(*root)->right, data);
    }
}

// find function
void find(struct Node *root, int data, struct Node **found)
{
    if (root == NULL)
    {
        *found = NULL;
    }
    else if (root->data == data)
    {
        *found = root;
    }
    else if (data < root->data)
    {
        find(root->left, data, found);
    }
    else
    {
        find(root->right, data, found);
    }
}

// print tree
void printTree(struct Node *root, int depth)
{
    if (root != NULL)
    {
        printTree(root->right, depth + 1);
        for (int i = 0; i < depth; i++)
        {
            printf("  ");
        }
        printf("%d\n", root->data);
        printTree(root->left, depth + 1);
    }
}