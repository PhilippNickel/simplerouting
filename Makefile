CC=gcc
CFLAGS=-Wall -Wextra -Iinclude
INPUTS=src/*.c
OUTPUT=routing

.PHONY: all
all:
	$(CC) $(CFLAGS) $(INPUTS) -o $(OUTPUT)

.PHONY: clean
clean:
	rm -f $(OUTPUT)

