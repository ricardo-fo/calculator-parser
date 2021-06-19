#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "parser.h"
#include "table.h"

int main() {
  printf("Insira a expressão pós-fixa utilizando tokens: ");
  char * expression = read_str(NULL);

  printf("\nAnálise léxica:\n");
  lexical_analysis(expression);
  insert_end_sentence(expression);

  printf("\nSua expressão em lista:\n");
  syntatic_analysis(expression);

  printf("\n# TABELA SINTÁTICA:\n");
  show_table();

  return 0;
}
