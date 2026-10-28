#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int h[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyup(int index) {
    int p;
    while (index > 0) {
        p = (index - 1) / 2;
        if (h[p] > h[index]) {
            break;
        }
        swap(&h[p], &h[index]);
        index = p;
    }
}

void insert(int x) {
    if (size == MAX - 1) {
        printf("Array Full\n");
    } else {
        h[size] = x;
        size++;
        heapifyup(size - 1);
    }
}

void heapifydown(int index) {
    int l, left, right;

    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        l = index; 

        if (left < size && h[left] > h[l]) {
            l = left;
        }

        if (right < size && h[right] > h[l]) {
            l = right;
        }

        if (h[index] >= h[l]) {
            break;
        } else {
            swap(&h[index], &h[l]);
            index = l;
        }
    }
}

void del() {
    if (size == 0) {
        printf("Heap Underflow\n");
        return;
    }
    printf("Deleted element is %d\n", h[0]);
    h[0] = h[size - 1];
    size--;
    if (size > 0) {
        heapifydown(0);
    }
}

void display() {
    if (size == 0) {
        printf("Heap is Empty\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", h[i]);
    }
    
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- HEAP PRIORITY QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                del();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }

    return 0;
}