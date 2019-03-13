HEADERS = lib/queue.h
BIN_NAME=fifo-problem
CC=gcc

default: program

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

program: $(OBJECTS)
	$(CC) main.c $(OBJECTS) -o $(BIN_NAME)

clean:
	-rm -f $(OBJECTS)
	-rm -f program
