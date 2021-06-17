#include <stdio.h>            // printf
#include <stdlib.h>           // exit, realloc
#include <string.h>           // strlen, strcat
#include "token.h"            // check_tokens
#include "parser.h"
#include "lexical_analyser.h" // analyse

// Insere o indicador de fim de sentença
void insert_end_sentence(char * expression) {
  expression = realloc(expression, sizeof(char) * 4 + sizeof(char) * strlen(expression));
  strcat(expression, "<$>\0");
}

// Realiza a análise léxica da sentença
void lexical_analysis(const char * expression) {
  if (!check_tokens(expression)) exit(1);
  if (!analyse(expression)) {
      printf("\nEntrada inválida!\n");
      exit(1);
  }
}

// Realiza a análise sintática
void syntatic_analysis(const char * expression) {
  char ** tokens = extract_tokens(expression);

  // for(int i = 0;; i++) {
  //   if (tokens[i] == NULL) break;
  //   printf("%s\n", tokens[i]);
  // }

  // create_syntax_table(tokens);
  // create_syntax_stack(tokens);
  // create_action_table(tokens);
  // create_goto_table(tokens);
  // analyse_syntax(tokens);
}

// Extrai os tokens da expressão e gera um vetor de tokens
char ** extract_tokens(const char * expression) {
  char * cpy = (char *) malloc(sizeof(char) * strlen(expression));
  char token[10];
  char ** tokens = (char **) malloc(0);
  int idx = 0;
  strcpy(cpy, expression);

  do {
    if(!get_token(cpy, token)) {
      printf("Erro ao extrair token.\n");
      exit(1);
    }

    tokens = (char **) realloc(tokens, sizeof(*tokens) * (idx + 1));
    tokens[idx] = (char *) malloc(strlen(token));
    strcpy(tokens[idx], token);
    idx++;
  } while(( (int)(strlen(cpy)/sizeof(char)) ) > 0);


  // Último elemento
  tokens = (char **) realloc(tokens, sizeof(*tokens) * (idx + 1));
  tokens[idx] = (char *) malloc(sizeof(char));
  tokens[idx] = NULL;

  return tokens;
}
