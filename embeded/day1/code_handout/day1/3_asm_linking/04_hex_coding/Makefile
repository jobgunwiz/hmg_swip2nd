compile:
	gcc -g -S foo.c       -o foo.s
	gcc -g -S increment.c -o increment.s 
	gcc -g -S decrement.c -o decrement.s 

asm:	
	as -o foo.o       foo.s
	as -o increment.o increment.s
	as -o decrement.o decrement.s

link:
	gcc -o foo foo.o increment.o decrement.o

all: compile asm link

gdb:
	gdb foo

dump:
	objdump -d -S foo > foo_dis.s

clean:
	rm *.o foo *.s
