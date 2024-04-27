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
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    if (i < n) {
        if (arr[i] == -1) {
            return NULL;
        }
        Node* temp = newNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

Node* cutTree(Node* root, int k) {
    if (root == NULL) return NULL;
    if (root->data == k) return NULL;
    root->left = cutTree(root->left, k);
    root->right = cutTree(root->right, k);
    return root;
}

int height(Node* node) {
    if (node == NULL) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* root = insertLevelOrder(arr, root, 0, n);
    root = cutTree(root, k);
    printf("%d", height(root));
    return 0;
}