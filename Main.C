#include <stdio.h> // input-output library

#include "BST.C"

int main() {
    int arr[] = {5, 2, 8, 1, 3, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = createBST(arr, n);
    printf("Binary Search Tree: ");
    printTree(root);
    printf("\n");
    int searchValue = 6;
    struct Node* searchResult = find(root, searchValue);
    if (searchResult != NULL) {
        printf("Found value %d in tree!\n", searchValue);
    } else {
        printf("Value %d not found in tree.\n", searchValue);
    }
    
    return 0;
}