CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11 
UNAME_S := $(shell uname -s)
OBJ = Functions/*.c
OBJ_TEST = TEST_UNIT/*.c

ifeq ($(UNAME_S),Linux)
OPEN_CMD = xdg-open
ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif

ifeq ($(UNAME_S),Darwin)
OPEN_CMD = open -a "Google Chrome"
ADD_LIB = -lcheck -lm
endif

all: clean s21_math.a gcov_report

test: clean
	@$(CC) $(FLAGS) $(OBJ) $(OBJ_TEST) -o test $(ADD_LIB)
	@./test

s21_math.a: 
	@$(CC) $(CFLAGS) $(OBJ) -c
	@ar rc s21_math.a *.o
	@ranlib s21_math.a
	@rm *.o

gcov_report: 
	$(CC) $(FLAGS) --coverage $(OBJ) $(OBJ_TEST) -o test $(ADD_LIB)
	@./test
	@lcov -t "s21_math_test" -o fizzbuzz.info -c -d .
	@genhtml -o report fizzbuzz.info
	@$(OPEN_CMD) report/Functions/index.html
	@rm *.gcda *.gcno

style:
	@clang-format -n */*.c *.h

clean:
	@rm -rf test s21_math.a *.gcda *.gcno report *.o
