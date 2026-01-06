#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} BSTree;

Node* createNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void makeEmptyNode(Node* t) {
    if (t != NULL) {
        makeEmptyNode(t->left);
        makeEmptyNode(t->right);
        free(t);
    }
}

void makeEmpty(BSTree* bst) {
    makeEmptyNode(bst->root);
    bst->root = NULL;
}

int isEmpty(BSTree* bst) {
    return bst->root == NULL;
}

void insertNode(Node** t, int val) {
    if (*t == NULL) {
        *t = createNode(val);
        return;
    }
    if (val < (*t)->value)
        insertNode(&((*t)->left), val);
    else if (val > (*t)->value)
        insertNode(&((*t)->right), val);
}

void insert(BSTree* bst, int val) {
    insertNode(&(bst->root), val);
}

Node* searchNode(Node* t, int val) {
    if (t == NULL || t->value == val)
        return t;
    if (val < t->value)
        return searchNode(t->left, val);
    return searchNode(t->right, val);
}

Node* search(BSTree* bst, int val) {
    return searchNode(bst->root, val);
}

void preorder(Node* t) {
    if (t != NULL) {
        printf("%d ", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(Node* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->value);
        inorder(t->right);
    }
}

void postorder(Node* t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->value);
    }
}

int main() {
    BSTree bst;
    bst.root = NULL;

    insert(&bst, 5);
    insert(&bst, 6);
    insert(&bst, 3);
    insert(&bst, 8);
    insert(&bst, 7);
    insert(&bst, 4);
    insert(&bst, 2);

    Node* root = search(&bst, 5);

    printf("Duyet cay thu tu truoc\n");
    preorder(root);
    printf("\n");

    Node* n1 = search(&bst, 4);
    Node* n2 = search(&bst, 9);

    if (n1 != NULL)
        printf("Node co gia tri = 4 la %d\n", n1->value);
    if (n2 == NULL)
        printf("Khong tim thay node co gia tri = 9\n");

    makeEmpty(&bst);

    if (isEmpty(&bst))
        printf("Cay da bi xoa rong\n");

    return 0;
}
