#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;  // Initialize head to NULL

void insertbeg(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;

    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        struct node* q = head;
        temp->next = q;
        head = temp;
        
    }
}

void insertend(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* q = head;
    temp->data = item;

    if (head == NULL) {
        head = temp;
        temp->next = head;
        return;
    }

    while (q->next != head) {
        q = q->next;
    }
    q->next = temp;
    temp->next = head;
}

void insertpos(int pos, int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    struct node* q = head;

    if (head == NULL) {
        if (pos == 0) {
            head = temp;
            temp->next = head;
        } else {
            printf("List is empty, position out of bounds\n");
        }
        return;
    }

    if (pos == 0) {
        temp->next = q;
        head = temp;
        return;
    }

    for (int i = 0; i < pos - 1 && q!= head; i++) {
        q = q->next;
    }

    if (q->next == head && pos != 1) {
        printf("Position out of bounds\n");
        free(temp);  // Free memory if not used
        return;
    }

    temp->next = q->next;
    q->next = temp;
}

void deletebeg() {
    if (head == NULL) {
        printf("Nothing to delete, list is empty\n");
        return;
    }

    struct node* q = head;
    if (q->next == head) {
        free(q);
        head = NULL;
    } else {
        struct node* temp = head;
        head = temp->next;
        free(temp);
    }
}

void deleteend() {
    if (head == NULL) {
        printf("Nothing to delete, list is empty\n");
        return;
    }

    struct node* q = head;
    if (q->next == head) {
        free(q);
        head = NULL;
        return;
    }

    struct node* temp = NULL;
    while (q->next != head) {
        temp = q;
        q = q->next;
    }
    temp->next = head;
    free(q);
}

void deletepos(int pos) {
    if (head == NULL) {
        printf("Nothing to delete, list is empty\n");
        return;
    }

    if (pos == 0) {
        deletebeg();
        return;
    }

    struct node* q = head;
    for (int i = 0; i < pos - 1 && q != head; i++) {
        q = q->next;
    }

    if (q->next == head) {
        printf("Position out of bounds\n");
        return;
    }

    struct node* temp = q->next;
    q->next = temp->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* q = head;
    do {
        printf("%d---->", q->data);
        q = q->next;
    } while (q != head);
    printf("\n");
}

int main() {
    int ch, item, pos;
    printf("This is a circular linked list\n");

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
