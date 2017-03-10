# CS411-Project-1
CS 411 Project 1
Philip Chiang
Professor Atanasio
This program is a lexical analyzer for a fictional C-like programming language, Toy.

Instructions for running program:
    This program was written and tested on Ubuntu 16.04.1 LTS.
    Install flex:
        - Open terminal
        - Enter "sudo apt-get install flex"
    Running the lexer:
        - Make sure project1.l, test1.txt, toyScanner.c, toyScanner.h,
            trie.c, and trie.h are in the same folder
        - Navigate to that folder and enter the commands in terminal:
            lex project1.l
            gcc toyScanner.c trie.c lex.yy.c
            ./a.out test1.txt
        - change "text1.txt" to a different name to test different files
