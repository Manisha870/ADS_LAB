#include <stdio.h>
#include <stdlib.h>

int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void countingSort(int A[], int n, int exp) {
    int output[n];     
    int count[10] = {0}; 

  
    for (int i = 0; i < n; i++) {
        int digit = (A[i] / exp) % 10;
        count[digit] = count[digit] + 1;
    }

 
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit] = count[digit] - 1;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}


void radixSort(int A[], int n) {
    int max = getMax(A, n); 
    int exp = 1;            

    while (max / exp > 0) {
        countingSort(A, n, exp);
        exp = exp * 10;
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 0;
    }

    int A[n];
    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("\nOriginal Array: ");
    printArray(A, n);

    radixSort(A, n); 
    

    printf("Sorted Array:   ");
    printArray(A, n);

    return 0;
}