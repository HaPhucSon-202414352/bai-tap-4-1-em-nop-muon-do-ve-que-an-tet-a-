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

int isSameTree(Node* t1, Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    if (t1->data != t2->data)
        return 0;
    return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

int main() {
    Node* t1 = createNode(1);
    t1->left = createNode(2);
    t1->right = createNode(3);

    Node* t2 = createNode(1);
    t2->left = createNode(2);
    t2->right = createNode(3);

    if (isSameTree(t1, t2))
        printf("Hai cay nhi phan giong nhau");
    else
        printf("Hai cay nhi phan KHONG giong nhau");

    return 0;
}
