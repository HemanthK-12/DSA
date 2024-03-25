#include <stdio.h>
#include <stdlib.h>
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
void findNextWeights(int weights[], int n, int nextGreater[], int nextLesser[])
{
    struct Stack *stack = createStack(n);
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && weights[i] > weights[peek(stack)])
        {
            int idx = pop(stack);
            nextGreater[idx] = i - idx;
        }
        push(stack, i);
    }
    while (!isEmpty(stack))
    {
        int idx = pop(stack);
        nextGreater[idx] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && weights[i] < weights[peek(stack)])
        {
            int idx = pop(stack);
            nextLesser[idx] = i - idx;
        }
        push(stack, i);
    }
    while (!isEmpty(stack))
    {
        int idx = pop(stack);
        nextLesser[idx] = 0;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int weights[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);
    int nextGreater[n], nextLesser[n];
    findNextWeights(weights, n, nextGreater, nextLesser);
    for (int i = 0; i < n; i++)
        printf("%d ", nextGreater[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", nextLesser[i]);
    return 0;
}