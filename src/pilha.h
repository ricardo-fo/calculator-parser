/**
 * pilha.h
 * Definição do TAD pilha e protótipo de suas operações
 * Ciro C. Trindade
 * 19/02/2019
 */

#ifndef _PILHA_H // previne que o arquivo seja incluído mais de uma vez
#define _PILHA_H // na mesma aplicação

#define STACK_MAX 100 // número máximo de elementos da pilha
#include <stdbool.h> // define o tipo de dado bool (para valores lógicos)

typedef int stack_info; // tipo de dado da pilha
typedef struct {
    stack_info itens[STACK_MAX]; // vetor que armazena os elementos da pilha
    int topo; // índice para o elemento do topo da pilha
} pilha;

/* função que inicializa a pilha no estado vazio */
void stack_init(pilha *);

/* função que verifica se a pilha está vazia */
bool stack_isempty(pilha);

/* função que verifica se a pilha está cheia */
bool stack_isfull(pilha);

/* função que empilha um novo nó no topo da pilha */
void push(pilha *, stack_info);

/* função que empilha um novo nó no topo da pilha e sinaliza
 * o sucesso ou falha da operação */
bool push_and_test(pilha *, stack_info);

/* função que desempilha o nó do topo da pilha e devolve seu valor */
stack_info pop(pilha *);

/* função que desempilha o nó do topo da pilha, devolve seu valor
 * através de um parâmetro e sinaliza seu sucesso ou falha */
bool pop_and_test(pilha *, stack_info *);

/* função que devolve o valor do nó que está no topo da pilha */
stack_info top(pilha);

/* função que devolve o valor do nó que está no topo da pilha através
 * de um parâmetro e sinaliza o sucesso ou falha da operação */
bool top_and_test(pilha, stack_info *);

#endif
