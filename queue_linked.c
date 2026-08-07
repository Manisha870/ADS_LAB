#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
 
    if (temp == NULL) {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    
    temp->data = value;
    temp->next = NULL;
    
    if (front == NULL && rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp; 
        rear = temp;       
    }
    
}

int dequeue() {
   
    if (front == NULL) {
        return -1;
    }
    
    struct node *temp = front;
    int deleted_val = temp->data;
    
    front = front->next; 
    
   
    if (front == NULL) {
        rear = NULL;
    }
    
    free(temp); 
    return deleted_val;
}


int peek() {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}


void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}


int main() {
    int choice, val, deleted_val, front_val;

    while (1) {
        printf("\n--- DYNAMIC QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
                break;
            case 2:
                deleted_val = dequeue();
                if (deleted_val == -1) {
                    printf("Queue Underflow! The queue is empty.\n");
                } else {
                    printf("Dequeued element: %d\n", deleted_val);
                }
                break;
            case 3:
                front_val = peek();
                if (front_val == -1) {
                    printf("Queue is empty! No element at the front.\n");
                } else {
                    printf("Element at the front: %d\n", front_val);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program \n");
               
                exit(0);
            default:
              break;
                        
          }
    }
    return 0;
}