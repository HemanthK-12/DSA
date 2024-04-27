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

Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;
    Node* node = newNode(arr[i]);
    node->left = buildTree(arr, n, 2*i + 1);
    node->right = buildTree(arr, n, 2*i + 2);
    return node;
}

Node* findLCA(Node* root, int a, int b) {
    if (root == NULL) return NULL;
    if (root->data == a || root->data == b) return root;
    Node* left = findLCA(root->left, a, b);
    Node* right = findLCA(root->right, a, b);
    if (left && right) return root;
    return (left != NULL) ? left : right;
}

int main() {
    int n, A, B;
    scanf("%d %d %d", &n, &A, &B);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* root = buildTree(arr, n, 0);
    Node* lca = findLCA(root, A, B);
    printf("%d\n", lca->data);
    free(arr);
    return 0;
}