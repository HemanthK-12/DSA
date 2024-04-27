#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node* next;
} Node;

Node* top = NULL;

void push(char x)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top != NULL)
    {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

bool isValid(char* s)
{
    top=NULL;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char a = (*(s+i));
        if (a == '{' || a == '(' || a == '[')
            push(a);
        else 
        {
            if (top == NULL) 
                return false;
            char b = (char) top->data;
            if ((a == '}' && b == '{') || (a == ']' && b == '[') || (a == ')' && b == '('))
                pop();
            else
                return false;
        }
    }
    bool res=(top==NULL);
    while(top!=NULL)
        pop();
    if (res)
        return true;
    else
        return false;
}