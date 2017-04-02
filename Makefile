DEPS = crossfireOperations.h
OBJ = main.c boardOperations.c userInteraction.c

%.o: %.c $(DEPS)
	$(gcc) -c -o $@ $< 

Ass3: $(OBJ)
	gcc -o $@ $^ 
