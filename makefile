all: stringProg
stringProg:
	gcc -g -Wall -o stringProg main.c
  
.PHONY: clean all

clean:
	rm -f *.o connections lib*
