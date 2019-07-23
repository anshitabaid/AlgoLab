#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node *left, *right;
} Node;

Node *create(Node *root, int x){

	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->value = x;
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

Node *search(Node *root, int x) {

	if (root == NULL) {
		root = create(root, x);
		printf("\nCreated\n");
		return root;
	}
	else {
		if (x < root->value) {
			root->left = search(root->left, x);
			return root;
		}
		else if (x == root->value) {
			printf("\nFound\n");
			return root;
		}
		else {
			root->right = search(root->right, x);
			return root;
		}
	}

}

void main() {

	int x, choice;
	Node *root;
	root = NULL;
	while(1) {
		printf("\n1. Insert, 2. Traversals, 3. Search\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\nEnter node (please do not enter duplicates):\n");
				scanf("%d", &x);
				root = create(root, x);
				break;
			case 2:
				printf("\nInorder traversal\n");
				inorder(root);
				printf("\nPreorder traversal\n");
				preorder(root);
				printf("\nPostorder traversal\n");
				postorder(root);
				break;
			case 3:
				printf("Enter search value:\n");
				scanf("%d", &x);
				root = search(root, x);
				break;
			default:
				printf("Exit\n");
				exit(0);
				break;
		}
	}

}