all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

rebuild: all clean
		
s21_string.o: s21_string.c
	gcc -c -Wall -Wextra -Werror s21_string.c 

strlen_tests: s21_string.o
	gcc -Wall -Wextra -Werror -Dstrlen s21_string.o s21_string_test.c -o ../build/Quest_1 

strcmp_tests: s21_string.o
	gcc -Wall -Wextra -Werror -Dstrcmp s21_string.o s21_string_test.c -o ../build/Quest_2

strcpy_tests: s21_string.o
	gcc -Wall -Wextra -Werror -Dstrcpy s21_string.o s21_string_test.c -o ../build/Quest_3

strcat_tests: s21_string.o
	gcc -Wall -Wextra -Werror -Dstrcat s21_string.o s21_string_test.c -o ../build/Quest_4

strchr_tests: s21_string.o
	gcc -Wall -Wextra -Werror -Dstrchr s21_string.o s21_string_test.c -o ../build/Quest_5

strstr_tests: s21_string.o
	gcc -Wall -Wextra -Werror -Dstrstr s21_string.o s21_string_test.c -o ../build/Quest_6

clean:
	rm -rf *.o rebuild
