FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic

all: s21_grep

rebuild: clean all

s21_grep:
	gcc $(FLAGS) s21_grep.c -o s21_grep

test:
	bash t_grep.sh
	
clean:
	rm -rf s21_grep *.o