all: door_struct list_test stack_test

rebuild: all clean

door_struct:
	gcc -Wall -Wextra -Werror dmanager_module.c -o ../build/Quest_1

list_test: list.o
	gcc -Wall -Wextra -Werror list.o list_test.c -o ../build/Quest_2

stack_test: stack.o
	gcc -Wall -Wextra -Werror stack.o stack_test.c -o ../build/Quest_3

list.o:
	gcc -c -Wall -Wextra -Werror list.c

stack.o:
	gcc -c -Wall -Wextra -Werror stack.c

clean:
	rm -rf *.o
