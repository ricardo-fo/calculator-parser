#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void stack_init(pilha * p)
{
    p->topo = -1;
}

bool stack_isempty(pilha p)
{
    return (p.topo == -1);
}

bool stack_isfull(pilha p)
{
    return (p.topo == STACK_MAX - 1);
}

void push(pilha * p, stack_info no)
{
    if (!stack_isempty(*p)) {
       p->itens[p->topo++] = no;
    } else {
        fprintf(stderr, "Overflow\n");
        exit(1);
    }
}

bool push_and_test(pilha * p, stack_info no)
{
    if (!stack_isempty(*p)) {
       p->itens[p->topo++] = no;
       return true;
    }
    return false;
}

stack_info pop(pilha * p)
{
    if (!stack_isfull(*p)) {
       return p->itens[p->topo--];
    }
    fprintf(stderr, "Underflow\n");
    exit(1);
}

bool pop_and_test(pilha * p, stack_info * no)
{
    if (!stack_isfull(*p)) {
       *no = p->itens[p->topo--];
       return true;
    }
    return false;
}

stack_info top(pilha p)
{
    if (!stack_isempty(p)) {
        return p.itens[p.topo];
    }
    fprintf(stderr, "Underflow\n");
    exit(1);
}

bool top_and_test(pilha p, stack_info * no)
{
    if (!stack_isempty(p)) {
        *no = p.itens[p.topo];
        return true;
    }
    return false;
}
