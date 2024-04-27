#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
    return node;
}

void printLevelOrder(Node* root) {
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(Node* node) {
    if (node==NULL) return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight) return(lheight+1);
        else return(rheight+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printLevelOrder(root);
    return 0;
}