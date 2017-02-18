CC = gcc
CCFLAGS = -Wall -g

build: mymalloc.c
	${CC} ${CCFLAGS} mymalloc.c memgrind.c -o mymalloc

clean:
	rm -rf *.o mymalloc
