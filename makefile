all: main.o random_num.o
	gcc -o randfile main.o random_num.o

main.o: main.c random_num.h
	gcc -c main.c

random_num.o: random_num.c random_num.h
	gcc -c random_num.c

run:
	./randfile

clear:
	rm *.o
	rm randfile
	rm text.txt
