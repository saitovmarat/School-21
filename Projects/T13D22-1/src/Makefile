all: cipher

rebuild: all clean

cipher: logger.o
	gcc -Wall -Wextra -Werror logger.o cipher.c -o ../build/cipher

logger.o:
	gcc -c -Wall -Wextra -Werror logger.c

clean:
	rm -rf *.o

