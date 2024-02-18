#include <stdio.h>
#include "queueADTarray.h"
// #include "stackADTlinklist.h"

// void insertBottom(QUEUE *Q, char data);

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

    // insertBottom(&Ss,'J');
    
    // printf("\nStack after inserting J in bottom:\n");
    // display(Ss);

    return 0;
}

void insertBottom(STACK *S, char data){
    STACK temp;

    if(!isFull(*S)&&!isEmpty(*S)){
	initialize(&temp);

        while(!isEmpty(*S)){
        	push(&temp, top(*S));
		pop(S);
	}
    	
	push(S,data);

	 while(!isEmpty(temp)){
		push(S, top(temp));
		pop(&temp);
        }
    }else if(!isFull(*S)&&isEmpty(*S)){
	push(S,data);
    }
}
