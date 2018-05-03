# Mój plik makefile - wpisz 'make all' aby skompilować cały program
# (właściwie wystarczy wpisać 'make' - all jest domyślny jako pierwszy cel)
CPP = g++  

all: main.o tests.o
	$(CPP) main.o tests.o -std=c++11 -o aplikacja

main.o: main.cpp tests.h
	$(CPP) main.cpp -std=c++11 -c -o main.o

tests.o: tests.cpp tests.h tensor.h
	$(CPP) tests.cpp -std=c++11 -c -o tests.o

clean:
	rm -f *.o aplikacja