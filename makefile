toyScanner: project1.l toyScanner.c trie.c
	lex project1.l
	gcc toyScanner.c trie.c lex.yy.c -o toyScanner

clean:
	rm -f lex.yy.c toyScanner
