CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=undefined
DBG_CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=undefined
SRCS = main.c

default: bento
all: bento
bento:
	$(CC) $(CFLAGS) $(SRCS) -o $@ 
debug:
	$(CC) $(DBG_CFLAGS) $(SRCS) -o $@
clean:
	rm -f bento
re: clean bento
