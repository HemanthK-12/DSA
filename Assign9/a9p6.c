#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void kthLargestUtil(struct node* root, int k, int* c) {
    if (root == NULL || *c >= k) {
        return;
    }
    kthLargestUtil(root->right, k, c);
    *c = *c + 1;
    if (*c == k) {
        printf("%d ", root->data);
        return;
    }
    kthLargestUtil(root->left, k, c);
}

void kthLargest(struct node* root, int k) {
    int c = 0;
    kthLargestUtil(root, k, &c);
}

int main() {
    int n, k;
    printf("Enter the size of array and k: ");
    scanf("%d %d", &n, &k);
    struct node* root = NULL;
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("The kth largest element is: ");
    kthLargest(root, k);
    return 0;
}