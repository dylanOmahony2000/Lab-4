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
    int i = 0;
    while (i < 10) {
        int num = rand() % 20 + 1;
        struct Node* found = NULL;
        find(root, num, &found);
        if (found == NULL) { // number is not in the tree yet
            insert(&root, num);
            i++; // increment i counter, if we insert a unique number
        }
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
    printf("Tree is printed left to right,\n");
    printf("the left most item is the root node\n");
    printf("Tree structure:\n");
    printTree(root, 0);

    return 0;
}