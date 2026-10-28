OBJECTIVE: Write a C program to create two polynomials and add them.
PROGRAM:


#include <stdio.h>
struct Term {
int coeff, exp;
};
int main() {
struct Term a[50], b[50], c[100];
int n, m, i = 0, j = 0, k = 0;
printf("Number of terms in first polynomial: ");
scanf("%d", &n);
printf("Enter coefficient and exponent in descending order:\n");
for (i = 0; i < n; i++)
scanf("%d%d", &a[i].coeff, &a[i].exp);
printf("Number of terms in second polynomial: ");
scanf("%d", &m);
printf("Enter coefficient and exponent in descending order:\n");
for (i = 0; i < m; i++)
scanf("%d%d", &b[i].coeff, &b[i].exp);
i = j = 0;
while (i < n && j < m) {
if (a[i].exp == b[j].exp) {
int sum = a[i].coeff + b[j].coeff;
if (sum != 0) {
c[k].coeff = sum;
c[k++].exp = a[i].exp;
}
i++;
j++;
} else if (a[i].exp > b[j].exp) {
c[k++] = a[i++];
} else {
c[k++] = b[j++];
}
}
while (i < n) c[k++] = a[i++];
while (j < m) c[k++] = b[j++];
printf("Sum = ");
if (k == 0) printf("0");
for (i = 0; i < k; i++) {
printf("%dx^%d", c[i].coeff, c[i].exp);
if (i < k - 1) printf(" + ");
}
printf("\n");
return 0;
}
