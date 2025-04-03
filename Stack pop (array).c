#include <stdio.h>

int size;
int top = -1;
int stack[100];

void push(int data) {
    if (top == size - 1) {
        printf("Stack is full!\n");
        return;
    }
    top = top + 1;
    stack[top] = data;
}

void pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top = top - 1;
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    push(10);
    push(20);
    push(30);

    printf("\nAfter pushing elements:\n");
    display();

    pop();

    printf("\nAfter popping an element:\n");
    display();

    return 0;
}
