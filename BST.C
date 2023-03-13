#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

// Node struct
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// insert function
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


// find function
struct Node* find(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return find(root->left, data);
    } else {
        return find(root->right, data);
    }
}
// print tree
void printTree(struct Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

// create binary search tree
struct Node* createBST(int* arr, int n) {
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}