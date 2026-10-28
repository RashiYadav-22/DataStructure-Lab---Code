OBJECTIVE: Write a C program to create a Circular Linked List and perform various operations:
(a) Insertion at: (i) Beg (ii) End (iii) Any position
(b) Deletion at: (i) Beg (ii) End (iii) Any position
PROGRAM:


#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node *head = NULL;
void insert(int pos, int val) {
struct Node *p = malloc(sizeof(struct Node));
p->data = val;
if (pos < 1) {
printf("Invalid position\n");
free(p);
return;
}
if (!head) {
if (pos != 1) {
printf("Invalid position\n");
free(p);
return;
}
head = p;
p->next = head;
return;
}
if (pos == 1) {
struct Node *t = head;
while (t->next != head)
t = t->next;
p->next = head;
t->next = p;
head = p;
return;
}
struct Node *t = head;
for (int i = 1; i < pos - 1 && t->next != head; i++)
t = t->next;
if (t->next == head && pos > 1) {
int count = 1;
struct Node *q = head;
while (q->next != head) {
count++;
q = q->next;
}
if (pos > count + 1) {
printf("Invalid position\n");
free(p);
return;
}
}
p->next = t->next;
t->next = p;
}
void deleteNode(int pos) {
if (!head || pos < 1) {
printf("List empty or invalid position\n");
return;
}
struct Node *t = head, *p;
if (pos == 1) {
if (head->next == head) {
free(head);
head = NULL;
return;
}
while (t->next != head)
t = t->next;
p = head;
