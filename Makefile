# #make para compilar

# all: flex.c bison.c bison.h
# 	gcc bison.c flex.c -lfl -o cafezinho -g

# bison.c bison.h: bison.y
# 	bison -d bison.y -o bison.c

# flex.yy.c: flex.l bison.tab.h
# 	bison flex.l -o flex.c

# clean: rm *.o

# Definições de variáveis
CC = gcc
CFLAGS = -Wall -Wextra -g
LFLAGS = -lfl

FLEX_SOURCE = cafezinho.l
BISON_SOURCE = cafezinho.y
BISON_C = cafezinho.tab.c
BISON_H = cafezinho.tab.h
FLEX_C = lex.yy.c
EXECUTABLE = cafezinho

# Alvo padrão para compilar tudo
all: $(EXECUTABLE)

# Gerar executável
$(EXECUTABLE): $(BISON_C) $(FLEX_C)
	$(CC) $(CFLAGS) $(BISON_C) $(FLEX_C) -o $@ $(LFLAGS)

# Gerar arquivos do Bison
$(BISON_C): $(BISON_SOURCE)
	bison -d $(BISON_SOURCE) -o $(BISON_C)

# Gerar arquivos do Flex
$(FLEX_C): $(FLEX_SOURCE) $(BISON_H)
	flex -o $(FLEX_C) $(FLEX_SOURCE)

# Limpar arquivos gerados
clean:
	rm -f $(BISON_C) $(BISON_H) $(FLEX_C) $(EXECUTABLE)

