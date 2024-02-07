# #make para compilar

# all: flex.c bison.c bison.h
# 	gcc bison.c flex.c -lfl -o cafezinho -g

# bison.c bison.h: bison.y
# 	bison -d bison.y -o bison.c

# flex.yy.c: flex.l bison.tab.h
# 	bison flex.l -o flex.c

# clean: rm *.o

# Definir o compilador C
CC=gcc

# Definir as flags de compilação
CFLAGS=-Wall -g -lfl

# Nome do programa final
PROGRAM=cafezinho

# Alvo padrão para compilar tudo
all: $(PROGRAM)

# Dependências do Bison - Gera o analisador sintático
cafezinho.tab.c cafezinho.tab.h: bison.y
	bison -d bison.y -o cafezinho.tab.c

# Dependências do Flex - Gera o analisador léxico
lex.yy.c: flex.l cafezinho.tab.h
	flex flex.l

# Compila o programa final
$(PROGRAM): lex.yy.c cafezinho.tab.c cafezinho.tab.h
	$(CC) $(CFLAGS) lex.yy.c cafezinho.tab.c -o $(PROGRAM)

# Limpar arquivos gerados
clean:
	rm -f lex.yy.c cafezinho.tab.c cafezinho.tab.h $(PROGRAM)

# Alvo falso para evitar conflitos com arquivos de mesmo nome
.PHONY: all clean
