#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct queue {
    Node* data;
    struct queue* next;
}Queue;

Queue* createQueueNode(Node* data) {
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue** front, Queue** rear, Node* data) {
    Queue* newNode = createQueueNode(data);
    if (*rear) {
        (*rear)->next = newNode;
    }
    *rear = newNode;
    if (!*front) {
        *front = *rear;
    }
}

Node* dequeue(Queue** front, Queue** rear) {
    if (!*front) {
        return NULL;
    }
    Queue* temp = *front;
    Node* data = temp->data;
    *front = (*front)->next;
    if (!*front) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

int search(int arr[], int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildTree(int in[], int pre[], int inStrt, int inEnd) {
    static int preIndex = 0;
    if (inStrt > inEnd)
        return NULL;
    Node* tNode = newNode(pre[preIndex++]);
    if (inStrt == inEnd)
        return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}

void printLevelOrder(Node* root)
{
    if (root == NULL) {
        return;
    }
    Queue* front = NULL;
    Queue* rear = NULL;
    enqueue(&front, &rear, root);
    while (front) {
        Node* temp = dequeue(&front, &rear);
        printf("%d ", temp->data);
        if (temp->left) {
            enqueue(&front, &rear, temp->left);
        } else if (temp->right) {  // If left child is NULL and right child is not NULL
            printf("-1 ");
        }
        if (temp->right) {
            enqueue(&front, &rear, temp->right);
        } else if (temp->left) {  // If right child is NULL and left child is not NULL
            printf("-1 ");
        }
    }
}

int main() {
    int n;
    printf("Enter the size of arrays: ");
    scanf("%d", &n);
    int in[n], pre[n];
    printf("Enter the Inorder traversal of the tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    printf("Enter the Preorder traversal of the tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    Node* root = buildTree(in, pre, 0, n - 1);
    printf("Level order traversal of the constructed tree is \n");
    printLevelOrder(root);
    return 0;
}