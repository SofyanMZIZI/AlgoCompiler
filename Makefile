default:
	flex -o scanner.c scanner.l
	bison -o parser.c -d parser.y
	gcc scanner.c parser.c -o algoCompiler
	clear
	./algoCompiler test1.algo

clean:
	rm scanner.c algoCompiler parser.c parser.h
