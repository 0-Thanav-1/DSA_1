#include<stdio.h>
#include<stdlib.h>
//stack using arrays
void push(int *stack, int *top, int size, int x);
void display(int *stack, int top);
void pop(int *stack, int *top);

int main() {
    int *stack;
    int top = -1;
    int size, ch, x;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    stack = (int*)malloc(size * sizeof(int)); // Stack created in the heap

    while (1) {
        display(stack, top);
        printf("\n1: PUSH \n2: POP\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to be pushed: ");
                scanf("%d", &x);
                push(stack, &top, size, x);
                break;

            case 2:
                pop(stack, &top);
                break;

            default:
                printf("Invalid choice! Exiting...\n");
                exit(0);
        }
    }

    free(stack); // Free allocated memory
    return 0;
}

void push(int *stack, int *top, int size, int x) {
    if (*top == size - 1) {
        printf("Stack overflow\n");
    } else {
        (*top)++; // Increment top
        stack[*top] = x; // Push the element onto the stack
    }
}

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) { // Corrected loop to go down to 0
            printf("%d\n", stack[i]);
        }
    }
}

void pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
    } else {
        int x = stack[*top]; // Element to pop (optional, only for illustration)
        (*top)--; // Decrement top
        printf("Popped element: %d\n", x);
    }
}
