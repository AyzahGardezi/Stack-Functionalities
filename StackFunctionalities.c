#include <stdbool.h>
#include <stdlib.h>

// A node in our linked list
typedef struct node {
  int data;
  struct node *next;
} Node;

// Our stack, implemented as a wrapper around our linked list
typedef struct {
  Node *root;
} Stack;

// Modify the code below to implement the key operations for our stack
void stack_push(Stack *stack, int data) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  if (!stack->root)
    {
    newNode->next = NULL;
    stack->root = newNode;
  }
  else
  {
    newNode->next = stack->root;
    stack->root = newNode;
  }
}

int stack_pop(Stack *stack) {
  if(stack->root)
  {
    int data = stack->root->data;
    stack->root = stack->root->next;
    return data;
  }
  return 0;
}
  
int stack_peek(const Stack *stack) {
  if (!stack->root)
    return 0;
  return stack->root->data;
}
  
bool stack_is_empty(const Stack *stack) {
  return (stack->root ? false : true);
}
