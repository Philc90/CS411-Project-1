#ifndef TRIE_H
#define TRIE_H

#define MAX_LEN 300
const char ALPH[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int _switch[52];
char _symbol[MAX_LEN];
int _next[MAX_LEN];
int _endOfTable;

void test1();
void test2();
void initTrie();
void printTrie();
int printSwitch(int start, int limit, int numPerLine);
int printSymbolAndNext(int start, int limit, int numPerLine);
void addToTrie(char* str);

#endif // TRIE_H