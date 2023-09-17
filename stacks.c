#include <stdio.h>
#include "stackADTarray.h"
// #include "stackADTlinklist.h"

void insertBottomArr(STACK *S, char data){
    STACK tempStack;
    char elem;

    initialize(&tempStack);

    if (isFull(*S) || isEmpty(*S)) {
        printf("Error inserting. \n");
        return;
    }
    while (!isEmpty(*S)) {
        elem = S->elem[S->top];
        push(&tempStack, elem);
        pop(S);
    }

    push(S,data);//insert bottom

    while (!isEmpty(tempStack)) {
        elem = tempStack.elem[tempStack.top];
        push(S,elem);
        pop(&tempStack);
    }
}

int main(){
    STACK Ss;
    initialize(&Ss);

    push(&Ss, 'A');
    push(&Ss, 'B');
    push(&Ss, 'C');

    printf("Stack after pushing A, B, C:\n");
    display(Ss);

    pop(&Ss);

    printf("Stack after popping one element:\n");
    display(Ss);

    push(&Ss, 'D');
    push(&Ss, 'E');
    
    printf("Stack after pushing D and E:\n");
    display(Ss);

    insertBottomArr(&Ss,'J');
    
    printf("Stack after inserting J in bottom:\n");
    display(Ss);

    return 0;
}


