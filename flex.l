%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cafezinho.tab.h"
#include "types.h"

int lineNum = 1;
void yyerror(const char *s);

%}
%x COMENTARIO
%option yylineno
DIGIT   [0-9]
CHAR    [A-Za-z]        
ID      [a-zA-Z_][a-zA-Z0-9_]*
COMENTARIO 	     "/*"([^*]|"*"+[^*/])*"*"+"/"
CADEIADECARACTERES   '"' ID* '"'

%%

"/*" {
    lineNum = yylineno;
    BEGIN(COMENTARIO);
    }
<COMENTARIO>"*/" { BEGIN(INITIAL); }
<COMENTARIO>(.|\n);
<COMENTARIO><<EOF>> {printf("(ERRO DE SINTAXE: COMENTÁRIO NÂO TERMINA NA LINHA %d,\"/*\")\n",lineNum);}


"["         {return (ABRECOLCHETES); }

"]"         { return (FECHACOLCHETES);  }

"("         { return (ABREPARENTESES);  }

")"         { return (FECHAPARENTESES);  }

"="         { return (IGUAL);  }

"!="        { return (DIFERENTE);  }

"=="        { return (RECEBE);  }

"<="        { return (MENORIGUAL);  }

">="        { return (MAIORIGUAL);  }

"<"         { return (MENOR); }

">"         { return (MAIOR);  }

","         { return (VIRGULA);  }

"{"         { return (ABRECHAVE);  }

"}"         { return (FECHACHAVE); }

"!"         { return (EXCLAMACAO); }

"?"         { return (INTERROGACAO); }

":"         { return (DOISPONTOS);  }

"*"         { return (VEZES);  }

"%"         { return (RESTO);  }

"/"         { return (DIVIDIDO); }

"-"         { return (MENOS);  }

"+"         { return (MAIS);  }

";"         { return (PONTOVIRGULA);  }

"programa"  { return (PROGRAMA);  }

"car"       { return (CAR); }

"int"       { return (INT);  }

"retorne"   { return (RETORNE);  }

"leia"      { return (LEIA);  }

"escreva"   { return (ESCREVA);  }

"novalinha" { return (NOVALINHA); }

"se"        { return (SE);  }

"entao"     { return (ENTAO);  }

"senao"     { return (SENAO); }

"enquanto"  { return (ENQUANTO); }

"execute"   { return (EXECUTE);  }

"e"         { return (ABRECOLCHETES);  }

"ou"        { return (OU);  }

{CHAR}       { return (CARCONST);  }

{ID}+       { return (ID);  }

{DIGIT}+    { return (INTCONST);  }



\"([^"\n\\]|\\(.|\n))*\" {
   printf("Cadeia de caracteres: %s\n", yytext);
   return(CADEIADECARACTERES);
}


\n         {lineNum++;} //CONTAGEM DE LINHAS

[ \t]+  ; //IGNORAR ESPAÇOS EM BRANCO

.   {printf("ERRO SINTAXE: CARACTERE INVALIDO %c\n", *yytext);}

%%

int yywrap() {
    return 1;
}
