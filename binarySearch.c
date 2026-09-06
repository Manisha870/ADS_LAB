#include<stdio.h>
#include<stdlib.h>

void sortArray(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}
int binarySearch(int arr[],int n,int target){
    int low=0;
    int high = n-1;
    while(low<=high){
        int mid=low + (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int binarySearchRecursive(int arr[],int low, int high,int target){
    if(low<=high){
        int mid=low+ (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if (arr[mid]<target){
            binarySearchRecursive(arr,mid+1,high,target);
        }else{
            binarySearchRecursive(arr,low,mid-1,target);
        }
    }
    return -1;
}

int main(){
    int target,choice,result,n;
    printf("Enter number of element in the array:");
    scanf("%d",&n);
    int arr[n];

    printf("enter %d element:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sortArray(arr,n);
    printf("sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    while(1){
        printf("\n1.Non-Recursive search\n");
        printf("2.Recursive Search\n");
        printf("3.Exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter element to search:");
            scanf("%d",&target);
            result=binarySearch(arr,n,target);
            if(result !=-1){
                printf("\nelement %d found at index %d\n",target,result);
            }else{
                printf("\nelement %d not found\n",target);
            }
            break;
        case 2:
            printf("enter element to search:");
            scanf("%d",&target);
            result = binarySearchRecursive(arr,0,n-1,target);
            if(result !=-1){
                printf("\nelement %d found at index %d\n",target,result);
            }else{
                printf("\nelement %d not found\n",target);
            }
            break;
        case 3:
            printf("Exiting Program");
            exit(0);
        
        default:
            printf("invalid choice");
            break;
        }
    }

}