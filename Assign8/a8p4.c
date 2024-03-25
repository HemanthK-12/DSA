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
int getMaxArea(int hist[], int n)
{
    struct Stack *stack = createStack(n);
    int max_area = 0,tp,area_with_top;
    int i = 0;
    while (i < n)
    {
        if (isEmpty(stack) || hist[peek(stack)] <= hist[i])
            push(stack, i++);
        else
        {
            tp = pop(stack);
            area_with_top = hist[tp] * (isEmpty(stack) ? i : i - peek(stack) - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (isEmpty(stack) == 0)
    {
        tp = pop(stack);
        area_with_top = hist[tp] * (isEmpty(stack) ? i : i - peek(stack) - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int hist[n];
    for (i = 0; i < n; i++)
        scanf("%d", &hist[i]);
    printf("%d", getMaxArea(hist, n));
    return 0;
}