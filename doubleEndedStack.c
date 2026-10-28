#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x){
    if(top1==top2-1){
        printf("Stack1 overflow\n");
    }
    arr[++top1]=x;
}

void pop1(){
    if(top1==-1){
        printf("Stack1 Underflow");
    }
    printf("Popped element from Stack1: %d\n", arr[top1--]);

}

void display1(){
    if ( top1==-1){
        printf("Stack1 Underflow");
    }else{
        printf("Stack1 element\n");
        for ( int i=top1;i>=0;i--){
            printf("%d ",arr[i]);
        }
    }

}

void push2(int x){
    if(top2==top1+1){
        printf("Stack2 overflow\n");
    }
    arr[--top2]=x;
}

void pop2(){
    if(top2==MAX){
        printf("Stack2 Underflow");
    }
    printf("Popped element from Stack2: %d\n", arr[top2++]);
    
}

void display2(){
    if ( top2==MAX){
        printf("Stack2 Underflow");
    }else{
        printf("Stack2 element\n");
        for ( int i=top2;i<MAX;i++){
            printf("%d ",arr[i]);
        }
    }

}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- DOUBLE-ENDED STACK MENU ---\n");
        printf("1. Push Stack1\n");
        printf("2. Push Stack2\n");
        printf("3. Pop Stack1\n");
        printf("4. Pop Stack2\n");
        printf("5. Display Stack1\n");
        printf("6. Display Stack2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push in Stack1: ");
                scanf("%d", &x);
                push1(x);
                break;

            case 2:
                printf("Enter value to push in Stack2: ");
                scanf("%d", &x);
                push2(x);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}