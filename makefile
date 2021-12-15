all: main.o
main.o:
	gcc -g -Wall -c main.c
  
.PHONY: clean all

clean:
	rm -f *.o connections lib*
