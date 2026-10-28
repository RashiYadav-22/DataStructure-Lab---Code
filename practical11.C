OBJECTIVE: Write a C program to Implement Sequential Search and Binary Search.
PROGRAM:

(a)Sequential Search
#include <stdio.h>
int main() {
int a[100], n, key, i, found = 0;
printf("Enter number of elements: ");
scanf("%d", &n);
if (n < 1 || n > 100) {
printf("Invalid size\n");
return 0;
}
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
printf("Enter element to search: ");
scanf("%d", &key);
for (i = 0; i < n; i++) {
if (a[i] == key) {
printf("Element found at position %d\n", i + 1);
found = 1;
break;
}
}
if (!found)
return 0;
printf("Element not found\n");
}
(b)Binary search
#include <stdio.h>
int main() {
int a[100], n, key, low, high, mid, i;
printf("Enter number of elements: ");
scanf("%d", &n);
if (n < 1 || n > 100) {
printf("Invalid size\n");
return 0;
}
printf("Enter elements in sorted order: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
printf("Enter element to search: ");
scanf("%d", &key);
low = 0;
high = n - 1;
while (low <= high) {
mid = low + (high - low) / 2;
if (a[mid] == key) {
printf("Element found at position %d\n", mid + 1);
return 0;
} else if (a[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
printf("Element not found\n");
return 0;
}
