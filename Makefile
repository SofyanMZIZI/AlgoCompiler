default:
	flex -o scanner.c scanner.l
	bison -o parser.c -d parser.y
	gcc scanner.c parser.c -o algoCompiler
	clear

test1:
	./algoCompiler test1.algo

test2:
	./algoCompiler test2.algo

test3:
	./algoCompiler test3.algo

clean:
	rm scanner.c algoCompiler parser.c parser.h
