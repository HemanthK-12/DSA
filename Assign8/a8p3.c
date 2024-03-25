#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, int item)
{
    if (stack->top == stack->capacity - 1)
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack *stack)
{
   return (isEmpty(stack))?-1:stack->array[stack->top--];
}
int peek(struct Stack *stack)
{
    return (isEmpty(stack))?-1:stack->array[stack->top];
}
int sumOfMinima(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    int res = 0;
    int leftSmaller[n], rightSmaller[n];
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && arr[peek(stack)] >= arr[i])
            pop(stack);
        if (isEmpty(stack))
            leftSmaller[i] = -1;
        else
            leftSmaller[i] = peek(stack);
        push(stack, i);
    }
    while (!isEmpty(stack))
        pop(stack);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty(stack) && arr[peek(stack)] > arr[i])
            pop(stack);
        if (isEmpty(stack))
            rightSmaller[i] = n;
        else
            rightSmaller[i] = peek(stack);
        push(stack, i);
    }
    for (int i = 0; i < n; i++)
        res = (res + arr[i] * (i - leftSmaller[i]) * (rightSmaller[i] - i)) % MOD;
    return res;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d", sumOfMinima(arr, n));
    return 0;
}