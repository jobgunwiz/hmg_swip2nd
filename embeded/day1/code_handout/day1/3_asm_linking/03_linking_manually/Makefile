compile:
	gcc -g -S decrement.c -o decrement.s 

asm:	
	as -o foo.o       foo.s 
	as -o decrement.o decrement.s

link:
	gcc -o foo foo.o decrement.o -no-pie

all: compile asm link

gdb:
	gdb foo

clean:
	rm *.o foo
