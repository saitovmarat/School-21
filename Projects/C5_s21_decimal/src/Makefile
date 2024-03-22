FLAGS = -Wall -Werror -Wextra -std=c11
UNAME_S := $(shell uname -s)
OBJ = Functions/*.c 
OBJ_TEST = tests/*.c

ifeq ($(UNAME_S),Linux)
OPEN_CMD = xdg-open
ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
LEAKS_CMD = valgrind --tool=memcheck --leak-check=yes
endif

ifeq ($(UNAME_S),Darwin)
OPEN_CMD = open -a "Google Chrome"
ADD_LIB = -lcheck -lm
LEAKS_CMD = leaks -atExit --
endif

all: clean s21_decimal.a gcov_report

build: clean
	@gcc -c $(OBJ)
	@gcc *.o main.c -g -o test && clear

compile: build
	@./test
	@rm -rf *.gcda *.gcno *.out *.info s21_decimal.a *.o report

s21_decimal.a:
	@gcc $(CFLAGS) $(OBJ) -c 
	@ar rc s21_decimal.a *.o
	@ranlib s21_decimal.a
	@rm *.o

test: clean
	@gcc $(OBJ) --coverage $(OBJ_TEST) -o test $(ADD_LIB)
	@./test
	@rm -rf *.gcda *.gcno

gcov_report:
	@gcc $(FLAGS) --coverage $(OBJ) $(OBJ_TEST) -o test $(ADD_LIB)
	@./test
	@lcov -t "s21_decimal_test" -o decimal_test.info -c -d .
	@genhtml -o report decimal_test.info
	@$(OPEN_CMD) ../src/report/Functions/index.html
	@rm *.gcda *.gcno

valgrind: test
	@valgrind --tool=memcheck --leak-check=yes  ./test
style:
	@clang-format -style=google -n Functions/*.c Tests/*.c Tests/*.h

clean:
	@rm -rf *.gcda *.gcno *.out *.info s21_decimal.a *.o test report

main: $(OBJ) main.c
	@gcc $(OBJ) main.c 
	@./a.out
