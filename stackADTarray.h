#ifndef STACKADTARRAY_H
#define STACKADTARRAY_H
#define MAX 8

typedef struct{
    char elem[MAX];
    int top;
}STACK;

void initialize(STACK *S);
void push(STACK *S, char data);
void pop(STACK *S);
int isEmpty(STACK *S);
int isFull(STACK *S); //1 - true, 0 - false
void display(STACK *S);
int top(STACK *S); //return top element
void insertBottom(STACK *S, char data);

void initialize(STACK *S){
    S->top = MAX-1;
}

void push(STACK *S,char data){
    if(isFull(S) == 0){
        S->top--;
        S->elem[S->top] = data;
    } //else if(isFull(S)== 1){}
}

void pop(STACK *S){

}

int isEmpty(STACK *S){
    return (S->top == MAX-1) ? 1 : 0; //1 is Empty, 0 is not Empty
}

int isFull(STACK *S){
    return (S->top == 0) ? 1 : 0; //1 is Full, 0 is not Full
}

void display(STACK *S){

}

int top(STACK *S);{

}

void insertBottom(STACK *S, char data){

}

#endif
