#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000
typedef struct
{
    int top;
    int data[MAX_SIZE];
    int min[MAX_SIZE];
} Stack;
typedef struct
{
    int front, rear, size;
    unsigned capacity;
    int *array;
    long long int sum;
} Queue;
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}
Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    queue->sum = 0;
    return queue;
}
void push(Stack *stack, int new_data)
{
    stack->data[++stack->top] = new_data;
    if (stack->top == 0)
        stack->min[stack->top] = new_data;
    else
        stack->min[stack->top] = new_data < stack->min[stack->top - 1] ? new_data : stack->min[stack->top - 1];
}
void enqueue(Queue *queue, int item)
{
    if (queue->size == queue->capacity)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    queue->sum += item;
}
void pop(Stack *stack)
{
    if (stack->top == -1)
        return;
    stack->top--;
}
void dequeue(Queue *queue)
{
    if (queue->size == 0)
        return;
    int item = queue->array[queue->front];
    queue->sum -= item;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
}
int getMin(Stack *stack)
{
    return stack->min[stack->top];
}
int getAvg(Queue *queue)
{
    return queue->sum / queue->size;
}
int main()
{
    int q;
    scanf("%d", &q);
    Stack *stack = createStack();
    Queue *queue = createQueue(MAX_SIZE);
    while (q--)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int x;
            scanf("%d", &x);
            push(stack, x);
            enqueue(queue, x);
        }
        else if (type == 2)
        {
            pop(stack);
            dequeue(queue);
        }
        else if (type == 3)
            printf("%d %d\n", getMin(stack), getAvg(queue));
    }
    return 0;
}