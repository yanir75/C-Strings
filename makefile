all: stringProg
stringProg:
	gcc -g -Wall -o stringProg stringProg.c
  
.PHONY: clean all

clean:
	rm -f *.o connections lib*
