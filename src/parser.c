#include <stdio.h>            // printf
#include <stdlib.h>           // exit, realloc
#include <string.h>           // strlen, strcat
#include "token.h"            // check_tokens
#include "parser.h"
#include "lexical_analyser.h" // analyse
#include "stack.h"
#include "utils.h"

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

   Stack * pilha = init_stack();

   Node * nodeInicial = insert_node(0, read_str(NULL));

   push(pilha, nodeInicial);

Node * acaoNo, * estadoNo;

  // Teste do vetor
  for(int i = 0; tokens[i] != NULL; i++) {

    Node * noTopo = pop(pilha);

    int estadoTopo = noTopo->idx;

    char * token = tokens[i];

    char * acao = "";
    int estadoAtual;

    // Vai definir se vai reduzir ou shift

    switch(estadoTopo) {

        case 0:

            strcpy(acao, "s");

            if(token[0] >= '0' && token[0] <= '9') {
                estadoAtual = 4;
            }
            else strcpy(acao, "e");

            break;

        case 1:
            strcpy(acao, "s");

            if(strcmp(token, "sen")) estadoAtual = 6;
            else if(strcmp(token, "cos")) estadoAtual = 6;
            else if(strcmp(token, "exp")) estadoAtual = 6;
            else if(token[0] >= '0' && token[0] <= '9') estadoAtual = 4;
            else strcpy(acao, "e");

            break;

        case 2:
            strcpy(acao, "r");

            if(token[0] >= '0' && token[0] <= '9') {
                strcpy(acao, "s");
                estadoAtual = 4;
            }
            else if(strcmp(token, "sen") || strcmp(token, "cos") || strcmp(token, "exp") || token[0] == '$') {
                strcpy(acao, "r");
                estadoAtual = 3;
            }
            else
                strcpy(acao, "e");

            break;

        case 3:

            if(token[0] == '*' || token[0] == '$') strcpy(acao, "e");
            else {
                strcpy(acao, "e");
            };

            break;

        case 4:

            strcpy(acao, "r");
            estadoAtual = 10;

            break;

        case 5:

            if((token[0] >= '0' && token[0] <= '9') || token[0] == '/' || strcmp(token, "sen")  || strcmp(token, "cos")  || strcmp(token, "exp")) {
                estadoAtual = 3;
                strcpy(acao, "r");
            }
            else if(token[0] == '+' || token[0] == '-') {
                strcpy(acao, "s");
                estadoAtual = token[0] == '+' ? 11 : 12;
            }
            else strcpy(acao, "e");

            break;

        case 6:

            if(token[0] == '*') {
                strcpy(acao, "s");
                estadoAtual = 13;
            }
            else strcpy(acao, "e");

            break;

        case 7:

            if(token[0] == '*') {
                strcpy(acao, "s");
                estadoAtual = 14;
            }
            else strcpy(acao, "e");

            break;

        case 8:

            if(token[0] == '*') {
                strcpy(acao, "s");
                estadoAtual = 15;
            }
            else strcpy(acao, "e");

            break;

        case 9:

            strcpy(acao, "s");

            if(strcmp(token, "sen")) estadoAtual = 8;
            else if(strcmp(token, "cos")) estadoAtual = 7;
            else if(strcmp(token, "exp")) estadoAtual = 6;
            else if(token[0] >= '0' && token[0] <= '9') estadoAtual = 4;
            else strcpy(acao, "e");

            break;

        case 10:

            switch(token[0]) {
                case '*':
                case '/':
                    strcpy(acao, "e");
                    break;

                default:
                  strcpy(acao, "r");
                  estadoAtual = 6;
            }

            break;

        case 11:

            if(strcmp(token, "sen") || strcmp(token, "cos") ||strcmp(token, "exp")) strcpy(acao, "e");
            else {
                strcpy(acao, "r");
                estadoAtual = 1;
            }

            break;

        case 12:

            if(strcmp(token, "sen") || strcmp(token, "cos") ||strcmp(token, "exp")) strcpy(acao, "e");
            else {
                strcpy(acao, "r");
                estadoAtual = 2;
            }

            break;

        case 13:
             strcpy(acao, "r");
            estadoAtual = 7;

            break;

        case 14:
            strcpy(acao, "r");
            estadoAtual = 8;

            break;

        case 15:
            strcpy(acao, "r");
            estadoAtual = 9;

            break;

        case 16:
            if(token[0] == '/' || token[0] == '*') {
                strcpy(acao, "e");
            }
            else {
                strcpy(acao, "r");
                estadoAtual = 4;
            }

            break;

        case 17:
            if(token[0] == '/' || token[0] == '*') {
                strcpy(acao, "e");
            }
            else {
                strcpy(acao, "r");
                estadoAtual = 5;
            }


            break;
    }

    if(strcmp(acao, "s") == 0) {

        acaoNo = insert_node(NULL, read_str(acao));
        estadoNo = insert_node(&estadoAtual, NULL);

        push(pilha, acaoNo);
        push(pilha, estadoNo);

    } else if (strcmp(acao, "a") == 0) {
        printf("Sentenca aceita\n");
        return;
    } else {
        printf("Sentenca invalida\n");
        return;
    }

  }
}


/*
0 E' -> E
1 E -> E T +
2 E -> E T -
3 E -> T
4 T -> T F *
5 T -> T F /
6 T -> F
7 F -> E sen *
8 F -> E cos *
9 F -> E exp *
10 F -> num
*/

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

  free(cpy);

  return tokens;
}
