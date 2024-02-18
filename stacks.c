#include <stdio.h>
#include "queueADTarray.h"
// #include "stackADTlinklist.h"

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
