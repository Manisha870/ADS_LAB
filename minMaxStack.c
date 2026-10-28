#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int minStack[MAX];
int maxStack[MAX];
int top = -1;

void push(int val) { 
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = val;

    if (top == 0) {
        minStack[top] = val;
    } else {
        minStack[top] = (val < minStack[top - 1]) ? val : minStack[top - 1];
    }

    if (top == 0) {
        maxStack[top] = val;
    } else {
        maxStack[top] = (val > maxStack[top - 1]) ? val : maxStack[top - 1];
    }

}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped element: %d\n", stack[top]);
    top--;
}

void getMin() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Minimum Element: %d\n", minStack[top]);
    }
}

void getMax() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Maximum Element: %d\n", maxStack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack element: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- MIN-MAX STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Minimum\n");
        printf("4. Get Maximum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                getMin();
                break;

            case 4:
                getMax();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}