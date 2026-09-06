#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct queue{
    int a[MAX];
    int r,f;
}q;

void enqueue (int x){
    if(q.r== MAX-1){
        printf("\n Queue Overflow");
    }else{
        q.r++;
        q.a[q.r]=x;
    }
}

int dequeue(){
  if(q.r<q.f){
    return -1;
  }
  return(q.a[q.f++]);
}

int peek(){
    if(q.r<q.f){
        return -1;
    }
    return(q.a[q.f]);
}

void display(){
    int i;
    printf("\n Queue elemet:");
    for(i=q.f;i<=q.r;i++){
        printf("%d ",q.a[i]);
    }
}


int main(){
    q.r=-1;
    q.f=0;
    int choice, val, del_ele,ele;

    while(1){
        printf("\n STACK OPERATION\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Dispay\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
              printf("enter element to Enqueue:");
              scanf("%d",&val);
              enqueue(val);
              display();
              break;
            
            case 2:
              del_ele=dequeue();
              if(del_ele==-1){
                printf("Stack is empty");
              }else{
                printf("deleted element is %d",del_ele);
              }
              break;

            case 3:
              ele=peek();
              if(ele==-1){
                printf("Queue is empty");
              }else{
                printf("First element is %d",ele);
              }
              break;
            
            case 4:
              display();
              break;
            
            case 5:
               printf("Exiting..");
               exit(0);
            
            default:
              break;
        }
    }
}


