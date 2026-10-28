OBJECTIVE: Write a C program to Implement Queue using Array and Linked List.
PROGRAM:

//(a) Queue using an array
#include <stdio.h>
#define MAX 5
int q[MAX], front = 0, rear = -1, count = 0;
void enqueue(int x) {
if (count == MAX) {
printf("Queue Overflow\n");
return;
}
rear = (rear + 1) % MAX;
q[rear] = x;
count++;
}
void dequeue() {
if (count == 0) {
printf("Queue Underflow\n");
return;
}
printf("Deleted: %d\n", q[front]);
front = (front + 1) % MAX;
count--;
}
void display() {
if (count == 0) {
printf("Queue is empty\n");
return;
}
for (int i = 0; i < count; i++)
printf("%d ", q[(front + i) % MAX]);
printf("\n");
}
int main() {
int ch, x;
do {
printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
scanf("%d", &ch);
if (ch == 1) {
printf("Enter value: ");
scanf("%d", &x);
enqueue(x);
} else if (ch == 2)
dequeue();
else if (ch == 3)
display();
} while (ch != 0);
return 0;}
(b) Queue using a linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int x) {
struct Node *p = malloc(sizeof(struct Node));
if (!p) {
printf("Memory full\n");
return;
}
p->data = x;
p->next = NULL;
if (rear == NULL)
front = rear = p;
else {
rear->next = p;
rear = p;
}
}
void dequeue() {
if (front == NULL) {
printf("Queue Underflow\n");
return;
}
struct Node *p = front;
printf("Deleted: %d\n", p->data);
front = front->next;
if (front == NULL) rear = NULL;
free(p);
}
void display() {
struct Node *p = front;
if (!p) printf("Queue is empty\n");
while (p) {
printf("%d ", p->data);
p = p->next;
}
printf("\n");
}
int main() {
int ch, x;
do {
printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
scanf("%d", &ch);
if (ch == 1) {
printf("Enter value: ");
scanf("%d", &x);
enqueue(x);
} else if (ch == 2)
dequeue();
else if (ch == 3)
display();
} while (ch != 0);
return 0;
}
