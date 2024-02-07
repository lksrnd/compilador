#ifndef types_h
#define types_h

#include <stdlib.h>

typedef enum {
    VAR_EMPTY,
    VAR_INTEGER,
    VAR_ERROR,
    VAR_CHAR,
    VAR_STRING
} VarType;

typedef enum {
    ASSIGN,
    IDENTIFIER,
    STATEMENT,
    ID_ARRAY,
    IF,
    ELSE,
    WHILE,
    UNARY,
    BINARY,
    TERNARY,
    BLOCK,
    DECLARATION,
    FUNC_DECLARATION,
    FUNC_CALL,
    VARIABLE,
    ARRAY_VARIABLE,
    LIST_VARIABLE,
    INTEGER,
    CHAR,
    STRING,
    NEW_LINE,
    READ,
    WRITE,
    START,
    EMPTY,
    RETURN,
    EXPRESSION,
    EXPRESSION_LIST
} NodeType;

typedef enum {
    SUM,
    SUB,
    MULTIPLY,
    DIVIDE,
    EQUAL,
    DIFFERENT,
    MINOR,
    MORE,
    NEGATIVE,
    REST,
    NEGATE,
    AND,
    OR,
    CONDITIONAL,
    LESS_EQUAL,
    GREATER_EQUAL
} Operator;

typedef struct Element Element;

struct Element {
    Element* next;
    int lineNum, intValue, level;
    char charValue;
    char name[256]; 
    Operator operatorType;
    NodeType nodeType;
    VarType varType;
    Element* id; 
    
};

#endif
