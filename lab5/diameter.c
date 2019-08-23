#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node *left, *right;
} Node;

int max(int a, int b) {
	return (a > b) ? a : b;
}

Node *newNode(int x) {
	Node *root = (Node*)malloc(sizeof(Node));
	root->value = x;
	root->left = root->right = NULL;
	return root;
}

int height(Node *root) {

	if (root == NULL) {
		return 0;
	}

	return 1 + max(height(root->right), height(root->left));

}

int diameter(Node *root) {

	if (root == NULL) {
		return 0;
	}

	int lheight = height(root->left);
	int rheight = height(root->right);

	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);

	return max((lheight + rheight + 1), max(ldiameter, rdiameter));

}

void main() {

	// sample input
	Node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->left->right->left = newNode(5);
	root->left->right->right = newNode(6);
	root->right = newNode(7);
	root->right->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->right->left = newNode(10);
	root->right->right->right->right = newNode(11);
	root->right->right->right->left->left = newNode(12);
	root->right->right->right->left->right = newNode(13);
	printf("diameter: %d\n", diameter(root));

}