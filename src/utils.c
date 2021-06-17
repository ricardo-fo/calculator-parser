#include <stdio.h>  // getchar
#include <stdlib.h> // malloc, realloc, size_t
#include <string.h> // strcpy, strlen
#include <ctype.h>  // isspace, tolower
#include "utils.h"

/**
 * Aloca dinamicamente uma string, onde o input pode ser passado por argumento
 * ou inserido pelo próprio usuário, retornando um ponteiro para o endereço de
 * memória alocado.
 *
 * return: char *
 */
char * read_str(char * str) {
  char * dyn_str = (char *) malloc(0);
  size_t len = 0;

  if (str != NULL) {
    // Aloca dinamicamente a string passada por argumento
    dyn_str = (char *) realloc(dyn_str, sizeof(char) * strlen(str));
    strcpy(dyn_str, str);
  } else {
    // Aloca dinamicamente a string passada pelo usuário
    char ch;
    while((ch = getchar()) != '\n') {
      if (isspace(ch)) continue;

      ch = tolower(ch);
      len += sizeof(char);
      dyn_str = (char *) realloc(dyn_str, len);
      dyn_str[(int)(len) - 1] = ch;
    }
  }

  // Indicador do fim da string
  len += sizeof(char);
  dyn_str = (char *) realloc(dyn_str, len);
  dyn_str[(int)(len) - 1] = '\0';

  return dyn_str;
}
