CC=g++
CFLAGS = -std=c++11
OBJS = main.o accelerometersample.o

all: app

app: main.o accelerometersample.o 
	$(CC) -o $@ $^ 

main.o: main.cpp accelerometersample.h
	$(CC) -c main.cpp

accelerometersample.o: accelerometersample.cpp accelerometersample.h
	$(CC) -c accelerometersample.cpp

test: test.o accelerometersample.o
	$(CC) $(CFLAGS) -o $@ $^

test.o: test.cpp accelerometersample.h catch2/catch.hpp
	$(CC) $(CFLAGS) -c test.cpp

clean: 
	$(RM) app test *.o *~
