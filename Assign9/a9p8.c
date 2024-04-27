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

int sumOfDistances(Node* root, int depth) {
    if (root == NULL) return 0;
    return depth + sumOfDistances(root->left, depth + 1) + sumOfDistances(root->right, depth + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* root = buildTree(arr, n, 0);
    int sum = sumOfDistances(root, 0);
    printf("%d\n", sum);
    free(arr);
    return 0;
}