CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=gnu90
SRC=$*-*.c tests/$*-main.c tests/rb_tree_print.c

%:
	rm -rf a.out
	$(CC) $(CFLAGS) $(SRC) 
	betty-doc $(SRC) 1>/dev/null
	betty-style $(SRC)
	valgrind -q ./a.out

1: SRC+=0-*.c
