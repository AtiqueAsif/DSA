// Basic and simple way to insert, delete and display in QUEUE


#include <stdio.h>

int size;
int rear = -1;
int front = 0;
int queue[100];

void enqueue(int data){
    if (rear == size - 1) {
        printf("Queue is full!\n");
        return;
    }
    else{
    rear = rear + 1;
    queue[rear] = data;
    }
}

void dequeue(){
    if (front == - 1 || front > rear){
        printf("Queue is empty!\n");
        return;
    }
    else{
    printf("Dequeued element: %d\n", queue[front]);
    front = front + 1;
    }
}

void display() {
    if (front > rear){
        printf("Queue is empty!\n");
        return;
    }
    for (int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("\nAfter insertion elements:\n");
    display();

    dequeue();

    printf("\nAfter deleting an element:\n");
    display();

    return 0;
}
