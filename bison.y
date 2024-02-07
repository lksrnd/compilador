%{
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
extern int lineNum;
%}

%union{
    int intValue;
    char charValue;
    //VarType varType;
}
%start Programa

%token OU 
%token CADEIADECARACTERES
%token E
%token <intValue> INTCONST
%token <charValue> CARCONST
%token ABRECOLCHETES FECHACOLCHETES ABREPARENTESES FECHAPARENTESES IGUAL DIFERENTE RECEBE MENORIGUAL MAIORIGUAL 
%token MENOR MAIOR VIRGULA ABRECHAVE FECHACHAVE EXCLAMACAO INTERROGACAO DOISPONTOS  RESTO  PONTOVIRGULA
%token MAIS
%token MENOS
%token VEZES
%token DIVIDIDO
%token PROGRAMA
%token ID
%token RETORNE
%token LEIA
%token ESCREVA
%token NOVALINHA
%token SE
%token ENTAO
%token SENAO
%token ENQUANTO
%token EXECUTE
%token <charValue> CAR
%token <intValue> INT 



//%type <varType> Tipo



%%

Programa 
    : DeclFuncVar DeclProg
    ;

DeclFuncVar
    : Tipo ID DeclVar PONTOVIRGULA DeclFuncVar
    | Tipo ID ABRECOLCHETES INTCONST FECHACOLCHETES DeclVar PONTOVIRGULA DeclFuncVar
    | Tipo ID DeclFunc DeclFuncVar
    |
    ;

DeclProg
    : PROGRAMA Bloco
    ;

DeclVar
    : VIRGULA ID DeclVar
    | VIRGULA ID ABRECOLCHETES INTCONST FECHACOLCHETES DeclVar
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
    | Tipo ID ABRECOLCHETES INTCONST FECHACOLCHETES DeclVar PONTOVIRGULA ListaDeclVar
    ;

Tipo
    : INT 
    | CAR 
    ;

ListaComando
    : Comando
    | Comando ListaComando  
    ;

Comando
    :
    PONTOVIRGULA
    | Expr PONTOVIRGULA
    | RETORNE Expr PONTOVIRGULA
    | LEIA LValueExpr PONTOVIRGULA
    | ESCREVA Expr PONTOVIRGULA
    | ESCREVA CADEIADECARACTERES DOISPONTOS
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
    | CARCONST
    | INTCONST
    | ABREPARENTESES Expr FECHAPARENTESES
    ;

ListExpr
    : ID AssignExpr
    | ListExpr VIRGULA AssignExpr
    ;

/* Defina as regras restantes para Comando, Expr, AssignExpr, etc., de forma semelhante */

%%

void yyerror(const char *s) {
    fprintf(stderr, "ERRO: %s\n", s);
}

int main(void) {
    if (yyparse() == 0) {
        printf("Análise sintática concluída com sucesso.\n");
    }
    return 0;
}

