#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int index;
    char title[50];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int index, char* title) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->index = index;
    strcpy(p->title, title);
    p->left = NULL;
    p->right = NULL;
    return p;
}

int isSameBook(Node* t1, Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    if (t1->index != t2->index || strcmp(t1->title, t2->title) != 0)
        return 0;
    return isSameBook(t1->left, t2->left) && isSameBook(t1->right, t2->right);
}

int main() {
    Node* book1 = createNode(1, "Chuong 1");
    book1->left = createNode(2, "Muc 1.1");
    book1->right = createNode(3, "Muc 1.2");

    Node* book2 = createNode(1, "Chuong 1");
    book2->left = createNode(2, "Muc 1.1");
    book2->right = createNode(3, "Muc 1.2");

    if (isSameBook(book1, book2))
        printf("Hai cuon sach la ban copy cua nhau\n");
    else
        printf("Hai cuon sach KHONG phai ban copy\n");

    return 0;
}
