#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
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
int isMatchingPair(char character1, char character2)
{
    return ((character1 == '(' && character2 == ')')||(character1 == '{' && character2 == '}')||(character1 == '[' && character2 == ']'))?1:0;
}
int areBracketsBalanced(char exp[])
{
    int i = 0;
    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;
    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
            if ((isEmpty(stack))||(!isMatchingPair(pop(stack), exp[i])))
                return 0;
        i++;
    }
    return (isEmpty(stack))?1:0;
}
int main()
{
    char exp[10000];
    printf("Enter the expression: ");
    scanf("%[^\n]", exp);
    getchar(); // consume newline character
    if (areBracketsBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}