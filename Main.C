#include <stdio.h> // input-output library
#include <stdlib.h> // standard library
#include "BST.C"
#include <time.h>

int main() {
    
    // create the binary search tree
    struct Node* root = NULL;
    
    
    // seed the random number generator
    srand(time(NULL));
    
    // insert 10 random numbers between 1 and 20 into the tree
    for (int i = 0; i < 10; i++) {
        int num = rand() % 20 + 1;
        root = insert(root, num);
    }
    // search for an item in the tree
    int item = 3;
    struct Node* found = find(root, item);
    if (found != NULL) {
        printf("Found item %d in the tree!\n", item);
    } else {
        printf("Item %d not found in the tree.\n", item);
    }
    
    // print the structure of the tree
    printf("Tree structure:\n");
    printTree(root, 0);
    
    
    return 0;
}