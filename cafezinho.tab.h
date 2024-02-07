/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_CAFEZINHO_TAB_H_INCLUDED
# define YY_YY_CAFEZINHO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OU = 258,
    CADEIADECARACTERES = 259,
    E = 260,
    INTCONST = 261,
    CARCONST = 262,
    ABRECOLCHETES = 263,
    FECHACOLCHETES = 264,
    ABREPARENTESES = 265,
    FECHAPARENTESES = 266,
    IGUAL = 267,
    DIFERENTE = 268,
    RECEBE = 269,
    MENORIGUAL = 270,
    MAIORIGUAL = 271,
    MENOR = 272,
    MAIOR = 273,
    VIRGULA = 274,
    ABRECHAVE = 275,
    FECHACHAVE = 276,
    EXCLAMACAO = 277,
    INTERROGACAO = 278,
    DOISPONTOS = 279,
    RESTO = 280,
    PONTOVIRGULA = 281,
    MAIS = 282,
    MENOS = 283,
    VEZES = 284,
    DIVIDIDO = 285,
    PROGRAMA = 286,
    ID = 287,
    RETORNE = 288,
    LEIA = 289,
    ESCREVA = 290,
    NOVALINHA = 291,
    SE = 292,
    ENTAO = 293,
    SENAO = 294,
    ENQUANTO = 295,
    EXECUTE = 296,
    CAR = 297,
    INT = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "bison.y"

    int intValue;
    char charValue;
    //VarType varType;

#line 107 "cafezinho.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_TAB_H_INCLUDED  */
