#include <stdio.h>
#include <stdbool.h>
#include "toyScanner.h"

extern int yylex();
extern int yylineno;
extern char * yytext;
extern FILE * yyin;
extern void initTrie();
extern void addToTrie(char* str);
extern void printTrie();

char* tokens[] = {
    NULL,"boolean", "break","class","double",
    "else","extends", "false", "for","if",
    "implements","int","interface","newarray",
    "println","readln","return","string", "true",
    "void","while","plus","minus",
    "multiplication","division","mod","less",
    "lessequal","greater","greaterequal","equal",
    "notequal","and","or","not",
    "assignop", "semicolon", "comma","period", 
    "leftparen", "rightparen", "leftbracket","rightbracket", 
    "leftbrace","rightbrace", "intconstant", "doubleconstant", 
    "stringconstant", "booleanconstant","id"}; 

int main(int argc, char * argv[])
{
    int ntoken, vtoken;
    // manual input
    // ntoken = yylex();
    // initTrie();
    // while(ntoken)
    // {
    //     printf("%s ", tokens[ntoken]);
    //     if(tokens[ntoken] == "id")
    //     {
    //         addToTrie(yytext);
    //     }
    //     ntoken = yylex();
    // }

    // read from file
    if(argv[1] == NULL)
    {
        printf("Usage: ./a.out filename.txt\n");
        return 1;
    }
    yyin = fopen(argv[1], "r");
    ntoken = yylex();
    initTrie();
    // add reserved words to trie
    for(int i = BOOLEAN; i <= WHILE; i++)
    {
        addToTrie(tokens[i]);
    }

    while(ntoken)
    {
        // identifiers
        if(ntoken == ID)
        {
            addToTrie(yytext);
        }
        printf("%s ", tokens[ntoken]);
        ntoken = yylex();
    }
    printf("\n");
    printTrie();
    fclose(yyin);
    return 0;
}
