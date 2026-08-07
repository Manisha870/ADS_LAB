#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack{
    int top;
    int a[MAX];

}s;

void push(int x){
    if(s.top==MAX-1){
        printf("\n Stack overflow");
    }else{
        s.top++;
        s.a[s.top]=x;
    }
}

int pop(){
    if(s.top==-1){
        return -1;
    }
    int ele = s.a[s.top];
    s.top--;
    return ele;
}

void peek(){
    if(s.top==-1){
        printf("\n stack is empty");
    }else{
        printf("Top element is %d",s.a[s.top]);
    }
}
 
void display(){
    int i;
    printf("\n Stack element:");
    for(i=s.top;i>=0;i--){
        printf("%d ",s.a[i]);
    }
}

int main(){
    s.top =-1;
    int choice, val, del_ele;

    while(1){
        printf("\n STACK OPERATION\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Dispay\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
              printf("enter element to push:");
              scanf("%d",&val);
              push(val);
              display();
              break;
            
            case 2:
              del_ele=pop();
              if(del_ele==-1){
                printf("Stack is empty");
              }else{
                printf("deleted element is %d",del_ele);
              }
              break;

            case 3:
              peek();
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


