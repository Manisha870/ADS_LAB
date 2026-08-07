#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;


void push(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
   
    if (temp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    
    temp->data = value;
    temp->next = top; 
    top = temp;      
    
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    
    struct node *temp = top;   
    printf("Popped element: %d\n", temp->data);
    top = top->next;           
    free(temp);                
}


void peek() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    
    struct node *temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
   
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- DYNAMIC STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek \n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                display();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program .\n");
                exit(0);
            default:
                break;
        }
    }
    return 0;
}