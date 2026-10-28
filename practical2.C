OBJECTIVE: Write a C program to perform various operations 2D array:
(a) Multiplication of 2 matrix
(b) Finding difference of sum of two diagonal elements.


PROGRAM:
//(a)Multiplication of 2 matrix
#include <stdio.h>
int main() {
int a[10][10], b[10][10], c[10][10];
int r1, c1, r2, c2, i, j, k;
printf("Enter rows and columns of first matrix: ");
scanf("%d%d", &r1, &c1);
printf("Enter rows and columns of second matrix: ");
scanf("%d%d", &r2, &c2);
if (c1 != r2 || r1 > 10 || c1 > 10 ||
r2 > 10 || c2 > 10 || r1 < 1 ||
c1 < 1 || r2 < 1 || c2 < 1) {
printf("Multiplication not possible\n");
return 0;
}
printf("Enter first matrix:\n");
for (i = 0; i < r1; i++)
for (j = 0; j < c1; j++)
scanf("%d", &a[i][j]);
printf("Enter second matrix:\n");
for (i = 0; i < r2; i++)
for (j = 0; j < c2; j++)
scanf("%d", &b[i][j]);
for (i = 0; i < r1; i++) {
for (j = 0; j < c2; j++) {
c[i][j] = 0;
for (k = 0; k < c1; k++)
c[i][j] += a[i][k] * b[k][j];
}
}
printf("Product matrix:\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c2; j++)
printf("%d ", c[i][j]);
printf("\n");
}
return 0;
}
//(b)Finding difference of sum of two diagonal elements.
#include <stdio.h>
#include <stdlib.h>
int main() {
int a[10][10], n, i, j;
int mainSum = 0, secSum = 0;
printf("Enter order of square matrix: ");
scanf("%d", &n);
if (n < 1 || n > 10) {
printf("Invalid size\n");
return 0;
}
printf("Enter matrix elements:\n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &a[i][j]);
for (i = 0; i < n; i++) {
mainSum += a[i][i];
secSum += a[i][n - 1 - i];
}
printf("Main diagonal sum = %d\n", mainSum);
printf("Secondary diagonal sum = %d\n", secSum);
printf("Absolute difference = %d\n",
abs(mainSum - secSum));
return 0;
}
