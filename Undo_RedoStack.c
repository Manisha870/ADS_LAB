#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int undoStack[MAX];
int redoStack[MAX];
int topUndo = -1;
int topRedo = -1;

void pushUndo(int x) {
    if (topUndo == MAX - 1) {
        printf("Undo Stack Overflow\n");
        return;
    }
    topUndo++;
    undoStack[topUndo] = x;
}

void pushRedo(int x) {
    if (topRedo == MAX - 1) {
        printf("Redo Stack Overflow\n");
        return;
    }
    topRedo++;
    redoStack[topRedo] = x;
}

void insert(int x) {
    if(topUndo== MAX-1){
        printf("Stack Overflow\n");
    }else{
        pushUndo(x);
        topRedo = -1;
    }


}

void undo() {
    if (topUndo == -1) {
        printf("Nothing to Undo\n");
        return;
    }
    int val = undoStack[topUndo];
    topUndo--;
    pushRedo(val);
    printf("Undo performed: Reverted %d\n", val);
}

void redo() {
    if (topRedo == -1) {
        printf("Nothing to Redo\n");
        return;
    }
    int val = redoStack[topRedo];
    topRedo--;
    pushUndo(val);
    printf("Redo performed: Restored %d\n", val);

}

void display() {
    printf("Undo Stack: ");
    if (topUndo == -1) {
        printf("Empty");
    } else {
        for (int i = 0; i <= topUndo; i++) {
            printf("%d ", undoStack[i]);
        }
    }
    printf("\n");

    printf("Redo Stack: ");
    if (topRedo == -1) {
        printf("Empty");
    } else {
        for (int i = 0; i <= topRedo; i++) {
            printf("%d ", redoStack[i]);
        }
    }

}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- UNDO-REDO MENU ---\n");
        printf("1. Insert\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display Current Stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                undo();
                break;

            case 3:
                redo();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}