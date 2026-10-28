#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int data[MAX];
int pr[MAX];
int size = 0;

void enqueue(int val, int priority) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    
    data[size] = val;
    pr[size] = priority;
    size++;
    
    printf("Inserted Data: %d with Priority: %d\n", val, priority);
}

void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }

    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (pr[i] > pr[maxIdx]) {
            maxIdx = i;
        }
    }

    printf("Deleted highest priority element -> Data: %d (Priority: %d)\n", data[maxIdx], pr[maxIdx]);

    for (int i = maxIdx; i < size - 1; i++) {
        data[i] = data[i + 1];
        pr[i] = pr[i + 1];
    }
    size--;
}

void peek() {
    if (size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (pr[i] > pr[maxIdx]) {
            maxIdx = i;
        }
    }

    printf("Highest Priority Element -> Data: %d (Priority: %d)\n", data[maxIdx], pr[maxIdx]);
}

void display() {
    if (size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nCurrent Priority Queue (Parallel Arrays):\n");
    printf("----------------------------------------\n");
    printf("Index\tData\tPriority\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", i, data[i], pr[i]);
    }
    printf("----------------------------------------\n");
}

int main() {
    int choice, val, priority;

    while (1) {
        printf("\n--- PRIORITY QUEUE MENU ---\n");
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
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}