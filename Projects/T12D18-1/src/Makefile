all: print_module

rebuild: all clean

print_module: print_module.o
	gcc -Wall -Wextra -Werror print_module.o main_module_entry_point.c -o ../build/Quest_1

print_module.o:
	gcc -c -Wall -Wextra -Werror print_module.c

clean:
	rm -rf *.o
