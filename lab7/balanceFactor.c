#include "bst.h"

void balanceFactor(Node *root) {
    if (root == NULL) {
        return;
    }

    root->balance = height(root->left) - height(root->right);

    balanceFactor(root->right);
    balanceFactor(root->left);
}

void balanceInorder(Node *root) {
	if(root != NULL) {
		balanceInorder(root->left);
		printf("%5d", root->balance);
		balanceInorder(root->right);
	}
}

int main() {

    int n, x, ch, i;
    Node *root;
    root = NULL;
    while(1) {
        printf("\n\n1. Insert\t2. All Traversals\t3. Balance Factor\n> ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter node (do not enter duplicate nodes):\t");
                scanf("%d", &x);
                root = create(root, x);
                break;
            case 2:
                printf("\n\nInorder Traversal\n\n");
                inorder(root);
                printf("\n\nPreorder Traversal\n\n");
                preorder(root);
                printf("\n\nPostorder Traversal\n\n");
                postorder(root);
                break;
            case 3:
                printf("\n\nBalance Factor\n\n");
                balanceFactor(root);
                balanceInorder(root);
                break;
            default:
                printf("Invalid, try again.");
                exit(1);
        }
    }

}
