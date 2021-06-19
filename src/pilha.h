/**
 * pilha.h
 * Defini��o do TAD pilha e prot�tipo de suas opera��es
 * Ciro C. Trindade
 * 19/02/2019
 */

#ifndef _PILHA_H // previne que o arquivo seja inclu�do mais de uma vez
#define _PILHA_H // na mesma aplica��o

#define STACK_MAX 100 // n�mero m�ximo de elementos da pilha
#include <stdbool.h> // define o tipo de dado bool (para valores l�gicos)

typedef int stack_info; // tipo de dado da pilha
typedef struct {
    stack_info itens[STACK_MAX]; // vetor que armazena os elementos da pilha
    int topo; // �ndice para o elemento do topo da pilha
} pilha;

/* fun��o que inicializa a pilha no estado vazio */
void stack_init(pilha *);

/* fun��o que verifica se a pilha est� vazia */
bool stack_isempty(pilha);

/* fun��o que verifica se a pilha est� cheia */
bool stack_isfull(pilha);

/* fun��o que empilha um novo n� no topo da pilha */
void push(pilha *, stack_info);

/* fun��o que empilha um novo n� no topo da pilha e sinaliza
 * o sucesso ou falha da opera��o */
bool push_and_test(pilha *, stack_info);

/* fun��o que desempilha o n� do topo da pilha e devolve seu valor */
stack_info pop(pilha *);

/* fun��o que desempilha o n� do topo da pilha, devolve seu valor
 * atrav�s de um par�metro e sinaliza seu sucesso ou falha */
bool pop_and_test(pilha *, stack_info *);

/* fun��o que devolve o valor do n� que est� no topo da pilha */
stack_info top(pilha);

/* fun��o que devolve o valor do n� que est� no topo da pilha atrav�s
 * de um par�metro e sinaliza o sucesso ou falha da opera��o */
bool top_and_test(pilha, stack_info *);

#endif
