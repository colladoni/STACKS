#ifndef STACKADTLINKLIST_H
#define STACKADTLINKLIST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	char elem;
	struct node *link;
}*STACK;

void initialize(STACK *S);
void push(STACK *S, char data);
void pop(STACK *S);
int isEmpty(STACK S);
int isFull(STACK S);
void display(STACK S);
char top(STACK S);


void initialize(STACK *S){
	S=NULL;
}

void push(STACK *S, char data){
	STACK temp;
	temp = (STACK)malloc(sizeof(struct node));
	if (temp != NULL){
	    temp->elem = data;
	    temp->link = *S;
	    *S = temp;
	}
}

void pop(STACK *S){
    STACK temp;
    if(!isEmpty(*S)){
        temp = *S;
        *S = temp->link;
        free(temp);
    }
}

int isEmpty(STACK S){
	return (S == NULL) ? 1:0;
}

int isFull(STACK S){
    return 0;
}

void display(STACK S){
	STACK temp;
	
	if(isEmpty(S)){
	    printf("Empty List");
	}else{
	    temp = NULL;
	    
        while(!isEmpty(S)){
            push(&temp,top(S));
            pop(&S);
        }
        while(!isEmpty(temp)){
            push(&S,top(temp));
            printf("%c",top(S));
            pop(&temp);
        }
    }
}

char top(STACK S){
    if(!isEmpty(S)){
        return S->elem;
    }
}

#endif
