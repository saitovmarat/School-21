all: graph

rebuild: all clean
	
graph: print.o toPolish.o countPolish.o
	gcc -Wall -Wextra -Werror print.o toPolish.o countPolish.o graph.c -o ../build/graph -lm

print.o:
	gcc -c -Wall -Wextra -Werror -lm print.c

toPolish.o:
	gcc -c -Wall -Wextra -Werror -lm toPolish.c

countPolish.o:
	gcc -c -Wall -Wextra -Werror -lm countPolish.c
	
clean:
	rm -rf *.o
