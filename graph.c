#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX][MAX];
int stack[MAX];
int queue[MAX];
int visited[MAX];
int n;

void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void bfs(int v) {
    int front = 0, rare = 0;
    queue[rare++] = v;
    visited[v] = 1;
    printf("BFS Path:\n");
    
    while (front < rare) {
        v = queue[front++];
        printf("%d ", v);
        
        for (int i = 0; i < n; i++) {
            if (arr[v][i] == 1 && visited[i] == 0) {
                queue[rare++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v) {
    int top = -1;
    stack[++top] = v;
    printf("DFS Path:\n");
    
    while (top != -1) {
        v = stack[top--];

        if (visited[v] == 0) {
            visited[v] = 1;
            printf("%d ", v);

            for (int i = n - 1; i >= 0; i--) {
                if (arr[v][i] == 1 && visited[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
   
}

int main() {
    int choice, start;
    
    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    while (1) {
        printf("\n1. BFS\n");
        printf("2. DFS\n");
        printf("3. Exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                resetVisited();
                bfs(start); 
                break;

            case 2:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                resetVisited();
                dfs(start);
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}