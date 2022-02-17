help:
	@echo "make all"
	@echo "make clean"


all:
	gcc -o     main     *.c
	gcc -O3 -o main_opt *.c 

clean:
	rm -rf *.o main 

dump:
	objdump -d -S main     > main_dis.s
	objdump -d -S main_opt > main_opt_dis.s