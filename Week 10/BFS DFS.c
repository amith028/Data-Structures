BFS method 

#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int queue[MAX], front = -1, rear = -1;


void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = item;
}


int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// BFS Function
void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n) {
    int i;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    int n, i, j, start;
    int graph[MAX][MAX], visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    bfs(graph, visited, start, n);
    return 0;
}

DFS 
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];  
int visited[MAX];      
int n;                


void dfs(int v) {
    visited[v] = 1;  
   
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);  
        }
    }
}

int isConnected() {
   
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

   
    dfs(0);

   
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;  
        }
    }
    return 1;  
}

int main() {
    int i, j;

   
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

   
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
   
    if (isConnected()) {
        printf("The graph is connected.\n");
    } 
    else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
