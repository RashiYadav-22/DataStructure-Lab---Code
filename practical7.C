OBJECTIVE: Write a C program to Implement Stack using Array and Linked List.
PROGRAM:

#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;
void push(int x) {
if (top == MAX - 1)
printf("Stack Overflow\n");
else
stack[++top] = x;
}
void pop() {
if (top == -1)
printf("Stack Underflow\n");
else
printf("Deleted: %d\n", stack[top--]);
}
void display() {
if (top == -1) {
printf("Stack is empty\n");
return;
}
for (int i = top; i >= 0; i--)
printf("%d\n", stack[i]);
}
int main() {
int ch, x;
do {
printf("\n1.Push 2.Pop 3.Display 0.Exit\n");
scanf("%d", &ch);
if (ch == 1) {
printf("Enter value: ");
scanf("%d", &x);
push(x);
} else if (ch == 2)
pop();
else if (ch == 3)
display();
} while (ch != 0);
return 0;
}
// Stack Using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node *top = NULL;
void push(int x) {
struct Node *p = malloc(sizeof(struct Node));
if (!p) {
printf("Memory full\n");
return;
}
p->data = x;
p->next = top;
top = p;
}
void pop() {
if (!top) {
printf("Stack Underflow\n");
return;
}
struct Node *p = top;
printf("Deleted: %d\n", p->data);
top = top->next;
free(p);
}
void display() {
struct Node *p = top;
if (!p) printf("Stack is empty\n");
while (p) {
printf("%d\n", p->data);
p = p->next;
}
}
int main() {
int ch, x;
do {
printf("\n1.Push 2.Pop 3.Display 0.Exit\n");
scanf("%d", &ch);
if (ch == 1) {
printf("Enter value: ");
scanf("%d", &x);
push(x);
} else if (ch == 2)
pop();
else if (ch == 3)
display();
} while (ch != 0);
return 0;
}
