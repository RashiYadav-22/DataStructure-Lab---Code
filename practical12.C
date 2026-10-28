OBJECTIVE: Write a C program to Implement Linear Probe method for collision resolution.
PROGRAM:

#include <stdio.h>
#define SIZE 10
int hash[SIZE];
void insert(int key) {
int index = key % SIZE;
int start = index;
while (hash[index] != -1) {
index = (index + 1) % SIZE;
if (index == start) {
printf("Hash table is full\n");
return;
}
}
hash[index] = key;
printf("Inserted at index %d\n", index);
}
void display() {
printf("\nHash Table:\n");
for (int i = 0; i < SIZE; i++) {
if (hash[i] == -1)
printf("%d : Empty\n", i);
else
printf("%d : %d\n", i, hash[i]);
}
}
int main() {
int n, key;
for (int i = 0; i < SIZE; i++)
hash[i] = -1;
printf("Enter number of elements (0-10): ");
scanf("%d", &n);
if (n < 0 || n > SIZE) {
printf("Invalid size\n");
return 0;
}
for (int i = 0; i < n; i++) {
printf("Enter key: ");
scanf("%d", &key);
insert(key);
}
display();
return 0;
}
