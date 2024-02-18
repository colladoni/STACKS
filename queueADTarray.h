#ifndef QUEUEADTARRAY_H
#define QUEUEADTARRAY_H
#include <stdio.h>
#define MAX 8

typedef struct{
    char elem[MAX];
    int front;
    int rear;
}QUEUE;

void initialize(QUEUE *Q);
void EnQueue(QUEUE *Q, char data);
void DeQueue(QUEUE *Q);
int isFull(QUEUE Q);
int isEmpty(QUEUE Q);
char Front(QUEUE Q);
void display(QUEUE Q);

void initialize(QUEUE *Q){
    Q->rear = 0;
    Q->front = (Q->rear + 1) % MAX;
}

void EnQueue(QUEUE *Q, char data){
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->elem[Q->rear] = data;
    }
}

void DeQueue(QUEUE *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
    }
}

int isFull(QUEUE Q){
    return (Q.front==(Q.rear + 2) % MAX) ? 1:0;
}

int isEmpty(QUEUE Q){
    return (Q.front==(Q.rear + 1) % MAX) ? 1:0;
}
char Front(QUEUE Q){
    char retval = '0';
    if(!isEmpty(Q)){
        retval = Q.elem[Q.front];
    }
    return retval;
}
void display (QUEUE Q){
    QUEUE temp;
    
    while(!isEmpty(Q)){
        EnQueue(&temp,Front(Q));
        printf("%c",Front(Q));
        DeQueue(&Q);
    }
}
#endif
