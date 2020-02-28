a.out: demo.o Guards.o Rational.o
	gcc demo.o Guards.o Rational.o

demo.o: demo.c
	gcc -Wextra -Wall -std=c11 -g -c demo.c

Guards.o: Guards.c
	gcc -Wextra -Wall -std=c11 -g -c Guards.c

Rational.o: Rational.c
	gcc -Wextra -Wall -std=c11 -g -c Rational.c
