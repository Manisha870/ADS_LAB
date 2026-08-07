#include<stdio.h>
int arr[20],n;
void insertion (int x, int pos){
    int i;
    for(i=n-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=x;
    n++;
}

void deletion ( int pos){
    int i;
    if(pos!=n){
        for(i=pos-1;i<n-1;i++){
            arr[i]=arr[i+1];
        }
    }
    n--;
}

int search(int k){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==k){
            return i+1;
        }
    }
    return -1;
}

void display(){
    printf("Array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}

int main(){
    int i,pos,k,x,choice,result;
    printf("enter size of the array: ");
    scanf("%d",&n);
    printf("enter elements of the array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    do{
        printf("\n1.insertion\n2.deletion\n3.search\n4.display\n5.Exit\n");
        printf("enter your choice(1,2,3,4):");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter element to insert:");
            scanf("%d",&x);
            printf("enter position: ");
            scanf("%d",&pos);
            insertion(x,pos);
            display();
            break;
        case 2:
           printf("enter position to delete element: ");
           scanf("%d",&pos);
           deletion(pos);
           display();
           break;
        case 3:
           printf("enter element to search:");
           scanf("%d",&k);
           result=search(k);
           if (result==-1){
            printf("element %d is not present",k);
           }else{
            printf("element %d is present is position %d",k,result);
           }
           break;
        case 4:
           display();
           break;
        case 5:
           return 0;
        
        default:
            break;
        }
    }while(choice <= 5);
}

