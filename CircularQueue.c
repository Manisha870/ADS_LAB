#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int r=-1,f=-1;
int arr[MAX];

void enqueue(int x){
    if((r+1)%MAX==f){
        printf("Queue Overflow");
    }else{
        if(f==-1){
            f++;
        }
        r=(r+1)%MAX;
        arr[r]=x;
    }
}

void dequeue(){
    if ( f==-1){
        printf("Queue Underflow");
    }else{
        printf("Deleted element: %d",arr[f]);
        if(f==r){
            f==-1;
            r==-1;
        }else{
            f=(f+1)%MAX;
        }
    }
}

void display(){
    if(f==-1){
        printf("Queue Underflow");
    }
    int i=f;
    printf("Queue element: ");
    while(i!=r){
        printf("%d ",arr[i]);
        i= (i+1)%MAX;
    }
    printf("%d ",arr[i]);
}

int main(){
    int val,choice;

    while(1){
        printf("\n---CIRCULAR QUEUE---\n");
        printf("1.Enqueue\n");
        printf("2.Dequeu\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter element to insert:");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Existing Program..");
                exit(0);
            
            default:
               printf("Invalid choice");
                break;
        }
    }
}


