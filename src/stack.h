#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
  int idx;
  char * state;
} Node;

typedef struct {
  Node ** nodes;
  int top;
} Stack;

Node * insert_node(int *, char *);

// Cria uma pilha vazia
Stack * init_stack();

// Insere um elemento na pilha
void push(Stack *, Node *);

// Remove um elemento na pilha
Node * pop(Stack *);

bool stack_is_empty(Stack *);

#endif
