all: stringProg
libstr.a: my_mat.o
	ar -rcs libstr.a str.o
my_mat.o:
	gcc -g -Wall -c str.c
stringProg: libstr.a
	gcc -static -Wall -g main.c -L. -lstr -o stringProg
.PHONY: clean all

clean:
	rm -f *.o connections lib*
