#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Node * insert_node(int * idx, char * state) {
  Node * node = (Node *) malloc(sizeof(Node));
  if (idx == NULL) {
    node->state = (char *) malloc(sizeof(char) * strlen(state));
    strcpy(node->state, state);
  } else {
    node->idx = *idx;
  }

  return node;
}

Stack * init_stack() {
  Stack * stack = (Stack *) malloc(sizeof(Stack));
  if (stack == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }
  stack->top = 0;
  stack->nodes = (Node **) malloc(sizeof(Node *));
  stack->nodes[stack->top] = (Node *) malloc(sizeof(Node));
  stack->nodes[stack->top] = NULL;

  return stack;
}

void push(Stack * stack, Node * node) {
  stack = (Stack *) realloc(stack, sizeof(Node *) * ++(stack->top));
  stack->nodes = (Node **) realloc(stack->nodes, sizeof(Node *) * stack->top);
  stack->nodes[stack->top] = node;
}

Node * pop(Stack * stack) {
  if (!stack_is_empty(stack)) {
    Node * node = stack->nodes[stack->top];
    stack = (Stack *) realloc(stack, sizeof(Node *) * stack->top--);

    return node;
  }

  return NULL;
}

bool stack_is_empty(Stack * stack) {
  return stack->top == 0;
}
