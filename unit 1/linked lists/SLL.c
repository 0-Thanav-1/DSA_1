#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertbeg(int item) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = head;
    head = temp;
}

void insertend(int item) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
    } else {
        struct node* q = head;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = temp;
    }
}

void insertpos(int item, int pos) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    struct node* q = head;

    if(head == NULL) {
        head = temp;
        return;
    }

    if(pos == 0) {
        temp->next = head;
        head = temp;
        return;
    }

    for(int i = 0; i < pos - 1 && q != NULL; i++) {
        q = q->next;
    }

    if(q == NULL) {
        printf("Position out of bounds\n");
        free(temp);
    } else {
        temp->next = q->next;
        q->next = temp;
    }
}

void display() {
    struct node* q = head;
    while(q != NULL) {
        printf("%d---->",q->data);
        q=q->next;
    }
}




void deletebeg(){
    struct node* q = head;
    if(head == NULL){
        printf("Nothing to delete, list is empty\n");
        return;
    }
    
    if(q->next == NULL) {
        free(q);
        head=NULL;
        return;
    }

    else{
        head=q->next;
    }
}


void deleteend() {
    struct node *q;
    struct node *prev;
    q=head;
    if(head == NULL){
        printf("Nothing to delete, list is empty\n");
        return;
    }

    if(q->next == NULL) {
        free(q);
        head=NULL;
        return;
    }

    else{
        
        while(q->next != NULL) {
            prev=q;
            q = q->next;
        }
        
        prev->next = NULL;
        free(q);
    }

}


void deletepos(int pos){
    struct node* q =  head;
    struct node* prev;

    if(head == NULL){
        printf("Nothing to delete, list is empty\n");
        return;
    }

    if(pos == 0){
        head = q->next;
        free(q);
        return;
    }


    for(int i = 0; i < pos - 1 && q != NULL; i++) {
        prev = q;
        q=q->next;
    }
    
    if(q == NULL){
        printf("list out of bound\n");
        return;
    }

    prev->next = q->next;
    free(q);

}


int main() {
    int ch, item, pos;
    printf("This is a singly linked list\n");
    while(1) {
        display();

    printf("1. Insert @ beginning\n2. Insert @ end\n3. Insert @ position\n4. Delete @ beginning\n5. Delete @ end\n6. Delete @ position\n7. Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &ch);

    
    switch(ch) {
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
            insertpos(item, pos);
            break;

        case 4: 
            printf("deleting the first node of the list:)");
            deletebeg();
            break;

         case 5: 
            printf("deleting the last node of the list:)");
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
