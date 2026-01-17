#include <stdio.h>
#include <stdlib.h>

/* BST Node */
struct bst {
    int data;
    struct bst *left;
    struct bst *right;
};

typedef struct bst NODE;

/* Create a new node */
NODE* createNode(int data) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Insert into BST */
NODE* insert(NODE *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

/* Inorder Traversal */
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(NODE *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search in BST */
int search(NODE *root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    NODE *root = NULL;
    int choice, data, key, n, i;

    while (1) {
        printf("\n1. Create BST");
        printf("\n2. Search Element");
        printf("\n3. Traversals");
        printf("\n4. Exit");
        printf("\nEnter choice:\n");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of elements:\n");
                scanf("%d", &n);
                printf("Enter elements:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;

            case 2:
                printf("Enter element to search:\n");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Search successful\n");
                else
                    printf("Search unsuccessful\n");
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
