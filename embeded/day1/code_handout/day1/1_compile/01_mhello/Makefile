help:
	@echo "make help"
	@echo "make all"

hello1.o: hello1.c
	gcc -c hello1.c

hello2.o: hello2.c
	gcc -c hello2.c

hello3.o: hello3.c
	gcc -c hello3.c

all: hello1.o hello2.o hello3.o
	gcc -o hello hello1.o hello2.o hello3.o

clean: 
	rm -rf *.o

cleanup: clean
	rm -rf hello

	

