all: main.c buche.h
	gcc -Wall -O2 main.c -o main
clean:
	rm -f main
