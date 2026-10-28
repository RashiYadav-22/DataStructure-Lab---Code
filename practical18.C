OBJECTIVE: Write a C program to Implement Minimum spanning tree algorithms.
PROGRAM:

(a) Kruskal's algorithm

#include <stdio.h>
struct Edge {
int u, v, w;
};
int parent[20];
int find(int x) {
while (parent[x] != x)
x = parent[x];
return x;
}
int main() {
struct Edge e[190], t;
int n, m, i, j, total = 0, count = 0;
printf("Enter vertices and edges: ");
scanf("%d%d", &n, &m);
if (n < 1 || n > 20 || m < 0 || m > 190)
return 0;
for (i = 0; i < m; i++) {
printf("Enter u v weight: ");
scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
}
for (i = 0; i < m; i++)
for (j = i + 1; j < m; j++)
if (e[i].w > e[j].w) {
t = e[i];
e[i] = e[j];
e[j] = t;
}
for (i = 0; i < n; i++)
parent[i] = i;
printf("MST edges:\n");
for (i = 0; i < m && count < n - 1; i++) {
int a = find(e[i].u);
int b = find(e[i].v);
if (a != b) {
parent[a] = b;
printf("%d - %d : %d\n",
e[i].u, e[i].v, e[i].w);
total += e[i].w;
count++;
}
}
if (count != n - 1)
printf("Graph is disconnected\n");
else
printf("Total weight = %d\n", total);
return 0;
}
(b) Prim's algorithm

#include <stdio.h>
#define INF 999999
int main() {
int a[20][20], selected[20] = {0};
int n, i, j, edges = 0, total = 0;
int min, u = -1, v = -1;
printf("Enter number of vertices: ");
scanf("%d", &n);
if (n < 1 || n > 20) return 0;
printf("Enter adjacency matrix (0 = no edge):\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
if (i != j && a[i][j] == 0)
a[i][j] = INF;
}
selected[0] = 1;
printf("MST edges:\n");
while (edges < n - 1) {
min = INF;
u = v = -1;
for (i = 0; i < n; i++) {
if (selected[i]) {
for (j = 0; j < n; j++) {
if (!selected[j] && a[i][j] < min) {
min = a[i][j];
u = i;
v = j;
}
}
}
}
if (u == -1) {
printf("Graph is disconnected\n");
return 0;
}
printf("%d - %d : %d\n", u, v, min);
total += min;
selected[v] = 1;
edges++;
}
printf("Total weight = %d\n", total);
return 0;
}








