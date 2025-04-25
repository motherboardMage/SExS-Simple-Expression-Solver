SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=%.o)
CC = gcc-14
CFLAGS = -Wall -Wextra

all: SExS clean

SExS: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o SExS
	@echo "Compilation comlpleted."

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@."

.PHONY: all clean


clean:
	rm -f $(OBJS)
	@echo "Cleaned up object files."