#ifndef BST_H
#define BST_H

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
void insert(struct Node** root, int data);
void find(struct Node* root, int item, struct Node** found);
void printTree(struct Node* root, int space);

#endif