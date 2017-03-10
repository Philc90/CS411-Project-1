%{
#include "toyScanner.h"
%}

%%
"boolean"               return BOOLEAN;
"break"                 return BREAK;
"class"                 return CLASS;
"double"                return DOUBLE;
"else"                  return ELSE;
"extends"               return EXTENDS;
"false"                 return FALSE;
"true"                  return TRUE;
"for"                   return FOR;
"if"                    return IF;
"implements"            return IMPLEMENTS;
"int"                   return INT;
"interface"             return INTERFACE;
"newarray"              return NEWARRAY;
"println"               return PRINTLN;
"readln"                return READLN;
"return"                return RETURN;
"string"                return STRING;
"void"                  return VOID;
"while"                 return WHILE;
"//"(.)*[\n]                            ; // singleline comments
"/*"([^*]|(\*+[^*/]))*\*+\/             ; // multiline comments
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return MULTIPLICATION;
"/"                     return DIVISION;
"%"                     return MOD;
"<"                     return LESS;
"<="                    return LESSEQUAL;
">"                     return GREATER;
">="                    return GREATEREQUAL;
"=="                    return EQUAL;
"!="                    return NOTEQUAL;
"&&"                    return AND;
"||"                    return OR;
"!"                     return NOT;
"="                     return ASSIGNOP;
";"                     return SEMICOLON;
","                     return COMMA;
"."                     return PERIOD;
"("                     return LEFTPAREN;
")"                     return RIGHTPAREN;
"["                     return LEFTBRACKET;
"{"                     return LEFTBRACE;
"}"                     return RIGHTBRACE;
"]"                     return RIGHTBRACKET;
[0-9]+([.]?[eE][-+]?[0-9]+)|([.][0-9]*)     return DOUBLECONSTANT;
([0-9]+)|(0[xX][0-9a-fA-F]+)                return INTCONSTANT;
\"(\\.|[^"])*\"         return STRINGCONSTANT;
[a-zA-Z][a-zA-Z0-9_]*   return ID;
[\n]                    printf("\n");
[ \t]*                  ;
.                       printf("ERROR: unexpected character.\n");
%%

int yywrap(void)
{
    return 1;
}
