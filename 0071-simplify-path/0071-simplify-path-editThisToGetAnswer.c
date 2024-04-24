#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* data;
    struct node* next;
} Node;

Node* top = NULL;
Node* reverse = NULL;

void push(Node** stack, char* x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = *stack;
    *stack = newNode;
}

void pop(Node** stack) {
    if (*stack != NULL) {
        Node* temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

char* simplifyPath(char* path) {
    top=NULL;
    reverse=NULL;
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            pop(&top);
        } else if (strcmp(token, ".") != 0) {
            push(&top, token);
        }
        token = strtok(NULL, "/");
    }

    while (top != NULL) {
        push(&reverse, top->data);
        pop(&top);
    }

    Node* temp = reverse;
    char* canonicalPath = (char*)malloc(1024 * sizeof(char));
    strcpy(canonicalPath, "");
    while (temp != NULL) {
        strcat(canonicalPath, "/");
        strcat(canonicalPath, temp->data);
        temp = temp->next;
    }

    if (reverse == NULL)
        return "/";
    else
        return canonicalPath;
}