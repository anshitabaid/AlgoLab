#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

typedef struct node {
	int value;
	struct node *left, *right;
} Node;

Node *newNode(int x) {
	Node *root = (Node*)malloc(sizeof(Node));
	root->value = x;
	root->left = root->right = NULL;
	return root;
}

int count(Node *root) {

	opcount++;

	if (root == NULL) {
		return 0;
	}

	return 1 + count(root->left) + count(root->right);

}

int main() {

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
	printf("number of nodes: %d\n", count(root));
	printf("OP count: %d\n", opcount);

}
