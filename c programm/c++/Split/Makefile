CC=g++ 
CFLAGS=-I. 
DEPS = my_header.hpp 
OBJ = main.o my_functions.o 
%.o: %.cpp $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) 
myprog: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) 
.PHONY: clean 
clean: 
	del *.o