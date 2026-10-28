OBJECTIVE: Write a C program to Implement Shortest path algorithms.
PROGRAM:

#include <stdio.h>
#define INF 999999
int main() {
int a[20][20], dist[20], visited[20] = {0};
int n, source, i, j, u, min;
printf("Enter number of vertices: ");
scanf("%d", &n);
if (n < 1 || n > 20) return 0;
printf("Enter adjacency matrix (0 = no edge):\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
if (i != j && a[i][j] == 0)
a[i][j] = INF;
}
}
printf("Enter source vertex: ");
scanf("%d", &source);
if (source < 0 || source >= n) return 0;
for (i = 0; i < n; i++)
dist[i] = INF;
dist[source] = 0;
for (i = 0; i < n; i++) {
min = INF;
u = -1;
for (j = 0; j < n; j++) {
if (!visited[j] && dist[j] < min) {
min = dist[j];
u = j;
}
}
if (u == -1) break;
visited[u] = 1;
for (j = 0; j < n; j++) {
if (!visited[j] && a[u][j] != INF &&
dist[u] + a[u][j] < dist[j]) {
dist[j] = dist[u] + a[u][j];
}
}
}
printf("Shortest distances from vertex %d:\n", source);
for (i = 0; i < n; i++) {
if (dist[i] == INF)
printf("To %d: Unreachable\n", i);
else
printf("To %d: %d\n", i, dist[i]);
}
return 0;
}









