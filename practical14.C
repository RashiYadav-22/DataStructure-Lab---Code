OBJECTIVE: Write a C program to Implement of Heapsort.
PROGRAM:

#include <stdio.h>
void heapify(int a[], int n, int i) {
int largest = i, left = 2 * i + 1;
int right = 2 * i + 2, t;
if (left < n && a[left] > a[largest])
largest = left;
if (right < n && a[right] > a[largest])
largest = right;
if (largest != i) {
t = a[i];
a[i] = a[largest];
a[largest] = t;
heapify(a, n, largest);
}
}
int main() {
int a[100], n, i, t;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (i = n / 2 - 1; i >= 0; i--)
heapify(a, n, i);
for (i = n - 1; i > 0; i--) {
t = a[0];
a[0] = a[i];
a[i] = t;
heapify(a, i, 0);
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
