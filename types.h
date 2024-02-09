#ifndef types_h
#define types_h

#include <stdlib.h>

typedef enum{
   Programa,
   DeclFunc,
   DeclFuncVar,
   DeclFuncVar1,
   DeclFuncVar2,
   DeclFuncVar3,
   Se, 
   And,
   Ou,
   Enquanto, 
   Do, 
   Num, 
   Escreva,
   lstStmt,
   Atribuir,
   Identificador,
   Bloco,
   ListaComando,
   IdentificadorCEC,
   IdentificadorL,
   Negacao,
   Oposto,
   Divisao,
   Resto,
   Mais,
   Menos, 
   Mult, 
   Menor,
   Maior, 
   Igual, 
   MenorIgual,
   MaiorIgual,
   IgualIgual,
   Diferente,
   SeTernario,
   SeSenao,
   NovaLinha,
   EscrevaC,
   Leia,
   Retorne,
   Tipo,
   VetorDeclVar,
   ListaDeclVar,
   ListaParametrosCont2,
   ListaParametrosCont3,
   Virgula,
   ConstCar,
   ConstInt
   }TypeOperators;

typedef struct operador{
    TypeOperators typeOperator;
    int  line;
    char* Tlexema;
    struct operador* t1;
    struct operador* t2;
    struct operador* t3;
} TOperador;

#endif
