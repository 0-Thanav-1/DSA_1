// Given a binary tree, perform a level order traversal and return the values of nodes at each level from left to right. 
// The level order traversal is a breadth-first traversal method where nodes are visited level by level.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    if (data == -1) {
        return NULL;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int currentLevelCount = rear - front;

        for (int i = 0; i < currentLevelCount; i++) {
            struct Node* current = queue[front++];
            printf("%d ", current->data);

            if (current->left) {
                queue[rear++] = current->left;
            }

            if (current->right) {
                queue[rear++] = current->right;
            }
        }

        printf("\n");
    }

    free(queue);
}

struct Node* buildTree(int* values, int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(values[0]);
    if (root == NULL) return NULL; // Check if root creation failed

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];

        if (i < n) {
            current->left = createNode(values[i++]);
            if (current->left) {
                queue[rear++] = current->left;
            }
        }

        if (i < n) {
            current->right = createNode(values[i++]);
            if (current->right) {
                queue[rear++] = current->right;
            }
        }
    }

    free(queue);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 1000) {
        fprintf(stderr, "Invalid number of nodes.\n");
        return EXIT_FAILURE;
    }

    int* values = (int*)malloc(n * sizeof(int));
    if (!values) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    struct Node* root = buildTree(values, n);
    levelOrderTraversal(root);

    free(values);
    return 0;
}




