#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "parser.h"
#include "stack.h"

int main() {
  printf(">>> ");
  char * expression = read_str(NULL);

  lexical_analysis(expression);
  insert_end_sentence(expression);
  syntatic_analysis(expression);

  // Stack * stack = init_stack();
  // printf("Digite algo: ");
  // Node * node1 = insert_node(NULL, read_str(NULL));
  // printf("Digite algo: ");
  // Node * node2 = insert_node(NULL, read_str(NULL));
  // printf("Digite algo: ");
  // Node * node3 = insert_node(NULL, read_str(NULL));

  // push(stack, node1);
  // push(stack, node2);
  // push(stack, node3);

  // Node * popped1 = pop(stack);
  // Node * popped2 = pop(stack);
  // Node * popped3 = pop(stack);

  // printf(">>> %s\n", popped1->state);
  // printf(">>> %s\n", popped2->state);
  // printf(">>> %s\n", popped3->state);

  return 0;
}
