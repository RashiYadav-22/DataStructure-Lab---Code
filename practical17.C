OBJECTIVE: Write a C program to create a Graph, and implement Traversal algorithms.
PROGRAM:

#include <stdio.h>
int a[20][20], visited[20], n;
void DFS(int v) {
printf("%d ", v);
visited[v] = 1;
for (int i = 0; i < n; i++) {
if (a[v][i] && !visited[i])
DFS(i);
}
}
void BFS(int start) {
int q[20], front = 0, rear = 0;
for (int i = 0; i < n; i++)
visited[i] = 0;
q[rear++] = start;
visited[start] = 1;
while (front < rear) {
int v = q[front++];
printf("%d ", v);
for (int i = 0; i < n; i++) {
if (a[v][i] && !visited[i]) {
q[rear++] = i;
visited[i] = 1;
}
}
}
}
int main() {
int e, u, v, start;
printf("Enter vertices and edges: ");
scanf("%d%d", &n, &e);
if (n < 1 || n > 20 || e < 0) return 0;
for (int i = 0; i < e; i++) {
printf("Enter edge (u v): ");
scanf("%d%d", &u, &v);
if (u < 0 || u >= n || v < 0 || v >= n)
return 0;
a[u][v] = a[v][u] = 1;
}
printf("Enter starting vertex (0 to %d): ", n - 1);
scanf("%d", &start);
if (start < 0 || start >= n) return 0;
printf("DFS: ");
for (int i = 0; i < n; i++) visited[i] = 0;
DFS(start);
printf("\nBFS: ");
BFS(start);
return 0;
}












