OBJECTIVE: Write a C program to Implement Binary Search Tree(BST) and its traversal operations:
Insertion, Deletion, Searching
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left, *right;
};
struct Node *insert(struct Node *r, int x) {
if (!r) {
r = malloc(sizeof(struct Node));
r->data = x;
r->left = r->right = NULL;
} else if (x < r->data)
r->left = insert(r->left, x);
else if (x > r->data)
r->right = insert(r->right, x);
return r;
}
struct Node *search(struct Node *r, int x) {
if (!r || r->data == x) return r;
if (x < r->data)
return search(r->left, x);
return search(r->right, x);
}
struct Node *minimum(struct Node *r) {
while (r && r->left)
r = r->left;
return r;
}
struct Node *deleteNode(struct Node *r, int x) {
if (!r) return NULL;
if (x < r->data)
r->left = deleteNode(r->left, x);
else if (x > r->data)
r->right = deleteNode(r->right, x);
else {
if (!r->left) {
struct Node *t = r->right;
free(r);
return t;
}
if (!r->right) {
struct Node *t = r->left;
free(r);
return t;
}
struct Node *t = minimum(r->right);
r->data = t->data;
r->right = deleteNode(r->right, t->data);
}
return r;
}
void inorder(struct Node *r) {
if (r) {
inorder(r->left);
printf("%d ", r->data);
inorder(r->right);
}
}
int main() {
struct Node *root = NULL;
int ch, x;
do {
printf("\n1.Insert 2.Delete 3.Search 4.Display 0.Exit\n");
scanf("%d", &ch);
if (ch == 1) {
printf("Value: ");
scanf("%d", &x);
root = insert(root, x);
} else if (ch == 2) {
printf("Value to delete: ");
scanf("%d", &x);
root = deleteNode(root, x);
} else if (ch == 3) {
printf("Value to search: ");
scanf("%d", &x);
printf(search(root, x) ? "Found\n" : "Not found\n");
} else if (ch == 4) {
inorder(root);
printf("\n");
}
} while (ch != 0);
return 0;
}
