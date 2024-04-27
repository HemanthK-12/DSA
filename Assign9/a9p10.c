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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(Node* tree) {
    if (tree == NULL) return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight, max(ldiameter, rdiameter));
}

Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
    return node;
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        if (data != -1) {
            root = insert(root, data);
        }
    }
    printf("%d\n", diameter(root));
    return 0;
}