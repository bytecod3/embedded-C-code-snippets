GCC = gcc
CFLAGS = -g -Wall -Wshadow #replace -g by -O

# -O optimizes the program, -g adds debugging information to the compiled objec

prog: aredistinct.o file-check.o
	$(GCC) $(CFLAGS) aredistinct.o file-check.o -o prog

aredistinct.o: aredistinct.c
	$(GCC) $(CFLAGS) -c aredistinct.c

file-check.o: file-check.c
	$(GCC) $(CFLAGS) -c file-check.c
