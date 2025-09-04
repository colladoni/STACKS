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

void insertBottom(QUEUE *Q, char data);
int main(){
    QUEUE Qq;
    initialize(&Qq);

    EnQueue(&Qq, 'A');
    EnQueue(&Qq, 'B');
    EnQueue(&Qq, 'C');

    printf("\nQueue after pushing A, B, C:\n");
    display(Qq);

    DeQueue(&Qq);
    

    printf("\nQueue after popping one element:\n");
    display(Qq);

    EnQueue(&Qq, 'D');
    EnQueue(&Qq, 'E');
    
    printf("\nQueue after pushing D and E:\n");
    display(Qq);

    insertBottom(&Qq,'J');
    
    printf("\nQueue after inserting J in bottom:\n");
    display(Qq);

    return 0;
}

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
    int count = (((Q.rear - Q.front) + MAX) + 1) % MAX;
    
    for(;count>0;count--){
        printf("%c",Front(Q));
        EnQueue(&Q,(Front(Q)));
        DeQueue(&Q);
    }
}

void insertBottom(QUEUE *Q, char data){
    QUEUE temp;

    if(!isFull(*Q)&&!isEmpty(*Q)){
	    initialize(&temp);
        while(!isEmpty(*Q)){
        	EnQueue(&temp, Front(*Q));
		    DeQueue(Q);
	    }
    
	    EnQueue(Q,data);

	    while(!isEmpty(temp)){
		    EnQueue(Q, Front(temp));
		    DeQueue(&temp);
        }
    }else if(!isFull(*Q)&&isEmpty(*Q)){
	EnQueue(Q,data);
    }
}
