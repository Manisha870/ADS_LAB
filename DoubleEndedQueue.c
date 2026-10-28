#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int dequeue[MAX];
int f=-1,r=-1;

int isFull(){
    return((f==0 && r== MAX-1) || (f==r+1));
}

int isEmpty(){
    return (f==-1);
}

void insertFront(int x){
    if(isFull()){
        printf("Dequeue overflow");
        return;
    }
    if (isEmpty()){
        f=0;
        r=0;
    }else if ( f==0){
        f= MAX-1;
    }else{
        f--;
    }
    dequeue[f]=x;
}

void insertRear(int x) {
    if (isFull()) {
        printf("Dequeue Overflow\n");
        return;
    }
    if (isEmpty()) {
        f = 0;
        r = 0;
    } else if (r == MAX - 1) {
        r = 0;
    } else {
        r++;
    }
    dequeue[r] = x; 
}

void deleteFront() {
    if (isEmpty()) { 
        printf("Dequeue Underflow\n");
        return;
    }
    printf("Deleted %d from front.\n", dequeue[f]);
    if (f == r) { 
        f = -1;
        r = -1;
    } else if (f == MAX - 1) {
        f = 0; 
    } else {
        f++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Dequeue Underflow\n");
        return;
    }
    printf("Deleted %d from rear.\n", dequeue[r]);
    if (f == r) { 
        f = -1;
        r = -1;
    } else if (r == 0) {
        r = MAX - 1; 
    } else {
        r--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Dequeue is empty\n");
        return;
    }
    printf("Dequeue elements: ");
    int i=f;
    while (1) {
        printf("%d ", dequeue[i]);
        if (i == r) break;
        i = (i + 1) % MAX;
    }

}

int main() {
    int choice, val;

    while (1) {
        printf("\nDOUBLE-ENDED QUEUE MENU \n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}