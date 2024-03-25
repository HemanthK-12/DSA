#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure definition
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack) 
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {   
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;          
    return stack->array[stack->top--];
}

// Function to check if character x is an opening bracket and character y is an matching closing bracket
int isMatchingPair(char character1, char character2) {
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

// Function to check if brackets in given expression are balanced
int areBracketsBalanced(char exp[]) {
    int i = 0;
  
    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) 
        return -1;

    while (exp[i]) {
        // If the exp[i] is a starting bracket then push it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);

        // If exp[i] is an ending bracket then pop from stack and check if the popped bracket is a matching pair
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // If we see an ending bracket without a pair then return false
            if (isEmpty(stack)) {
              return 0;
            } else if ( !isMatchingPair(pop(stack), exp[i]) ) {
              return 0;
            }
        }
        i++;
    }

    // If there is something left in expression then there is a starting bracket without a closing bracket
    if (isEmpty(stack)) {
        return 1; // balanced
    } else {
        return 0;  // not balanced
    }
}

// Driver program to test above function
int main() {
    char exp[10000];
    printf("Enter the expression: ");
    scanf("%[^\n]", exp);
    getchar();  // consume newline character
    if (areBracketsBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}