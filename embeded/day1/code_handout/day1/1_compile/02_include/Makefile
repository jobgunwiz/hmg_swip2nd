help:
	@echo "make help"
	@echo "make all"

hello.o: hello.c
	gcc -c hello.c -I.

all: hello.o
	gcc -o hello hello.o 

clean: 
	rm -rf *.o

cleanup: clean
	rm -rf hello

	

