OBJECTIVE: Write a C program to Implement:
(a) Bubble Sort (b) Selection Sort (c) Insertion Sort
(d) Quick Sort (e) Shell Sort (f) Radix Sort (g) Merge Sort
PROGRAM:

(a) Bubble Sort

#include <stdio.h>
int main() {
int a[100], n, i, j, t;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (a[j] > a[j + 1]) {
t = a[j];
a[j] = a[j + 1];
a[j + 1] = t;
}
}
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
(b) Selection sort

#include <stdio.h>
int main() {
int a[100], n, i, j, min, t;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (i = 0; i < n - 1; i++) {
min = i;
for (j = i + 1; j < n; j++)
if (a[j] < a[min])
min = j;
t = a[i];
a[i] = a[min];
a[min] = t;
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
(c) Insertion Sort 

#include <stdio.h>
int main() {
int a[100], n, i, j, key;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (i = 1; i < n; i++) {
key = a[i];
j = i - 1;
while (j >= 0 && a[j] > key) {
a[j + 1] = a[j];
j--;
}
a[j + 1] = key;
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
(d) Quick Sort

#include <stdio.h>
void quickSort(int a[], int n) {
int stack[200], top = -1;
int low, high, i, j, pivot, t;
if (n < 2) return;
stack[++top] = 0;
stack[++top] = n - 1;
while (top >= 0) {
high = stack[top--];
low = stack[top--];
pivot = a[high];
i = low - 1;
for (j = low; j < high; j++) {
if (a[j] <= pivot) {
i++;
t = a[i]; a[i] = a[j]; a[j] = t;
}
}
t = a[i + 1];
a[i + 1] = a[high];
a[high] = t;
int p = i + 1;
if (p - 1 > low) {
stack[++top] = low;
stack[++top] = p - 1;
}
if (p + 1 < high) {
stack[++top] = p + 1;
stack[++top] = high;
}
}
}
int main() {
int a[100], n, i;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
quickSort(a, n);
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;}
e) Shell Sort
#include <stdio.h>
int main() {
int a[100], n, i, j, gap, temp;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (gap = n / 2; gap > 0; gap /= 2) {
for (i = gap; i < n; i++) {
temp = a[i];
for (j = i; j >= gap &&
a[j - gap] > temp; j -= gap)
a[j] = a[j - gap];
a[j] = temp;
}
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
(f) Radix Sort

#include <stdio.h>
int getMax(int a[], int n) {
int max = a[0];
for (int i = 1; i < n; i++)
if (a[i] > max) max = a[i];
return max;
}
void countSort(int a[], int n, int exp) {
int output[100], count[10] = {0};
for (int i = 0; i < n; i++)
count[(a[i] / exp) % 10]++;
for (int i = 1; i < 10; i++)
count[i] += count[i - 1];
for (int i = n - 1; i >= 0; i--) {
int d = (a[i] / exp) % 10;
output[--count[d]] = a[i];
}
for (int i = 0; i < n; i++)
a[i] = output[i];
}
int main() {
int a[100], n, max;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter non-negative elements: ");
for (int i = 0; i < n; i++) {
scanf("%d", &a[i]);
if (a[i] < 0) {
printf("Negative numbers not supported\n");
return 0;
}
}
max = getMax(a, n);
for (int exp = 1; max / exp > 0; ) {
countSort(a, n, exp);
if (exp > max / 10) break;
exp *= 10;
}
printf("Sorted array: ");
for (int i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
(g) Merge Sort

#include <stdio.h>
int main() {
int a[100], temp[100], n, i, width, left;
int mid, right, x, y, k;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1 || n > 100) return 0;
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (width = 1; width < n; width *= 2) {
for (left = 0; left < n; left += 2 * width) {
mid = left + width;
right = left + 2 * width;
if (mid > n) mid = n;
if (right > n) right = n;
x = left;
y = mid;
k = left;
while (x < mid && y < right) {
if (a[x] <= a[y])
temp[k++] = a[x++];
else
temp[k++] = a[y++];
}
while (x < mid) temp[k++] = a[x++];
while (y < right) temp[k++] = a[y++];
}
for (i = 0; i < n; i++)
a[i] = temp[i];
if (width > n / 2) break;
}
printf("Sorted array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}

