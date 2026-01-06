#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(Node* root) {
    if (root == NULL) return;

    Node* largest = root;

    if (root->left && root->left->data > largest->data)
        largest = root->left;

    if (root->right && root->right->data > largest->data)
        largest = root->right;

    if (largest != root) {
        swap(&root->data, &largest->data);
        heapify(largest);
    }
}

void buildHeap(Node* root) {
    if (root == NULL) return;
    buildHeap(root->left);
    buildHeap(root->right);
    heapify(root);
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(16);
    root->right = createNode(14);
    root->left->left = createNode(2);
    root->left->right = createNode(8);
    root->right->left = createNode(1);
    root->right->right = createNode(3);

    printf("Duyet truoc: ");
    preorder(root);

    printf("\nDuyet giua: ");
    inorder(root);

    printf("\nDuyet sau: ");
    postorder(root);

    buildHeap(root);

    printf("\n\nSau khi vun dong (duyet truoc): ");
    preorder(root);

    return 0;
}
