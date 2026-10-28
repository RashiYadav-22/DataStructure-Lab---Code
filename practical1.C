OBJECTIVE: : Write a C program to create array and perform various operations.
(a) Insertion at : (i) Beg (ii) End (iii) Any position
(b) Deletion from : (i) Beg (ii) End (iii) Any position
PROGRAM:


#include <stdio.h>
int main() {
int a[100], n, i, ch, pos, val;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
printf("1.Insert 2.Delete\n");
scanf("%d", &ch);
if (ch == 1) {
printf("1.Beginning 2.End 3.Position: ");
scanf("%d", &pos);
if (pos == 1) pos = 0;
else if (pos == 2) pos = n;
else {
printf("Enter position: ");
scanf("%d", &pos);
pos--;
}
if (n >= 100 || pos < 0 || pos > n) {
printf("Invalid operation\n");
return 0;
}
printf("Enter value: ");
scanf("%d", &val);
for (i = n; i > pos; i--)
a[i] = a[i - 1];
a[pos] = val;
n++;
} else if (ch == 2) {
printf("1.Beginning 2.End 3.Position: ");
scanf("%d", &pos);
if (n == 0) {
printf("Array is empty\n");
return 0;
}
if (pos == 1) pos = 0;
else if (pos == 2) pos = n - 1;
else {
printf("Enter position: ");
scanf("%d", &pos);
pos--;
}
if (pos < 0 || pos >= n) {
printf("Invalid position\n");
return 0;
}
for (i = pos; i < n - 1; i++)
a[i] = a[i + 1];
n--;
} else {
printf("Invalid choice\n");
return 0;
}
printf("Array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
