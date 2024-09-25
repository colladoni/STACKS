#ifndef QUEUEKADTLINKLIST_H
#define QUEUEADTLINKLIST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char data;
    struct node* link;
} Node;

typedef struct queue {
    Node *front, *rear;
} QUEUE;

// Function prototypes
void initialize(QUEUE *Q);
void EnQueue(QUEUE *Q, char data);
void DeQueue(QUEUE *Q);
int isFull(QUEUE Q);
int isEmpty(QUEUE Q);
char Front(QUEUE Q);
void display(QUEUE Q);


void initialize(QUEUE *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

// Add an element to the rear of the queue (EnQueue)
void EnQueue(QUEUE *Q, char data) {
    Node* temp = (Node*)malloc(sizeof(Node));

    if (temp != NULL) {
        temp->data = data;
        temp->link = NULL;

        if (isEmpty(*Q)) {
            Q->front = temp;
        } else {
            Q->rear->link = temp;
        }
        Q->rear = temp;
    } else {
        printf("Memory allocation failed. Queue is full.\n");
    }
}

// Remove an element from the front of the queue (DeQueue)
void DeQueue(QUEUE *Q) {
    if (!isEmpty(*Q)) {
        Node* temp = Q->front;

        if (Q->front == Q->rear) {
            Q->rear = NULL;
        }

        Q->front = Q->front->link;
        free(temp);
    } else {
        printf("Queue is empty. Cannot DeQueue.\n");
    }
}

// Check if the queue is empty
int isEmpty(QUEUE Q) {
    return (Q.front == NULL);
}

// Peek at the front element of the queue
char Front(QUEUE Q) {
    if (!isEmpty(Q)) {
        return Q.front->data;
    }
    return '\0';  // Return null character if the queue is empty
}

// Display the elements of the queue
void display(QUEUE Q) {
    if (!isEmpty(Q)) {
        Node* temp = Q.front;
        while (temp != NULL) {
            printf("%c ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    } else {
        printf("Queue is empty.\n");
    }
}

int isFull(QUEUE Q) {
    return 0;  // Queue is not full
}

#endif
