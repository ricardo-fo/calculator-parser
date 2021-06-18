#ifndef PARSER_H
#define PARSER_H

struct valor_pilha
{
    int estado;
    char acao;
};

struct valor_pilha valorPilha;

// Insere o indicador de fim de sentença
void insert_end_sentence(char *);

// Realiza a análise léxica
void lexical_analysis(const char *);

// Realiza a análise sintática
void syntatic_analysis(const char *);

char ** extract_tokens(const char *);

#endif
