#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include <time.h>

int main() {

    // create the binary search tree
    struct Node* root = NULL;

    // create seed for random number
    srand(time(NULL));

    // insert 10 random numbers between 1 and 20 into the tree
    for (int i = 0; i < 10; i++) {
        int num = rand() % 20 + 1;
        insert(&root, num);
    }

    // search for an item in the tree
    int item = 3;
    struct Node* found = NULL;
    find(root, item, &found);
    if (found != NULL) {
        printf("Found item %d in the tree!\n", item);
    } else {
        printf("Item %d not found in the tree.\n", item);
    }

    // print the structure of the tree
    printf("The root is the left most node:\n");
    printf("Tree structure:\n");
    printTree(root, 0);

    return 0;
}