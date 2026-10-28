OBJECTIVE: Write a C program to Implement Binary Search Tree(BST) and its traversal operations.
In order traversal
Pre order traversal
Post order traversal
PROGRAM:

#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left, *right;
};
struct Node *insert(struct Node *root, int x) {
if (root == NULL) {
struct Node *p = malloc(sizeof(struct Node));
p->data = x;
p->left = p->right = NULL;
return p;
}
if (x < root->data)
root->left = insert(root->left, x);
else if (x > root->data)
root->right = insert(root->right, x);
return root;
}
void inorder(struct Node *r) {
if (r) {
inorder(r->left);
printf("%d ", r->data);
inorder(r->right);
}
}
void preorder(struct Node *r) {
if (r) {
printf("%d ", r->data);
preorder(r->left);
preorder(r->right);
}
}
void postorder(struct Node *r) {
if (r) {
postorder(r->left);
postorder(r->right);
printf("%d ", r->data);
}
}
int main() {
struct Node *root = NULL;
int n, x, i;
printf("Enter number of nodes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
scanf("%d", &x);
root = insert(root, x);
}
printf("Inorder: ");
inorder(root);
printf("\nPreorder: ");
preorder(root);
printf("\nPostorder: ");
postorder(root);
return 0;
}
