#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "parser.h"
#include "lexical_analyzer.h"

// Realiza a análise léxica da sentença
void lexical_analyze(const char * expression) {
  if (!check_tokens(expression)) exit(1);
  if (!analyse(expression)) {
      printf("\nEntrada inválida!\n");
      exit(1);
  }
}
