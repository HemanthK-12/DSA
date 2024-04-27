#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct queue {
    struct node* data;
    struct queue* next;
};

struct queue* createQueueNode(struct node* data) {
    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct queue** front, struct queue** rear, struct node* data) {
    struct queue* newNode = createQueueNode(data);
    if (*rear) {
        (*rear)->next = newNode;
    }
    *rear = newNode;
    if (!*front) {
        *front = *rear;
    }
}

struct node* dequeue(struct queue** front, struct queue** rear) {
    if (!*front) {
        return NULL;
    }
    struct queue* temp = *front;
    struct node* data = temp->data;
    *front = (*front)->next;
    if (!*front) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* constructBST(int post[], int* postIndex, int key, int min, int max, int size) {
    if (*postIndex < 0) {
        return NULL;
    }
    struct node* root = NULL;
    if (key > min && key < max) {
        root = newNode(key);
        *postIndex = *postIndex - 1;
        if (*postIndex >= 0) {
            root->right = constructBST(post, postIndex, post[*postIndex], key, max, size);
            root->left = constructBST(post, postIndex, post[*postIndex], min, key, size);
        }
    }
    return root;
}

struct node* constructTree(int post[], int size) {
    int postIndex = size - 1;
    return constructBST(post, &postIndex, post[postIndex], INT_MIN, INT_MAX, size);
}

void printLevelOrder(struct node* root) {
    struct queue* front = NULL;
    struct queue* rear = NULL;
    enqueue(&front, &rear, root);
    while (front) {
        struct node* temp = dequeue(&front, &rear);
        printf("%d ", temp->data);
        if (temp->left) {
            enqueue(&front, &rear, temp->left);
        } else if (temp->right) {
            printf("-1 ");
        }
        if (temp->right) {
            enqueue(&front, &rear, temp->right);
        } else if (temp->left) {
            printf("-1 ");
        }
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int post[n];
    printf("Enter the Postorder traversal of the tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    struct node* root = constructTree(post, n);
    printf("Level order traversal of the constructed tree is \n");
    printLevelOrder(root);
    return 0;
}