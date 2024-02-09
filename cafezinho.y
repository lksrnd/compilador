%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

extern char * yytext;
extern int yylex();
extern FILE* yyin;
extern int lineNum;
extern int tipoErro;
void yyerror(const char *s);

TOperador* CriaNo(TypeOperators typeOperator,  int line, TOperador* t1, TOperador* t2, char* Tlexema);
TOperador* CriaNoTernario(TypeOperators typeOperator,  int line, TOperador* t1, TOperador* t2,TOperador* t3, char* Tlexema);
void walkTree(TOperador* raiz);
void printOperator(TOperador* no, char* nomeOperador);

TOperador* raiz;
char nomeOperador[200];

%}

%union{
    int line;
    char* Tlexema;
    TOperador* Tpont;
}
%start Programa

%token ABRECOLCHETES FECHACOLCHETES ABREPARENTESES FECHAPARENTESES IGUAL DIFERENTE RECEBE
%token MENORIGUAL MAIORIGUAL MENOR MAIOR VIRGULA ABRECHAVE FECHACHAVE EXCLAMACAO INTERROGACAO
%token DOISPONTOS VEZES RESTO DIVIDIDO MENOS MAIS PONTOVIRGULA PROGRAMA CAR INT RETORNE LEIA
%token ESCREVA NOVALINHA SE ENTAO SENAO ENQUANTO EXECUTE E OU   
%type<Tpont> DeclFuncVar DeclProg DeclVar DeclFunc ListaParametros 
%type<Tpont> ListaParametrosCont Bloco ListaDeclVar Tipo ListaComando 
%type<Tpont> Comando Expr AssignExpr CondExpr OrExpr AndExpr EqExpr 
%type<Tpont> DesigExpr AddExpr MulExpr UnExpr LValueExpr PrimExpr ListExpr
%token<Tlexema> ID CONSTCAR CONSTINT CADEIACARACTERES
%%

Programa
    : DeclFuncVar DeclProg { raiz = CriaNo(Programa, lineNum, $1, $2, NULL); }
    ;

DeclFuncVar
    : Tipo ID DeclVar PONTOVIRGULA DeclFuncVar { $$ = CriaNoTernario(DeclFuncVar1, lineNum, $1, $3, $5, NULL); }
    | Tipo ID ABRECOLCHETES CONSTINT FECHACOLCHETES DeclVar PONTOVIRGULA DeclFuncVar { $$ = CriaNoTernario(DeclFuncVar1, lineNum, $1, $6, $8, NULL); } 
    | Tipo ID DeclFunc DeclFuncVar { $$ = CriaNoTernario(DeclFuncVar2, lineNum, $1, $3, $4, NULL); }
    |   {$$=NULL;}
    ;

DeclProg    
    : PROGRAMA Bloco { $$ = $2; }
    ;

DeclVar
    : VIRGULA ID DeclVar    { $$ = $3; }
    | VIRGULA ID ABRECOLCHETES CONSTINT FECHACOLCHETES DeclVar  { $$ = $6; }
    |   { $$=NULL; }
    ;

DeclFunc
    : ABREPARENTESES ListaParametros FECHAPARENTESES Bloco  { $$ = CriaNo(DeclFunc , lineNum, $2, $4, NULL); }
    ;

ListaParametros
    : { $$=NULL; }
    | ListaParametrosCont { $$=$1; }
    ;

ListaParametrosCont
    : Tipo ID { $$=$1; }
    | Tipo ID ABRECOLCHETES FECHACOLCHETES { $$=$1; }
    | Tipo ID VIRGULA ListaParametrosCont { $$ = CriaNo(ListaParametrosCont2, lineNum, $1, $4, NULL); }
    | Tipo ID ABRECOLCHETES FECHACOLCHETES VIRGULA ListaParametrosCont { $$ = CriaNo(ListaParametrosCont3, lineNum, $1, $6, NULL); }
    ;

Bloco
    : ABRECHAVE ListaDeclVar ListaComando FECHACHAVE { $$ = CriaNo(Bloco, lineNum, $2, $3, NULL); }
    | ABRECHAVE ListaDeclVar FECHACHAVE { $$=$2; }
    ;

ListaDeclVar
    :   { $$=NULL; }
    | Tipo ID DeclVar PONTOVIRGULA ListaDeclVar { $$ = CriaNoTernario(ListaDeclVar, lineNum, $1, $3, $5, NULL); }
    | Tipo ID ABRECOLCHETES CONSTINT FECHACOLCHETES DeclVar PONTOVIRGULA ListaDeclVar { $$ = CriaNoTernario(VetorDeclVar, lineNum, $1, $6, $8, NULL); }
    ;

Tipo
    : INT { $$ = CriaNo(Tipo, lineNum, NULL, NULL, "int"); }
    | CAR { $$ = CriaNo(Tipo, lineNum, NULL, NULL, "car"); }
    ;

ListaComando
    : Comando { $$ = $1; }
    | Comando ListaComando { $$ = CriaNo(ListaComando, lineNum, $1, $2, NULL); }
    ;

Comando 
    : PONTOVIRGULA { $$=NULL; }
    | Expr PONTOVIRGULA { $$=$1; }
    | RETORNE Expr PONTOVIRGULA { $$ = CriaNo(Retorne, lineNum, $2, NULL, NULL); }
    | LEIA LValueExpr PONTOVIRGULA { $$ = CriaNo(Leia, lineNum, $2, NULL, NULL); }
    | ESCREVA Expr PONTOVIRGULA { $$ = CriaNo(Escreva, lineNum, $2, NULL, NULL); }
    | ESCREVA CADEIACARACTERES PONTOVIRGULA { $$ = CriaNo(EscrevaC, lineNum, NULL, NULL, NULL); }
    | NOVALINHA PONTOVIRGULA { $$ = CriaNo(NovaLinha, lineNum, NULL, NULL, NULL); }
    | SE ABREPARENTESES Expr FECHAPARENTESES ENTAO Comando {{ $$ = CriaNo(Se, lineNum, $3, $6, NULL); }}
    | SE ABREPARENTESES Expr FECHAPARENTESES ENTAO Comando SENAO Comando { $$ = CriaNoTernario(SeSenao, lineNum, $3, $6, $8, NULL); }
    | ENQUANTO ABREPARENTESES Expr FECHAPARENTESES EXECUTE Comando { $$ = CriaNo(Enquanto, lineNum, $3, $6, NULL); }
    | Bloco { $$=$1; }
    ;

Expr
    : AssignExpr { $$=$1; }
    ;

AssignExpr
    : CondExpr { $$=$1; }
    | LValueExpr IGUAL AssignExpr { $$ = CriaNo(Atribuir, lineNum, $1, $3, NULL); }
    ;

CondExpr
    : OrExpr { $$=$1; }
    | OrExpr INTERROGACAO Expr DOISPONTOS CondExpr { $$ = CriaNoTernario(SeTernario, lineNum, $1, $3, $5, NULL); }
    ;

OrExpr
    : OrExpr OU AndExpr { $$ = CriaNo(Ou, lineNum, $1, $3, NULL); }
    | AndExpr { $$=$1; }
    ;

AndExpr
    : AndExpr E EqExpr { $$ = CriaNo(And, lineNum, $1, $3, NULL); }
    | EqExpr { $$=$1; }
    ;

EqExpr
    : EqExpr RECEBE DesigExpr { $$ = CriaNo(IgualIgual, lineNum, $1, $3, NULL); }
    | EqExpr DIFERENTE DesigExpr { $$ = CriaNo(Diferente, lineNum, $1, $3, NULL); }
    | DesigExpr {   $$=$1; }
    ;

DesigExpr
    : DesigExpr MENOR AddExpr { $$ = CriaNo(Menor, lineNum, $1, $3, NULL); }
    | DesigExpr MAIOR AddExpr { $$ = CriaNo(Maior, lineNum, $1, $3, NULL); }
    | DesigExpr MAIORIGUAL AddExpr { $$ = CriaNo(MaiorIgual, lineNum, $1, $3, NULL); }
    | DesigExpr MENORIGUAL AddExpr { $$ = CriaNo(MenorIgual, lineNum, $1, $3, NULL); }
    | AddExpr { $$=$1; } 
    ;
AddExpr
    : AddExpr MAIS MulExpr { $$ = CriaNo(Mais, lineNum, $1, $3, NULL); }
    | AddExpr MENOS MulExpr { $$ = CriaNo(Menos, lineNum, $1, $3, NULL); }
    | MulExpr { $$=$1; }
    ;

MulExpr
    : MulExpr VEZES UnExpr { $$ = CriaNo(Mult, lineNum, $1, $3, NULL); }
    | MulExpr DIVIDIDO UnExpr { $$ = CriaNo(Divisao, lineNum, $1, $3, NULL); }
    | MulExpr RESTO UnExpr { $$ = CriaNo(Resto, lineNum, $1, $3, NULL); }
    | UnExpr { $$=$1; }
    ;

UnExpr
    : MENOS PrimExpr { $$ = CriaNo(Oposto, lineNum, $2, NULL, NULL); }
    | EXCLAMACAO PrimExpr { $$ = CriaNo(Negacao, lineNum, $2, NULL, NULL); }
    | PrimExpr { $$=$1; }
    ;

LValueExpr
    : ID ABRECOLCHETES Expr FECHACOLCHETES { $$ = CriaNo(IdentificadorCEC, lineNum, $3, NULL, NULL); }
    | ID { $$ = CriaNo(Identificador, lineNum, NULL, NULL, NULL); }
    ;

PrimExpr
    : ID ABREPARENTESES ListExpr FECHAPARENTESES { $$ = CriaNo(IdentificadorL, lineNum, $3, NULL, NULL); }
    | ID ABREPARENTESES FECHAPARENTESES { $$ = CriaNo(Identificador, lineNum, NULL, NULL, NULL); }
    | ID ABRECOLCHETES Expr FECHACOLCHETES { $$ = CriaNo(IdentificadorCEC, lineNum, $3, NULL, NULL); }
    | ID { $$ = CriaNo(Identificador, lineNum, NULL, NULL, yytext); }
    | CONSTCAR { $$ = CriaNo(ConstCar, lineNum, NULL, NULL, yytext); }
    | CONSTINT { $$ = CriaNo(ConstInt, lineNum, NULL, NULL, yytext); }
    | ABREPARENTESES Expr FECHAPARENTESES { $$=$2; }
    ;

ListExpr
    : AssignExpr { $$=$1; }
    | ListExpr VIRGULA AssignExpr { $$ = CriaNo(Virgula, lineNum, $1, $3, yytext); }
    ;

%%

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

void walkTree(TOperador* raiz){
    if(raiz){
        printOperator(raiz, nomeOperador);
        printf("%s", nomeOperador);
            printf("filho 1\n");
        walkTree(raiz->t1);
            printf("end filho 1 \nfilho 2\n");
        walkTree(raiz->t2);
            printf("end filho 2\n");
        walkTree(raiz->t3);
        }
}
TOperador* CriaNo(TypeOperators typeOperator, int line, TOperador* t1, TOperador* t2, char* Tlexema){
    
    TOperador* aux = (TOperador*) malloc(sizeof(TOperador));
    if (aux){
        //printf("entrei aqui\n");
        aux->typeOperator=typeOperator;
        aux->line=line;
        aux->t1=t1;
        aux->t2=t2;
        aux->t3=NULL;
        if(Tlexema){
            aux->Tlexema= (char*)malloc(strlen(Tlexema)+1);
            strcpy(aux->Tlexema, Tlexema);
        }
        return(aux);
    }
    return(NULL);
}
TOperador* CriaNoTernario(TypeOperators typeOperator, int line, TOperador* t1, TOperador* t2,TOperador* t3, char* Tlexema){
    
    TOperador* aux = (TOperador*) malloc(sizeof(TOperador));
    if (aux){
        //printf("entrei aqui\n");
        aux->typeOperator=typeOperator;
        aux->line=line;
        aux->t1=t1;
        aux->t2=t2;
        aux->t3=t3;
        if(Tlexema){
            aux->Tlexema= (char*)malloc(strlen(Tlexema)+1);
            strcpy(aux->Tlexema, Tlexema);
        }
        return(aux);
    }
    return(NULL);
}
void printOperator(TOperador* no, char* nomeOperador){
    switch(no->typeOperator){
        case Programa:
        strcpy(nomeOperador,"programa\n");
        break;
        case DeclFunc:
        sprintf(nomeOperador, "DeclFunc - LINHA: %d\n",no->line);
        break;
        case DeclFuncVar1:
        sprintf(nomeOperador, "DeclFuncVar1 - LINHA: %d\n",no->line);
        break;
        case DeclFuncVar2:
        sprintf(nomeOperador, "DeclFuncVar2 - LINHA: %d\n",no->line);
        break;
        case DeclFuncVar3:
        sprintf(nomeOperador, "DeclFuncVar3 - LINHA: %d\n",no->line);
        break;
        case Num:
        sprintf(nomeOperador, "%s NUM- LINHA: %d\n", no->Tlexema,no->line);
        break;
        case Mais:
        sprintf(nomeOperador, "+ - LINHA: %d\n", no->line);
        break;
        case Menos:
        sprintf(nomeOperador, "- - LINHA: %d\n", no->line);
        break;
        case Mult:
        sprintf(nomeOperador, "* - LINHA: %d\n", no->line);
        break;
        case Divisao:
        sprintf(nomeOperador, "/ - LINHA: %d\n", no->line);
        break;
        case Resto:
        sprintf(nomeOperador, "%% - LINHA: %d\n", no->line);
        break;
        case Menor:
        sprintf(nomeOperador, "< - LINHA: %d\n", no->line);
        break;
        case Maior:
        sprintf(nomeOperador, "> - LINHA: %d\n", no->line);
        break;
        case Igual:
        sprintf(nomeOperador, "== - LINHA: %d\n", no->line);
        break;
        case MenorIgual:
        sprintf(nomeOperador, "<= - LINHA: %d\n", no->line);
        break;
        case MaiorIgual:
        sprintf(nomeOperador, ">= - LINHA: %d\n", no->line);
        break;
        case Se:
        sprintf(nomeOperador, "Se - LINHA: %d\n", no->line);
        break;
        case Enquanto :
        sprintf(nomeOperador, "Enquanto - LINHA: %d\n", no->line);
        break;
        case Do:
        sprintf(nomeOperador, "Do - LINHA: %d\n", no->line);
        break;
        case Identificador:
        sprintf(nomeOperador, "ID - LINHA: %d\n", no->line);
        break;
        case Atribuir:
        sprintf(nomeOperador, "= - LINHA: %d\n", no->line);
        break;
        case DeclFuncVar:
        sprintf(nomeOperador, "DeclFuncVar - LINHA: %d\n", no->line);
        break;
        case Escreva:
        sprintf(nomeOperador, "Escreva Expr - LINHA: %d\n", no->line);
        break;
        case EscrevaC:
        sprintf(nomeOperador, "Escreva Cadeia - LINHA: %d\n", no->line);
        break;
        case lstStmt:
        sprintf(nomeOperador, "Faze de Teste - LINHA: %d\n", no->line);
        break;
        case Bloco:
        sprintf(nomeOperador, "Bloco - LINHA: %d\n", no->line);
        break;
        case ListaComando:
        sprintf(nomeOperador, "ListaComando - LINHA: %d\n", no->line);
        break;
        case VetorDeclVar:
        sprintf(nomeOperador, "VetorDeclVar - LINHA: %d\n",no->line);
        break;
        case ListaDeclVar:
        sprintf(nomeOperador, "ListaDeclVar - LINHA: %d\n",no->line);
        break;
        case ListaParametrosCont2:
        sprintf(nomeOperador, "Tipo ID VIRGULA  ListaParametrosCont - LINHA: %d\n",no->line);
        break;
        case ListaParametrosCont3:
        sprintf(nomeOperador, "Tipo ID COLCH_E  COLCH_D VIRGULA ListaParametrosCont - LINHA: %d\n",no->line);
        break;
        case Negacao:
        sprintf(nomeOperador, "! - LINHA: %d\n", no->line);
        break;
        case Oposto:
        sprintf(nomeOperador, "- Unario - LINHA: %d\n", no->line);
        break;
        case Virgula:
        sprintf(nomeOperador, ", - LINHA: %d\n",no->line);
        break;
        case IgualIgual:
        sprintf(nomeOperador, "== - LINHA: %d\n", no->line);
        break;
        case Diferente:
        sprintf(nomeOperador, "!= - LINHA: %d\n", no->line);
        break;
        case And:
        sprintf(nomeOperador, "E - LINHA: %d\n", no->line);
        break;
        case Ou:
        sprintf(nomeOperador, "Ou - LINHA: %d\n", no->line);
        break;
        case SeTernario:
        sprintf(nomeOperador, "E ? E : E - LINHA: %d\n", no->line);
        break;
        case SeSenao:
        sprintf(nomeOperador, "SeSenao - LINHA: %d\n", no->line);
        break;
        case NovaLinha:
        sprintf(nomeOperador, "NovaLinha  - LINHA: %d\n", no->line);
        break;
        case IdentificadorCEC:
        sprintf(nomeOperador, "ID[Expr] - LINHA: %d\n", no->line);
        break;
        case IdentificadorL:
        sprintf(nomeOperador, "ID(ListExpr) - LINHA: %d\n", no->line);
        break;
        case Leia:
        sprintf(nomeOperador, "Leia  - LINHA: %d\n", no->line);
        break;
        case Retorne:
        sprintf(nomeOperador, "Retorne  - LINHA: %d\n", no->line);
        break;
        case Tipo:
        sprintf(nomeOperador, "Tipo %s  - LINHA: %d\n",no->Tlexema, no->line);
        break;
        case ConstCar:
        sprintf(nomeOperador, "%s ConstCar- LINHA: %d\n", no->Tlexema,no->line);
        break;
        case ConstInt:
        sprintf(nomeOperador, "%s ConstInt- LINHA: %d\n", no->Tlexema,no->line);
        break;
    }
}