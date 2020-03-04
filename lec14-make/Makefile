# Variables
TARGET=lec14
OBJ_FILES=main.o Guards.o Point.o Path.o
CC=gcc
CC_FLAGS=-Wall -Wextra -std=c11 -g
LINK_MATH=-lm

# Rules
lec14: main.o Guards.o Point.o Path.o 
	gcc -Wall -Wextra -std=c11 -g main.o Guards.o Point.o Path.o -o lec14 -lm

main.o: main.c
	${CC} ${CC_FLAGS} -c main.c

Point.o: Point.c
	${CC} ${CC_FLAGS} -c Point.c

Path.o: Path.c
	${CC} ${CC_FLAGS} -c Path.c

Guards.o: Guards.c
	${CC} ${CC_FLAGS} -c Guards.c

.PHONY: clean
clean:
	rm -f ${OBJ_FILES} ${TARGET}
