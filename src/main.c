#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "parser.h"

int main() {
  printf(">>> ");
  char * expression = read_str(NULL);

  lexical_analysis(expression);
  insert_end_sentence(expression);
  syntatic_analysis(expression);

  return 0;
}
