//Given a Binary Search Tree (BST), find the Lowest Common Ancestor (LCA) of two given nodes. The Lowest Common 
// Ancestor is the lowest node in the tree that has both the given nodes as descendants, where a node can be a descendant of itself.

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Corrected "struct Node" usage
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE); 
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    struct Node* prev = NULL;
    struct Node* curr = root;
    struct Node* temp = createNode(data);

    if (root == NULL) {
        return temp;
    }

 
    while (curr != NULL) {
        prev = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (data < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }

    return root;
}

// Function to find the Lowest Common Ancestor (LCA) in a BST
struct Node* findLCA(struct Node* root, int u, int v) {
    if (root == NULL) {
        return NULL;
    }

    if (u < root->data && v < root->data) {
        return findLCA(root->left, u, v);
    }

    if (u > root->data && v > root->data) {
        return findLCA(root->right, u, v);
    }

    return root;
}

int main() {
    int n, u, v;


    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        fprintf(stderr, "Invalid number of nodes.\n");
        return EXIT_FAILURE;
    }

    struct Node* root = NULL;
    int value;

  
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    
    scanf("%d %d", &u, &v);

    struct Node* lca = findLCA(root, u, v);

    if (lca != NULL) {
        printf("%d\n", lca->data);
    } else {
        printf("No LCA found.\n");
    }

    return 0;
}

