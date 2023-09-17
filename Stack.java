public class Stack {
    private static final int MAX = 100;
    private char[] elem;
    private int top;

    public Stack() {
        elem = new char[MAX];
        top = MAX - 1;
    }

    public boolean isEmpty() {
        return top == MAX - 1;
    }

    public boolean isFull() {
        return top == 0;
    }

    public void push(char elem) {
        if (!isFull()) {
            this.elem[top] = elem;
            top--;
        } else {
            System.out.println("Stack is full.");
        }
    }

    public void pop() {
        if (!isEmpty()) {
            top++;
        } else {
            System.out.println("Stack is empty.");
        }
    }

    public void insertBottom(char data) {
        Stack tempStack = new Stack();

        if (isFull() || isEmpty()) {
            System.out.println("Can't insert.");
            return;
        }

        while (!isEmpty()) {
            char element = elem[top + 1];
            tempStack.push(element);
            pop();
        }

        push(data);

        while (!tempStack.isEmpty()) {
            char elem = tempStack.elem[tempStack.top + 1];
            push(elem);
            tempStack.pop();
        }
    }

    public void display() {
        Stack tempStack = new Stack();

        System.out.println("\nStack: ");

        while(!isEmpty()) {
            char data = elem[top + 1];
            System.out.println(data + " ");
            tempStack.push(data);
            pop();
        }

        while(!tempStack.isEmpty()) {
            char data = tempStack.elem[tempStack.top + 1];
            push(data);
            tempStack.pop();
        }

        System.out.println();
    }

    public static void main(String[] args) {
        Stack S = new Stack();

        S.push('A');
        S.push('B');
        S.push('C');

        S.display();

        System.out.println("After pop");
        S.pop();
        S.display();

        System.out.println("After insert bottom");
        S.insertBottom('D');
        S.display();

        System.out.println("Pop again");
        S.pop();
        S.display();
    }
}