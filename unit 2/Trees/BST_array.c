#include<stdio.h>
#include<stdlib.h>
// bst implementation using arrays

#define TREE_SIZE 40;

void bst_intialize(int *bst){
    for(int i=0; i < TREE_SIZEl; ++i){
        bst[i] = 0;
    }
}

void bst_insert(int *bst, int data){
    int i=0;

    //empty tree
    if(bst[i] == 0){
        bst[i] = data;
        return;
    }
    else{
        while(i<  TREE_SIZE && bst[i] != 0) {
            if(data < bst[i])
                i = 2*i + 1;
            else    
                i = 2*i + 2;
        }
    }
    if(i > TREE_SIZE){
        printf("Tree is full\n");
        return
    }

}
void preodrer(int *bst, int i){
    if(bst[i] != 0 ) {
        printf("%d-->",bst[i]);
        preorder(bst,2*i +1);
        preorder(bst,2*i +2);
    }
}
void preorder_t(int *bst){
    preorder(bst,0);
}

void inorder(int *bst, int i){
    if(bst[i] != 0 ) {
        inorder(bst,2*i +1);
        printf("%d-->",bst[i]);
        inorder(bst,2*i +2);
    }
}
void inorder_t(int *bst){
    inorder(bst,0);
}

void postorder(int *bst, int i){
    if(bst[i] != 0 ) {
        postorder(bst,2*i +1);
        postorder(bst,2*i +2);
        printf("%d-->",bst[i]);
    }
}
void postorder_t(int *bst){
    postorder(bst,0);
}

int main(){
    int binary_tree[TREE_SIZE];
    bst_intialize(binary_tree);
    bst_insert(binary_tree,data);
    return 0;
}
