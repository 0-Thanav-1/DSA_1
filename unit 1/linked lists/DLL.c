#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void insertbeg(int item) {


    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data= item;
    if(head == NULL){
        head = temp;
        temp->next=NULL;
        temp->prev=NULL;
        
    }
    else{
        temp->next=head;
        temp->prev=NULL;
        head->prev= temp;
        head=temp;
    }
}

void insertend(int item) {
     struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data= item;
    if(head == NULL){
        head = temp;
        temp->next=NULL;
        temp->prev=NULL;
        
    }
  
    else{
        struct node* q = head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=temp;
        temp->prev=q;
        temp->next=NULL;

    }
}


void insertpos(int pos,int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data= item;
    struct node* q= head;
    if(head==NULL){
        head=temp;
        temp->prev=NULL;
        temp->next=NULL;
        return;
    }

    if(pos == 0){
        temp->next =head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
        return;
    }
 
    for(int i =0; i< pos-1 && q != NULL; i++){
        q=q->next;
    }
    if(q->next == NULL && pos != 1){
        printf("list is out of bounds\n");
        free(temp);
        return;
    }
    temp->next=q->next;
    temp->prev=q;
    if(q->next != NULL){
        q->next->prev=temp;
    }
    q->next=temp;
}



int main() {
    int ch, item, pos;
    printf("This is a doubly linked list\n");

    while (1) {
        display();

        printf("1. Insert @ beginning\n2. Insert @ end\n3. Insert @ position\n4. Delete @ beginning\n5. Delete @ end\n6. Delete @ position\n7. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                printf("Enter the data:\n");
                scanf("%d", &item);
                insertbeg(item);
                break;

            case 2: 
                printf("Enter the data:\n");
                scanf("%d", &item);
                insertend(item);
                break;

            case 3:
                printf("Enter the data:\n");
                scanf("%d", &item);
                printf("Enter the position:\n");
                scanf("%d", &pos);
                insertpos(pos, item);
                break;

            case 4: 
                deletebeg();
                break;

            case 5: 
                deleteend();
                break;

            case 6:
                printf("Enter the position:\n");
                scanf("%d", &pos);
                deletepos(pos);
                break;

            case 7:
                return 0;

            default:
                printf("Bad choice, try again\n");
                break;
        }
    }
    return 0;
}
