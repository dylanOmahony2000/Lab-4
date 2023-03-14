#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data <= (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

void find(struct Node* root, int item, struct Node** found) {
    if (root == NULL) {
        return;
    } else if (root->data == item) {
        *found = root;
    } else if (item < root->data) {
        find(root->left, item, found);
    } else {
        find(root->right, item, found);
    }
}
// print tree
void printTree(struct Node* root, int depth) {
    if (root != NULL) {
        printTree(root->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%d\n", root->data);
        printTree(root->left, depth + 1);
    }
}