all: hello

hello: hello.o func.o
	g++ -o hello hello.o func.o

func.o: func.cpp func.h
	g++ -c func.cpp

hello.o: hello.cpp
	g++ -c hello.cpp