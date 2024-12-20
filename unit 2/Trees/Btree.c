#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


//function to delete a node in a tree
struct node *delete(struct node **t,int key){
    struct node *prev,*cur,*q;
    prev=NULL;
    cur=*t;
    while(cur != NULL && key != cur->data){ 
        prev = cur;
        if(key < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if(cur == NULL)
        return *t;
    if(cur->left == NULL || cur->right == NULL){
        if(cur->left == NULL)
            q=cur->right;
        else    
            q = cur->left;
    }

    if(prev->left == cur)
        prev->left = q;
    else
        prev->right = q;

    free(cur)
};


void insert(struct node **t, int x) {
    struct node *temp, *prev, *cur;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    if (*t == NULL) {
        *t = temp;
    } else {
        prev = NULL;
        cur = *t;

        // Traverse the tree to find the appropriate position to insert
        while (cur != NULL) {
            prev = cur;
            if (x < cur->data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        // Insert the new node
        if (x < prev->data) {
            prev->left = temp;
        } else {
            prev->right = temp;
        }
    }
}

void preorder(struct node *t) {
    if (t != NULL) {
        printf("%d - ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(struct node *t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d - ", t->data);
        inorder(t->right);
    }
}

void postorder(struct node *t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d - ", t->data);
    }
}

int main() {
    struct node *root;
    root = NULL;
    int ch;
    int x;

    while (1) {
        printf("\n1. Insert\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value of data\n");
                scanf("%d", &x);
                insert(&root, x);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-Order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-Order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
