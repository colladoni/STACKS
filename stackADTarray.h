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
    S->top= MAX;
}

void push(STACK *S,char data){
    
    if(!(isFull(*S))){
        S->top--;
        S->elem[S->top] = data;
    }
}

void pop(STACK *S){
    
    if(!(isEmpty(*S))){
        S->top++;
    }
}

int isEmpty(STACK S){
    
    return (S.top == MAX) ? 1:0;
}

int isFull(STACK S){
    return (S.top == 0) ? 1:0;
}

void display(STACK S) {
    STACK temp;
    
    if (isEmpty(S)){
        printf("Empty List");
    }else{
        initialize(&temp);
        while(!isEmpty(S)){
            push(&temp,top(S));
            pop(&S);
        }
        
        while(!(isEmpty(temp))){
            push(&S,top(temp));
            printf("%c",top(S));
            pop(&temp);
        }
    }
    
}


char top(STACK S){
    if(!(isEmpty(S))){
        return S.elem[S.top];
    }
}

#endif
