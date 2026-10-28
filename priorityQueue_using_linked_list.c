#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

void enqueue(int val, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow.\n");
        return;
    }
    newNode->data = val;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority > front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* current = front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Inserted (%d, Priority: %d) successfully.\n", val, priority);
}

void dequeue() {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted element: %d (Priority: %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Highest Priority Element -> Data: %d, Priority: %d\n", front->data, front->priority);
}

void display() {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node* current = front;
    printf("Priority Queue (Front to Rear):\n");
    while (current != NULL) {
        printf("[Data: %d, Priority: %d] -> ", current->data, current->priority);
        current = current->next;
    }

}

int main() {
    int choice, val, priority;

    while (1) {
        printf("\n--- LINKED LIST PRIORITY QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data value and priority: ");
                scanf("%d %d", &val, &priority);
                enqueue(val, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
    
                while (front != NULL) {
                    struct Node* temp = front;
                    front = front->next;
                    free(temp);
                }
                printf("Exiting program. Memory freed.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}