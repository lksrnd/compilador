%{
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
extern char * yytext;
extern int yylex();
extern FILE* yyin;
extern int lineNum;
extern int tipoErro;
%}

%union{
    int intValue;
    char charValue;
    char* cadeiaValue;
}
%start Programa

%token ABRECOLCHETES FECHACOLCHETES ABREPARENTESES FECHAPARENTESES IGUAL DIFERENTE RECEBE
%token MENORIGUAL MAIORIGUAL MENOR MAIOR VIRGULA ABRECHAVE FECHACHAVE EXCLAMACAO INTERROGACAO
%token DOISPONTOS VEZES RESTO DIVIDIDO MENOS MAIS PONTOVIRGULA PROGRAMA CAR INT RETORNE LEIA
%token ESCREVA NOVALINHA SE ENTAO SENAO ENQUANTO EXECUTE E OU CONSTINT CONSTCAR CADEIACARACTERES
%token ID
%verbose

%%

Programa
    : DeclFuncVar DeclProg
    ;

DeclFuncVar
    : Tipo ID DeclVar PONTOVIRGULA DeclFuncVar
    | Tipo ID ABRECOLCHETES CONSTINT FECHACOLCHETES DeclVar PONTOVIRGULA DeclFuncVar
    | Tipo ID DeclFunc DeclFuncVar
    |
    ;

DeclProg
    : PROGRAMA Bloco
    ;

DeclVar
    : VIRGULA ID DeclVar
    | VIRGULA ID ABRECOLCHETES CONSTINT FECHACOLCHETES DeclVar
    |
    ;

DeclFunc
    : ABREPARENTESES ListaParametros FECHAPARENTESES Bloco
    ;

ListaParametros
    :
    | ListaParametrosCont
    ;

ListaParametrosCont
    : Tipo ID
    | Tipo ID ABRECOLCHETES FECHACOLCHETES
    | Tipo ID VIRGULA ListaParametrosCont
    | Tipo ID ABRECOLCHETES FECHACOLCHETES VIRGULA ListaParametrosCont
    ;

Bloco
    : ABRECHAVE ListaDeclVar ListaComando FECHACHAVE
    | ABRECHAVE ListaDeclVar FECHACHAVE
    ;

ListaDeclVar
    :
    | Tipo ID DeclVar PONTOVIRGULA ListaDeclVar
    | Tipo ID ABRECOLCHETES CONSTINT FECHACOLCHETES DeclVar PONTOVIRGULA ListaDeclVar
    ;

Tipo
    : INT 
    | CAR 
    ;

ListaComando
    : Comando
    | Comando ListaComando  
    ;

Comando : PONTOVIRGULA
    | Expr PONTOVIRGULA
    | RETORNE Expr PONTOVIRGULA
    | LEIA LValueExpr PONTOVIRGULA
    | ESCREVA Expr PONTOVIRGULA
    | ESCREVA CADEIACARACTERES PONTOVIRGULA
    | NOVALINHA PONTOVIRGULA
    | SE ABREPARENTESES Expr FECHAPARENTESES ENTAO Comando
    | SE ABREPARENTESES Expr FECHAPARENTESES ENTAO Comando SENAO Comando
    | ENQUANTO ABREPARENTESES Expr FECHAPARENTESES EXECUTE Comando
    | Bloco
    ;

Expr
    : AssignExpr
    ;

AssignExpr
    : CondExpr
    | LValueExpr IGUAL AssignExpr
    ;

CondExpr
    : OrExpr
    | OrExpr INTERROGACAO Expr DOISPONTOS CondExpr
    ;

OrExpr
    : OrExpr OU AndExpr
    | AndExpr
    ;

AndExpr
    : AndExpr E EqExpr
    | EqExpr
    ;

EqExpr
    : EqExpr RECEBE DesigExpr
    | EqExpr DIFERENTE DesigExpr
    | DesigExpr
    ;

DesigExpr
    : DesigExpr MENOR AddExpr
    | DesigExpr MAIOR AddExpr
    | DesigExpr MAIORIGUAL AddExpr
    | DesigExpr MENORIGUAL AddExpr
    | AddExpr
    ;
AddExpr
    : AddExpr MAIS MulExpr
    | AddExpr MENOS MulExpr
    | MulExpr
    ;

MulExpr
    : MulExpr VEZES UnExpr
    | MulExpr DIVIDIDO UnExpr
    | MulExpr RESTO UnExpr
    | UnExpr
    ;

UnExpr
    : MENOS PrimExpr
    | EXCLAMACAO PrimExpr
    | PrimExpr
    ;

LValueExpr
    : ID ABRECOLCHETES Expr FECHACOLCHETES
    | ID
    ;

PrimExpr
    : ID ABREPARENTESES ListExpr FECHAPARENTESES
    | ID ABREPARENTESES FECHAPARENTESES
    | ID ABRECOLCHETES Expr FECHACOLCHETES
    | ID
    | CONSTCAR
    | CONSTINT
    | ABREPARENTESES Expr FECHAPARENTESES
    ;

ListExpr
    : AssignExpr
    | ListExpr VIRGULA AssignExpr
    ;

%%

void yyerror(char const * s) {
        if(tipoErro==0)
    {
        printf("%s NA LINHA %d - token: %s\n", s, lineNum, yytext);
    }
    else
    {
        printf("Erro sintatico proximo a %s ", yytext);
        printf(" - linha: %d \n", lineNum);
        tipoErro=1;
    }
    exit(1);

}

int main(int argc, char** argv){
   if(argc!=2)
        yyerror("Uso correto: ./cafezinho nome_arq_entrada.txt");
   yyin=fopen(argv[1], "r");
   if(!yyin)
        yyerror("arquivo não pode ser aberto\n");
    if (yyparse() == 0) {
        printf("Análise sintática concluída com sucesso.\n");
    }

}