#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int index;
    int pages;
    char title[50];
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(int index, char* title, int pages) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->index = index;
    p->pages = pages;
    strcpy(p->title, title);
    p->firstChild = NULL;
    p->nextSibling = NULL;
    return p;
}

void addChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL)
        parent->firstChild = child;
    else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL)
            temp = temp->nextSibling;
        temp->nextSibling = child;
    }
}

int countChapters(Node* root) {
    int count = 0;
    Node* temp = root->firstChild;
    while (temp != NULL) {
        count++;
        temp = temp->nextSibling;
    }
    return count;
}

int totalPages(Node* root) {
    if (root == NULL) return 0;
    int sum = root->pages;
    Node* child = root->firstChild;
    while (child != NULL) {
        sum += totalPages(child);
        child = child->nextSibling;
    }
    return sum;
}

Node* findLongestChapter(Node* root) {
    Node* temp = root->firstChild;
    Node* maxNode = temp;
    int maxPages = 0;

    while (temp != NULL) {
        int p = totalPages(temp);
        if (p > maxPages) {
            maxPages = p;
            maxNode = temp;
        }
        temp = temp->nextSibling;
    }
    return maxNode;
}

Node* findNode(Node* root, int index) {
    if (root == NULL) return NULL;
    if (root->index == index) return root;

    Node* child = root->firstChild;
    while (child != NULL) {
        Node* found = findNode(child, index);
        if (found != NULL) return found;
        child = child->nextSibling;
    }
    return NULL;
}

int deleteNode(Node* parent, int index) {
    if (parent == NULL || parent->firstChild == NULL) return 0;

    Node* curr = parent->firstChild;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->index == index) {
            if (prev == NULL)
                parent->firstChild = curr->nextSibling;
            else
                prev->nextSibling = curr->nextSibling;
            free(curr);
            return 1;
        }
        if (deleteNode(curr, index)) return 1;
        prev = curr;
        curr = curr->nextSibling;
    }
    return 0;
}

void printChapter(Node* chapter) {
    if (chapter == NULL) return;
    printf("%s (%d trang)\n", chapter->title, chapter->pages);
    Node* child = chapter->firstChild;
    while (child != NULL) {
        printChapter(child);
        child = child->nextSibling;
    }
}

int main() {
    Node* book = createNode(0, "Sach Lap Trinh", 0);

    Node* c1 = createNode(1, "Chuong 1", 10);
    Node* c2 = createNode(2, "Chuong 2", 15);

    addChild(book, c1);
    addChild(book, c2);

    addChild(c1, createNode(11, "Muc 1.1", 5));
    addChild(c1, createNode(12, "Muc 1.2", 6));

    addChild(c2, createNode(21, "Muc 2.1", 7));
    addChild(c2, createNode(22, "Muc 2.2", 9));

    printf("So chuong cua sach: %d\n", countChapters(book));

    Node* longest = findLongestChapter(book);
    printf("Chuong dai nhat: %s\n", longest->title);

    printf("\nNoi dung chuong 1:\n");
    printChapter(c1);

    deleteNode(book, 12);

    printf("\nSau khi xoa muc 1.2:\n");
    printChapter(c1);

    return 0;
}
