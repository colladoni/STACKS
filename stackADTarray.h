#ifndef STACKADTARRAY_H
#define STACKADTARRAY_H
#include <stdio.h>
#define MAX 8

typedef struct{
    char elem[MAX];
    int top;
}STACK;

void initialize(STACK *S);
void push(STACK *S, char data);
void pop(STACK *S);
int isEmpty(STACK S);
int isFull(STACK S); //1 - true, 0 - false
void display(STACK S);

char top(STACK S);

void initialize(STACK *S){
    S->top = MAX;
}

void push(STACK *S,char data){
    if(!isFull(*S)){
        S->top--;
        S->elem[S->top] = data;
    } //else if(isFull(*S)== 1){}
}

void pop(STACK *S){
    if(!isEmpty(*S)){
        S->top++;
    } //else if(isEmpty(*S)== 1){}
}

int isEmpty(STACK S){
    return (S.top == MAX) ? 1 : 0; //1 is Empty, 0 is not Empty
}

int isFull(STACK S){
    return (S.top == 0) ? 1 : 0; //1 is Full, 0 is not Full
}

void display(STACK S) {
    STACK tempStack;
    char elem;

    initialize(&tempStack);

    if (isEmpty(S)) {
        printf("Stack is empty. Nothing to display.\n");
        return;
    }

    // Transfer and display the elements into the temporary stack
    while (!isEmpty(S)) {
        elem = S.elem[S.top];
        printf("%c ", elem);
        push(&tempStack, elem);
        S.top++;
    }

    //Free temp
    while (!isEmpty(tempStack)) {
        pop(&tempStack);
    }

    printf("\n");
}


char top(STACK S){
	if(!isEmpty(S)){
		return S.elem[S.top];
	}
}

#endif
