FLAGS = -Wall -Werror -Wextra -std=c11

all: s21_cat

rebuild: clean all

s21_cat: flagsRealisation
	gcc $(FLAGS) flagsRealisation.o s21_cat.c -o s21_cat

flagsRealisation:
	gcc -c $(FLAGS) flagsRealisation.c -o flagsRealisation.o

test:
	bash t_cat.sh

clean:
	rm -rf s21_cat *.o
