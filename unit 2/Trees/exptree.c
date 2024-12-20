//expression tree using stack implementation
DEFINE STACK_SIZE 20;

typedef struct node{
    char ch;
    struct node *left, *right;
}Node;

typedef struct tree{
    Node *root;
}Tree;

Node *create_node(char ch){
    Node *newnode - (Node*)malloc(sizeof(Node));
    newnode->ch = ch;
    newnode->left=newnode->right = NULL;
    return newnode;
}

//intialize tree
Tree *init(){
    Tree *newtree = (Tree*)malloc(sizeof(Tree));
    newtree->root = NULL;
    return newtree;
}

//destroy tree
void destroy(Tree *tree){
    if(tree == NULL) return;
    destroynodes(tree->root);
    free(tree);
}

void destroynodes(Node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        free(root);
        return;
    }
    if(root->left != NULL)
        destroynodes(root->left);
    if(root->right != NULL){
        destroynodes(root->right);
    }
}


void create_exptree(Tree *tree, char *exp) {
    char ch;
    Node *stack[STACK_SIZE];
    int top = -1;
    Node *temp = NULL;
    for(int i = 0; exp[i]!=0; i++) {
        ch = exp[i];
        temp = createnode(ch);

        if(is_oper(ch )){
            temp->right = pop(stack, &top);
            temp->left = pop(stack, &top);

            push(stack , temp, &top);
        }
        else{
            push(stack,temp,&top);
        }

    }
    tree->root = pop(stack, &top);
    stackdestroy(stack,top);
}

//preorder function
//inorder function
//postorder function

//isoper function [to check if a char is an operator or not]

//function to evaluate the tree
int evaluate_t(Tree *tree){
    if(tree == NULL || tree->root == NULL) return 0;
    return evaluate(tree->root);
}

int evaluate(Node *root){
    int x;

}

