#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head= NULL, *temp;

void insbeg(int x){
    temp=(struct node*)malloc(sizeof(struct node));
    temp ->data=x;
    temp -> next=NULL;
    if(head==NULL){
        head=temp;

    }else{
        temp ->next=head;
        head = temp;
    }

}

void insend(int x){
    struct node *t;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data=x;
    temp -> next= NULL;
    if(head == NULL){
        head = temp;
    }else{
        t= head;
        while(t -> next !=NULL){
            t= t -> next;
        }
        t -> next = temp;

    }
}

void inspos(int x, int pos){
    int c=1;
    struct node *t;
    temp= (struct node*)malloc(sizeof(struct node));
    temp -> data =x;
    temp ->next = NULL;
    if(head == NULL){
        head= temp;
    }else{
        t=head;
        while(c<pos-1 && t -> next != NULL){
            c++;
            t= t ->next;
        }
        temp ->next = t->next;
        t -> next=temp;
    }
}

void delbeg(){
    if(head==NULL){
        printf("List is empty");
    }else{
        temp = head;
        printf("Deleted node info is %d\n",temp->data);
        head = head->next;
        free(temp);
    }
}

void delend(){
    if(head == NULL){
        printf("List is empty");
    }else{
        temp = head;
        while(temp->next->next !=NULL){
            temp = temp->next;
        }
        printf("\nDeleted node info is %d\n",temp->next->data);
        free(temp->next);
        temp->next=NULL;
    }
}

void delpos(int pos){
    int c= 1;
    temp = head;
    struct node *t;
    while(c<pos-1){
        temp= temp->next;
        c++;
    }   
    t= temp -> next;
    temp -> next = t ->next;
    printf("\n Deleted node info is %d\n",t -> data);
    free(t);
    
}

int search(int k){
    int c=0;
    temp = head;
    while (temp != NULL){
        c++;
        if(temp ->data==k){
            return 1;

        }
        temp = temp->next;

    }
    return -1;
    
    
}
void display(){
    temp= head;
    printf("\nlinked list:\n");
    while (temp != NULL){
        printf("%d ",temp->data);
        temp= temp ->next;

    }
    
}

int main(){
    int val,choice,pos,result;
    while(1){
        printf("\nLINKED LIST\n");
        printf("1.Insert At Beginning\n");
        printf("2.Insert At End\n");
        printf("3.Insert At Position\n");
        printf("4.Delete From Beginning\n");
        printf("5.Detete From End\n");
        printf("6.Delete from position\n");
        printf("7.Search element\n");
        printf("8.Display list\n");
        printf("9.Exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
              printf("enter elemnet to insert:");
              scanf("%d",&val);
              insbeg(val);
              display();
              break;

            case 2:
              printf("enter element to insert:");
              scanf("%d",&val);
              insend(val);
              display();
              break;
            case 3:
              printf("enter element to insert:");
              scanf("%d",&val);
              printf("enter position:");
              scanf("%d",&pos);
              inspos(val,pos);
              display();
              break;

            case 4:
              delbeg();
              display();
              break;

            case 5:
              delend();
              display();
              break;

            case 6:
              printf("enter position:");
              scanf("%d",&pos);
              delpos(pos);
              display();
              break;
            case 7:
              printf("enter element to search:");
              scanf("%d",&val);
              result = search(val);
              if(result != -1){
                printf("elemnt %d found at index %d",val,result);
              }else{
                printf("elemnt %d not found",val);
              }
              break;
            case 8:
              display();
              break;
            case 9:
              printf("exit");
              exit(0);
            default:
              break;
        }

    }
    
}
