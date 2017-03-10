#include <stdio.h>
#include <stdbool.h>
#include "trie.h"

// int main()
// {
//     test1();
//     test2();
// }

void test1()
{
    initTrie();
    addToTrie("awt");
    addToTrie("awthave");
    addToTrie("cry");
    addToTrie("an");
    addToTrie("and");
    addToTrie("am");
    addToTrie("a");
    printTrie();
    printf("_endOfTable = %d\n", _endOfTable);
}

void test2()
{
    initTrie();
    addToTrie("boolean");
    addToTrie("break");
    addToTrie("class");
    addToTrie("double");
    addToTrie("else");
    addToTrie("extends");
    addToTrie("false");
    addToTrie("for");
    addToTrie("if");
    addToTrie("implements");
    addToTrie("int");
    addToTrie("interface");
    printTrie();
    printf("_endOfTable = %d\n", _endOfTable);
}

void initTrie()
{
    for(int i = 0; i < 52; i++)
    {
        _switch[i] = -1;
    }
    for(int i = 0; i < MAX_LEN; i++)
    {
        _symbol[i] = ' ';
        _next[i] = -1;
    }
    _endOfTable = 0;
}

void printTrie()
{
    int start = 0;
    while(start < 52)
    {
        start = printSwitch(start, 52, 20);
        printf("\n");
    }
    printf("\n\n");
    start = 0;
    while(start < MAX_LEN)
    {
        start = printSymbolAndNext(start, MAX_LEN, 20);
        printf("\n");
    }
}

int printSwitch(int start, int limit, int numPerLine)
{
    printf("       "); // space for "switch:"
    int i = start;
    for(i; i < (start + 20) && i < limit; i++) // print letters
    {
        printf("   %c", ALPH[i]);
    }
    printf("\nswitch:");
    i = start;
    for(i; i < (start + 20) && i < limit; i++) // print switch indexes
    {
        if(_switch[i] < 0)
        {
            printf("  %d", _switch[i]);
        }
        else if(_switch[i] < 10)
        {
            printf("   %d", _switch[i]);
        }
        else if(_switch[i] < 100)
        {
            printf("  %d", _switch[i]);
        }
        else // _switch[i] < 1000
        {
            printf(" %d", _switch[i]);
        }
    }
    printf("\n");
    if(i == limit)
    {
        return limit;
    }
    return start + 20;
}

int printSymbolAndNext(int start, int limit, int numPerLine)
{
    printf("       "); // space for "symbol:"
    int i = start;
    for(i; i < (start + 20) && i < limit; i++) // print indexes
    {
        if(i < 10)
        {
            printf("   %d", i);
        }
        else if(i < 100)
        {
            printf("  %d", i);
        }
        else // i < 1000
        {
            printf(" %d", i);
        }
    }
    printf("\nsymbol:");
    i = start;
    for(i; i < (start + 20) && i < limit; i++)
    {
        printf("   %c", _symbol[i]);
    }
    printf("\nnext:  ");
    i = start;
    for(i; i < (start + 20) && i < limit; i++)
    {
        if(_next[i] < 0)
        {
            printf("    ");
        }
        else
        {
            if(_next[i] < 10)
            {
                printf("   %d", _next[i]);
            }
            else if(_next[i] < 100)
            {
                printf("  %d", _next[i]);
            }
            else // _next[i] < 1000
            {
                printf(" %d", _next[i]);
            }
        }
    }
    printf("\n");
    if(i == limit)
    {
        return limit;
    }
    else
    {
        return start + 20;
    }
}

void addToTrie(char* str)
{
    // printf("in addToTrie: str[0] = %c\n", *str);
    int switchIndex, tableIndex, strIndex = 1;
    if(*str < 'a')
    {
        // Capital letters; achieve 0-based indexing by subtracting 'A'
        switchIndex = *str - 'A';
    }
    else
    {
        // lowercase letters; achieve 0-based indexing by subtracting 'A' and also
        // 6 for the extra symbols in the ascii table b/t upper- and lower-case
        switchIndex = *str - 'A' - 6;
    }

    if(_switch[switchIndex] == -1) // word does not exist that starts with the letter
    {
        _switch[switchIndex] = _endOfTable;
        tableIndex = _endOfTable;

    }
    else // word exists; check to see how much of it is the same
    {
        // printf("in else\n");
        tableIndex = _switch[switchIndex];
        while(_symbol[tableIndex] == str[strIndex]) // keep checking to see if the chars are the same
        {
            // printf(" %c %c\n", _symbol[tableIndex], str[strIndex]);
            tableIndex++;
            strIndex++;
        }
        // printf("first difference: %c %c\n", _symbol[tableIndex], str[strIndex]);
        if(_symbol[tableIndex] == '*' && str[strIndex] == '\0') // word is already in the trie
        {
            // printf("Already found %s; return\n", str);
            return;            
        }
        else // word not in trie, but prefix is in the trie
        {
            bool done = false;
            while(done != true)
            {
                if(str[strIndex] != _symbol[tableIndex])
                {
                    if(_next[tableIndex] != -1)
                    {
                        tableIndex = _next[tableIndex];
                    }
                    else
                    {
                        _next[tableIndex] = _endOfTable;
                        tableIndex = _endOfTable;
                        done = true;
                    }
                }
                else
                {
                    while(str[strIndex] == _symbol[tableIndex])
                    {
                        strIndex++;
                        tableIndex++;
                    }
                    if(str[strIndex] == '\0' && _symbol[tableIndex] == '*') 
                    // word is already in the trie
                    {
                        done = true;
                    }
                }
            }
        }

    }
    while(str[strIndex] != '\0') // keep checking the next char for eos
    {
        // printf("adding %c; strIndex = %d\n", str[strIndex], strIndex);
        _symbol[tableIndex] = str[strIndex];
        tableIndex++;
        _endOfTable++;
        strIndex++;
    }
    _symbol[tableIndex] = '*';
    _endOfTable++;
}