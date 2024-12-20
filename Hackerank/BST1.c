// Given a Binary Search Tree (BST) with n nodes, your task is to find the k-th smallest element in the tree.

// A Binary Search Tree is a tree where for each node, all elements in the left subtree are smaller, and all elements in the right subtree are greater.
// The elements are distinct and there are no duplicate values in the tree.
// You will be given n distinct integers representing the node values of the BST. The node values will be inserted into the tree in the given order. You also need to find the k-th smallest element in the BST after all the nodes have been inserted.


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Definition of a Node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
        return createNode(data);
    
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    
    return root;
}

// Function to find the k-th smallest element in BST using in-order traversal
void findKthSmallest(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;

    findKthSmallest(root->left, k, count, result);
    (*count)++;
    
    if (*count == k) {
        *result = root->data;
        return;
    }

    findKthSmallest(root->right, k, count, result);
}

// Wrapper function to find the k-th smallest element
int kthSmallest(struct Node* root, int k) {
    int count = 0;
    int result = -1;
    findKthSmallest(root, k, &count, &result);
    return result;
}

int main() {
    int n, k, value;
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        return EXIT_FAILURE;
    }

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    scanf("%d", &k);

    int result = kthSmallest(root, k);
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("k is out of bounds.\n");
    }

    return 0;
}
