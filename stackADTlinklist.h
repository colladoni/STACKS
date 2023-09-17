#ifndef STACKADTLINKLIST_H
#define STACKADTLINKLIST_H
#include <stdlib.h>

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
	*S = NULL;
}

void push(STACK *S, char data){
	STACK temp = (struct node*)malloc(sizeof(struct node)); 
	if(temp != NULL){
		temp->elem = data;
		temp->link = *S;
		*S = temp;
	}
}

void pop(STACK *S){ //no return, just delete
	STACK temp;
	if(*S != NULL){
		temp = *S;
		*S = temp->link;
		free(temp);
	}
}

int isEmpty(STACK S){
	return (S == NULL) ? 1 : 0;
}

int isFull(STACK S){
	return 0;	//linked list imp. rarely will get full
}

void display(STACK S){
	if(S!=NULL){
		STACK temp=NULL;
		while(S!=NULL){
			push(&temp, S->elem);
			printf("%c ", S->elem);
			pop(&S);
		}
		while(temp!=NULL){
			push(&S, temp->elem);
			pop(&temp);
		}
	}
	 printf("\n");
}


char top(STACK S){
	char retval;
	if(!isEmpty(S)){
		retval = S->elem;
	}else{
		retval = '0';
	}
	return retval;
}

#endif
