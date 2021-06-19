##### Variáveis #####
# Compilador
CC=gcc

# Flags
CFLAGS=-W -Wall

# Executável
EXEC=exec

# Nome do executavel
PROJ_NAME=exec

# Arquivos source, i.e. extensão .c
C_SRC=$(wildcard *.c)

# Arquivos objeto, i.e. extensão .o
OBJ=$(C_SRC:.c=.o)

# Diretório de objetos
OBJDIR=obj

##### Regras e dependências #####
$(PROJ_NAME): $(OBJ)
	$(CC) -o $(PROJ_NAME) $(OBJ) $(CFLAGS) -lm
	@echo "\nCompilação finalizada!\nDigite 'make run' e tecle <enter> para executar a aplicacao"

main.o: main.c utils.h parser.h stack.h table.h
	$(CC) -c main.c $(CFLAGS)

utils.o: utils.h
	$(CC) -c utils.c $(CFLAGS)

parser.o: parser.h lexical_analyser.h token.h
	$(CC) -c parser.c $(CFLAGS)

token.o: token.h
	$(CC) -c token.c $(CFLAGS)

lexical_analyser.o: lexical_analyser.h token.h
	$(CC) -c lexical_analyser.c $(CFLAGS)

stack.o: stack.h
	$(CC) -c stack.c $(CFLAGS)

table.o: table.h utils.h
	$(CC) -c table.c $(CFLAGS)

# Executar
run:
	./$(EXEC)

# Limpar de arquivos
clean:
	rm -rf *.o

# Apagar tudo o que deve ser modificado
mrproper:
	rm -rf $(EXEC)
