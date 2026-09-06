#include<stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition(int a[], int low, int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;

    while(i<=j){
        while (i<=high && a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
       
    }
    swap(&a[low],&a[j]);
    return j;
}

void quickSort(int a[],int low, int high){
    if(low<high){
        int p= partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}
int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n<1){
        printf("Enter positive number.");
        return 0;
    }
    int arr[n];

    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}