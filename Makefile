default:
	flex -o scanner.c scanner.l
	bison -o parser.c -d parser.y
	gcc scanner.c parser.c -o algoCompiler
	clear

test:
	./algoCompiler test1.algo
	./algoCompiler test2.algo
	./algoCompiler test3.algo

clean:
	rm scanner.c algoCompiler parser.c parser.h
