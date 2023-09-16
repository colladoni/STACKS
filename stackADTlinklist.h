#ifndef STACKADTLINKLIST_H
#define STACKADTLINKLIST_H
#define MAX 8

typedef struct node{
	char elem;
	struct node *link;
}*STACK;

void initialize(STACK *S);
void push(STACK *S, char data);
void pop(STACK *S);
int isEmpty(STACK *S);
//int isFull(STACK *S);
void display(STACK *S);
//int top(STACK *S);



void initialize(STACK *S){
	*S = NULL;
}

void push(STACK *S, char data){
	STACK temp = (STACK*)malloc(sizeof(struct node));
	if(temp != NULL){
		temp->elem = data;
		temp->link = *S;
	}
	*S = temp;
}

void pop(STACK *S){ //no return, just delete
	STACK temp;
	if(*S != NULL){
		temp = *S;
		*S = temp->link;
		free(temp);
	}
}

int isEmpty(STACK *S){
	return (*S == NULL) ? 1 : 0; //1 is Empty, 0 is not Empty
}

#endif
