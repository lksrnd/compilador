%{
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "cafezinho.tab.h"
#include "types.h"

int lineNum = 0;
char msg[1024];
extern void yyerror(const char *s);
int tipoErro = 1; // tipoErro = 0 é lexico - tipoErro = 1 é sintatico

%}

CHAR    [A-Za-z] 
DIGIT   [0-9]  
ID      [a-zA-Z_][a-zA-Z0-9_]*
ESPACO_VAZIO [ \t\r]
INTCONST [0-9]+
CARCONST [A-Za-z_0-9]+
CADEIADECARACTERES   \"(\\.|[^\\"])*\"
%x COMENTARIO
%option yylineno

%%

"/*"		    BEGIN(COMENTARIO);
<COMENTARIO>[^*\n]*  
<COMENTARIO>"*"+[^/\n]  
<COMENTARIO><<EOF>> {
                    strcpy(msg,"ERRO: COMENTÁRIO NÃO TERMINA");
		    tipoErro = 0;
		    yyerror(msg);
                  }
<COMENTARIO>\n lineNum++;    
<COMENTARIO>"*"+"/"    BEGIN(INITIAL);

"["         {printf("Simbolo: %s\n", yytext);return (ABRECOLCHETES); }

"]"         {printf("Simbolo: %s\n", yytext); return (FECHACOLCHETES);  }

"("         {printf("Simbolo: %s\n", yytext); return (ABREPARENTESES);  }

")"         {printf("Simbolo: %s\n", yytext); return (FECHAPARENTESES);  }

"="         {printf("Simbolo: %s\n", yytext); return (IGUAL);  }

"!="        {printf("Simbolo: %s\n", yytext); return (DIFERENTE);  }

"=="        {printf("Simbolo: %s\n", yytext); return (RECEBE);  }

"<="        {printf("Simbolo: %s\n", yytext); return (MENORIGUAL);  }

">="        {printf("Simbolo: %s\n", yytext); return (MAIORIGUAL);  }

"<"         {printf("Simbolo: %s\n", yytext); return (MENOR); }

">"         {printf("Simbolo: %s\n", yytext); return (MAIOR);  }

","         {printf("Simbolo: %s\n", yytext); return (VIRGULA);  }

"{"         {printf("Simbolo: %s\n", yytext); return (ABRECHAVE);  }

"}"         {printf("Simbolo: %s\n", yytext); return (FECHACHAVE); }

"!"         {printf("Simbolo: %s\n", yytext); return (EXCLAMACAO); }

"?"         {printf("Simbolo: %s\n", yytext); return (INTERROGACAO); }

":"         {printf("Simbolo: %s\n", yytext); return (DOISPONTOS);  }

"*"         {printf("Simbolo: %s\n", yytext); return (VEZES);  }

"%"         {printf("Simbolo: %s\n", yytext); return (RESTO);  }

"/"         {printf("Simbolo: %s\n", yytext); return (DIVIDIDO); }

"-"         {printf("Simbolo: %s\n", yytext); return (MENOS);  }

"+"         {printf("Simbolo: %s\n", yytext); return (MAIS);  }

";"         {printf("Simbolo: %s\n", yytext); return (PONTOVIRGULA);  }

"programa"  {printf("Palavra reservada: %s\n", yytext); return (PROGRAMA);  }

"car"       {printf("Palavra reservada: %s\n", yytext); return (CAR); }

"int"       {printf("Palavra reservada: %s\n", yytext); return (INT);  }

"retorne"   {printf("Palavra reservada: %s\n", yytext); return (RETORNE);  }

"leia"      {printf("Palavra reservada: %s\n", yytext); return (LEIA);  }

"escreva"   {printf("Palavra reservada: %s\n", yytext); return (ESCREVA);  }

"novalinha" {printf("Palavra reservada: %s\n", yytext); return (NOVALINHA); }

"se"        {printf("Palavra reservada: %s\n", yytext); return (SE);  }

"entao"     {printf("Palavra reservada: %s\n", yytext); return (ENTAO);  }

"senao"     {printf("Palavra reservada: %s\n", yytext); return (SENAO); }

"enquanto"  {printf("Palavra reservada: %s\n", yytext); return (ENQUANTO); }

"execute"   {printf("Palavra reservada: %s\n", yytext); return (EXECUTE);  }

"e"         {printf("Palavra reservada: %s\n", yytext); return (ABRECOLCHETES);  }

"ou"        {printf("Palavra reservada: %s\n", yytext); return (OU);  }

{ID} {printf("Identificador: %s\n", yytext); return (ID);}

{INTCONST} {printf("Constante inteiro: %s\n", yytext);return CONSTINT; }

{CARCONST} {printf("Constante Caractere: %s\n", yytext);return (CONSTCAR); } 

{CADEIADECARACTERES} {printf("Cadeia caractere: %s\n", yytext);return (CADEIACARACTERES);} 

{ESPACO_VAZIO}  {lineNum++;} //CONTAGEM DE LINHAS

{CHAR}({CHAR}|{DIGIT})*(\r|\n|\r\n){CHAR}({CHAR}|{DIGIT})* {
    strcpy(msg,"ERRO: Palavra não termina");
    tipoErro = 0;
    yyerror(msg);
}

.   {strcpy(msg,"ERRO: CARACTERE INVÁLIDO");
		tipoErro = 0;
		yyerror(msg);
    }



%%

int yywrap() {
    return 1;
}
