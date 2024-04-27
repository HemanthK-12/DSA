#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node *insertLevelOrder(int arr[], Node *root, int i, int n)
{
    if (i < n)
    {
        Node *temp = newNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}
int maxPathSumUtil(Node *root, int *res)
{
    if (root == NULL)
        return 0;
    int left = maxPathSumUtil(root->left, res);
    int right = maxPathSumUtil(root->right, res);
    int max_single = MAX(MAX(left, right) + root->data, root->data);
    int max_top = MAX(max_single, left + right + root->data);
    *res = MAX(*res, max_top);
    return max_single;
}
int maxPathSum(Node *root)
{
    int res = INT_MIN;
    maxPathSumUtil(root, &res);
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    Node *root = insertLevelOrder(arr, root, 0, n);
    printf("Max path sum is %d", maxPathSum(root));
    return 0;
}