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
    ABRECOLCHETES = 258,
    FECHACOLCHETES = 259,
    ABREPARENTESES = 260,
    FECHAPARENTESES = 261,
    IGUAL = 262,
    DIFERENTE = 263,
    RECEBE = 264,
    MENORIGUAL = 265,
    MAIORIGUAL = 266,
    MENOR = 267,
    MAIOR = 268,
    VIRGULA = 269,
    ABRECHAVE = 270,
    FECHACHAVE = 271,
    EXCLAMACAO = 272,
    INTERROGACAO = 273,
    DOISPONTOS = 274,
    VEZES = 275,
    RESTO = 276,
    DIVIDIDO = 277,
    MENOS = 278,
    MAIS = 279,
    PONTOVIRGULA = 280,
    PROGRAMA = 281,
    CAR = 282,
    INT = 283,
    RETORNE = 284,
    LEIA = 285,
    ESCREVA = 286,
    NOVALINHA = 287,
    SE = 288,
    ENTAO = 289,
    SENAO = 290,
    ENQUANTO = 291,
    EXECUTE = 292,
    E = 293,
    OU = 294,
    ID = 295,
    CONSTCAR = 296,
    CONSTINT = 297,
    CADEIACARACTERES = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "cafezinho.y"

    int line;
    char* Tlexema;
    TOperador* Tpont;

#line 107 "cafezinho.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_TAB_H_INCLUDED  */
