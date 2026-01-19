#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

bool search(struct Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    
    printf("Binary Search Tree Demo\n");
    printf("======================\n\n");
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    int key = 40;
    if (search(root, key)) {
        printf("Element %d found in BST\n", key);
    } else {
        printf("Element %d not found in BST\n", key);
    }
    
    return 0;
}
