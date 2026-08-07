#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node  *right;
};

struct node *root= NULL, *temp;

void insert(int x){
    struct node *p, *p1;

    temp= (struct node *)malloc(sizeof(struct node));
    temp -> data=x;
    temp ->left= NULL;
    temp -> right= NULL;

    if(root==NULL){
        root = temp;
    }else{
        p=root;
        p1=NULL;

        while (p != NULL){
            p1=p;

            if(x< p->data){
                p = p->left;
            }else{
                p= p->right;
            }
        }
        if(x< p1->data){
            p1->left = temp;
        }else{
            p1->right= temp;
        }
        
    }
}

void inorder (struct node *p){
    if(p != NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void preorder (struct node *p){
    if(p != NULL){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder (struct node *p){
    if(p != NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}

void search(int k){
    temp = root;
    while( temp != NULL){
        if (temp->data == k){
            printf("element %d is found in BST",k);
            break;
        }else if (k< temp->data){
            temp = temp->left;

        }else{
            temp = temp->right;
        }
    }
    if(temp == NULL){
       printf("element %d not found in BST",k);
    }
    
    
}

void deletion(int x) {
    int c = 0;
    struct node *p = root, *p1 = root;

    while (p != NULL) {
        if (p->data == x) {
            c = 1; 
            break;
        } else {
            p1 = p; 
            if (x < p->data) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
    }

    if (c == 0) {
        printf("element not present in the tree\n");
        return; 
    }

    if (p->left == NULL && p->right == NULL) { 
        printf("Deleted node info is %d\n", p->data);
        if (p == root) {
            root = NULL;
        } else if (p1->data > x) {
            p1->left = NULL;
        } else {
            p1->right = NULL;
        }
        free(p);
    } else if (p->left != NULL && p->right == NULL) {
        if (p == root) {
            root = p->left;
        } else if (p->data > x) {
            p1->left = p->left;
        } else {
            p1->right = p->left;
        }
        printf("Deleted node info is %d\n", p->data);
        free(p);
    } else if (p->left == NULL && p->right != NULL) {
        if (p == root) {
            root = p->right;
        } else if (p->data < x) {
            p1->right = p->right;
        } else {
            p1->left = p->right;
        }
        printf("Deleted node info is %d\n", p->data);
        free(p);
    } else {
        p1 = p->right;
        if (p1->left == NULL) {
            p->data = p1->data;
            p->right = p1->right;
            free(p1);
        } else {
            struct node *p2 = p1;
            while (p1->left != NULL) {
                p2 = p1;
                p1 = p1->left;
            }
            p->data = p1->data;
            p2->left = p1->right;
            free(p1);
        }
    }
}

int main(){
    int choice, x;

    while(1){
        printf("\nBINARY SEARCH TREE MENU\n");
        printf("1.Insert\n");
        printf("2.Inorder\n");
        printf("3.Preorder\n");
        printf("4.Postorder\n");    
        printf("5.Search\n");
        printf("6.Delete\n");
        printf("7.Exit\n");

        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
              printf("enter vale to insert:");
              scanf("%d",&x);
              insert(x);
              break;
            case 2:
              printf("Inorde Traversal:");
              inorder(root);
              printf("\n");
              break;
            case 3:
              printf("Preorde Traversal:");
              preorder(root);
              printf("\n");
              break;
            case 4:
              printf("Postorde Traversal:");
              postorder(root);
              printf("\n");
              break;
            case 5:
              printf("enter element to search:");
              scanf("%d",&x);
              search(x);
              break;
            case 6:
              printf("enter element to delete:");
              scanf("%d",&x);
              deletion(x);
              break;
            case 7:
               printf("Existing program");
               exit(0);
            default:
               break;

        }
    }
}