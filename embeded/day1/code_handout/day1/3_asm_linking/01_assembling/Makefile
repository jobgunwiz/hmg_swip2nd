compile:
	gcc -g -S foo.c -o foo.s

asm:	
	as -o foo.o foo.s

link:
	gcc -o foo foo.o

all: compile asm link

gdb:
	gdb foo

clean:
	rm *.o foo

