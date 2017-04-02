CC=gcc
CFLAGS=-I.
DEPS = crossfireOperations.h
OBJ = main.c boardOperations.c userInteraction.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
