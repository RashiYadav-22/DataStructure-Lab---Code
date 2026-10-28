OBJECTIVE: Write a program to create a single linked list and perform various operations:
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
p->next = NULL;
if (pos == 1) {
p->next = head;
head = p;
return;
}
struct Node *t = head;
for (int i = 1; t && i < pos - 1; i++)
t = t->next;
if (!t) {
printf("Invalid position\n");
free(p);
return;
}
p->next = t->next;
t->next = p;
}
void deleteNode(int pos) {
struct Node *t = head, *p;
if (!head) {
printf("List is empty\n");
return;
}
if (pos == 1) {
head = head->next;
free(t);
return;
}
for (int i = 1; t->next && i < pos - 1; i++)
t = t->next;
if (!t->next) {
printf("Invalid position\n");
return;
}
p = t->next;
t->next = p->next;
free(p);
}
void display() {
struct Node *t = head;
while (t) {
printf("%d -> ", t->data);
t = t->next;
}
printf("NULL\n");
}
int main() {
int ch, pos, val;
do {
printf("\n1.Insert 2.Delete 3.Display 0.Exit\n");
scanf("%d", &ch);
if (ch == 1) {
printf("Position and value: ");
scanf("%d%d", &pos, &val);
insert(pos, val);
} else if (ch == 2) {
printf("Position: ");
scanf("%d", &pos);
deleteNode(pos);
} else if (ch == 3) {
display();
}
} while (ch != 0);
return 0;
}
