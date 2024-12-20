#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

typedef struct tree {
    Node *root;
} Tree;

void init(Tree *tree);
void insert(Tree *tree, int data);
void rinsert_t(Tree *t, int key);
Node* rinsert(Node *root, int key);
void preorder_t(Tree *tree);
void preorder(Node *root);
void inorder_t(Tree *tree);
void inorder(Node *root);
void postorder_t(Tree *tree);
void postorder(Node *root);
int min(Tree *tree);
int max(Tree *tree);
int height_t(Tree *tree);
int height(Node *root);
int leafcount_t(Tree *tree);
int leafcount(Node *root);
int count_t(Tree *tree);
int count(Node *root);
int search(Tree *tree, int key);
int rsearch_t(Tree *tree, int key);
int rsearch(Node *root, int key);
void delete(Tree *tree, int key);

void init(Tree *tree) {
    tree->root = NULL;
}

void insert(Tree *tree, int data) {
    Node *curr, *prev, *newNode;
    curr = tree->root;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (curr == NULL) {
        tree->root = newNode;
    } else {
        while (curr != NULL) {
            prev = curr;
            if (data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (data > prev->data)
            prev->right = newNode;
        else
            prev->left = newNode;
    }
}

void rinsert_t(Tree *t, int key) {
    t->root = rinsert(t->root, key);
}

Node* rinsert(Node *root, int key) {
    Node *temp;
    if (root == NULL) {
        temp = (Node*)malloc(sizeof(Node));
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (key < root->data)
        root->left = rinsert(root->left, key);
    else
        root->right = rinsert(root->right, key);
    return root;
}

void preorder_t(Tree *tree) {
    preorder(tree->root);
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d-->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder_t(Tree *tree) {
    inorder(tree->root);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d-->", root->data);
        inorder(root->right);
    }
}

void postorder_t(Tree *tree) {
    postorder(tree->root);
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d-->", root->data);
    }
}

int min(Tree *tree) {
    Node *root = tree->root;
    if (root == NULL) {
        printf("Empty tree\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int max(Tree *tree) {
    Node *root = tree->root;
    if (root == NULL) {
        printf("Empty tree\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int height_t(Tree *tree) {
    return height(tree->root);
}

int height(Node *root) {
    int l, r;
    if (root == NULL) {
        return -1;
    }
    l = height(root->left);
    r = height(root->right);
    return (l > r) ? (l + 1) : (r + 1);
}

int leafcount_t(Tree *tree) {
    return leafcount(tree->root);
}

int leafcount(Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return leafcount(root->left) + leafcount(root->right);
}

int count_t(Tree *tree) {
    return count(tree->root);
}

int count(Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return count(root->left) + count(root->right) + 1;
}

int search(Tree *tree, int key) {
    Node *curr = tree->root;
    while (curr != NULL && curr->data != key) {
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return (curr != NULL && curr->data == key);
}

int rsearch_t(Tree *tree, int key) {
    return rsearch(tree->root, key);
}

int rsearch(Node *root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return rsearch(root->left, key);
    else
        return rsearch(root->right, key);
}

void delete(Tree *tree, int key) {
    Node *curr = tree->root, *prev = NULL, *q, *p, *temp;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr == NULL) {
        printf("Key not found\n");
        return;
    }
    if (curr->left == NULL || curr->right == NULL) {
        q = (curr->left == NULL) ? curr->right : curr->left;
        if (prev == NULL)
            tree->root = q;
        else if (curr == prev->left)
            prev->left = q;
        else
            prev->right = q;
        free(curr);
    } else {
        p = NULL;
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
        curr->data = temp->data;
        if (p != NULL)
            p->left = temp->right;
        else
            curr->right = temp->right;
        free(temp);
    }
}

int main() {
    Tree t;
    int ch, num, k, n;
    init(&t);
    while (1) {
        printf("\n1.Insert");
        printf("\n2.Preorder");
        printf("\n3.Postorder");
        printf("\n4.Inorder");
        printf("\n5.No. of nodes");
        printf("\n6.No. of Leaf nodes");
        printf("\n7.Height of a tree");
        printf("\n8.Delete a node");
        printf("\n9.Recursively insert");
        printf("\n10.Search");
        printf("\n11.Search using recursion");
        printf("\n12.Delete a node");
        printf("\n13.Find smallest");
        printf("\n14.Find largest");
        printf("\n15.Exit");
        printf("\nEnter the value:")
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &num);
                insert(&t, num);
                break;
            case 2:
                preorder_t(&t);
                break;
            case 3:
                postorder_t(&t);
                break;
            case 4:
                inorder_t(&t);
                break;
            case 5:
                k = count_t(&t);
                printf("\nThe number of nodes = %d", k);
                break;
            case 6:
                k = leafcount_t(&t);
                printf("\nThe number of leaf nodes = %d", k);
                break;
            case 7:
                k = height_t(&t);
                printf("\nThe height of tree = %d", k);
                break;
            case 8:
                printf("Enter the node to be deleted\n");
                scanf("%d", &num);
                delete(&t, num);
                break;
            case 9:
                printf("Enter the element: ");
                scanf("%d", &num);
                rinsert_t(&t, num);
                break;
            case 10:
                printf("Enter the element: ");
                scanf("%d", &num);
                k = search(&t, num);
                if (k)
                    printf("Key found\n");
                else
                    printf("Not found..\n");
                break;
            case 11:
                printf("Enter the element: ");
                scanf("%d", &num);
                k = rsearch_t(&t, num);
                if (k)
                    printf("Key found\n");
                else
                    printf("Not found..\n");
                break;
            case 12:
                printf("Enter the node to be deleted\n");
                scanf("%d", &num);
                delete(&t, num);
                break;
            case 13:
                n = min(&t);
                printf("\nThe smallest element is %d", n);
                break;
            case 14:
                n = max(&t);
                printf("\nThe largest element is %d", n);
                break;
            case 15:
                exit(0);
        }
    }
    return 0;
}
