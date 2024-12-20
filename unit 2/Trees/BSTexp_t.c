
//tree traversal
// inorder -> [algorithm : proceed as left as possible in the tree and start iterating using inorder method to obtain the expression]
// if we use the postorder method we get the postfix form for the expression [note: requires two stacks]

//code for the following
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char ch;
    struct node *left, *right;
}Node;

typedef struct tree{
    Node *root;
}Tree;

Node *create_node(int ch){
    Node *newnode - (Node*)malloc(sizeof(Node));
    newnode->ch = ch;
    newnode->left=newnode->right = NULL;
    return newnode;
}

void insert(Tree *tree, int data) {
    Node *temp
    temp = tree->root;
    Node *newnode = createnode(data);

    if (temp == NULL) {
        tree->root = newNode;
        return;
    } else {
        while (1) {
            if(data < temp->data){
                if(temp->left == NULL)
                    temp->left = newnode;
                    return;}

                else{
                    temp= temp->left;
                }
            else{
                if(temp->right == NULL){
                    temp->right = newnode;
                    return;
                }
                else{
                    temp = temp->right;
                }
            }
        }
}