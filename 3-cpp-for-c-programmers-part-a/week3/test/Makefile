all: test

test: test.o header.o
	clang++ test.o header.o -o test -arch arm64 --std=c++17

test.o: test.cpp header.hpp
	clang++ --std=c++17 -c test.cpp -o test.o

header.o: header.cpp
	clang++ --std=c++17 -c header.cpp -o header.o

clean:
	rm *.o
	rm test

launch:
	./test