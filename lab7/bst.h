#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
    int balance;
	struct node *left, *right;
} Node;

int max(int a, int b) {
	return (a > b) ? a : b;
}

Node *create(Node *root, int x){

	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->value = x;
        root->balance = 0;
		root->left = root->right = NULL;
	}

	else if (x > root->value) {
		root->right = create(root->right, x);
	}

	else if (x < root->value) {
		root->left = create(root->left, x);
	}

	else {
		printf("\nDuplicate node\n");
		exit(0);
	}

	return root;

}

int height(Node *root) {

    if (root == NULL) {
        return 0;
    }

    return 1 + max(height(root->right), height(root->left));

}

void inorder(Node *root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%5d", root->value);
		inorder(root->right);
	}
}

void postorder(Node *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%5d", root->value);
	}
}

void preorder(Node *root) {
	if(root != NULL) {
		printf("%5d", root->value);
		preorder(root->left);
		preorder(root->right);
	}
}