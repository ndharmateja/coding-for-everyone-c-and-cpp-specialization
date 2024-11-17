all: assignment2

assignment2: assignment2.o graph.o weighted-edge.o dijkstras.o
	clang++ --std=c++17 assignment2.o graph.o weighted-edge.o dijkstras.o -o assignment2

assignment2.o: assignment2.cpp graph.cpp dijkstras.cpp
	clang++ --std=c++17 -c assignment2.cpp -o assignment2.o

graph.o: graph.cpp weighted-edge.cpp
	clang++ --std=c++17 -c graph.cpp -o graph.o

weighted-edge.o: weighted-edge.cpp
	clang++ --std=c++17 -c weighted-edge.cpp -o weighted-edge.o

dijkstras.o: dijkstras.cpp graph.cpp weighted-edge.cpp
	clang++ --std=c++17 -c dijkstras.cpp -o dijkstras.o

clean:
	rm *.o
	rm assignment2

launch:
	./assignment2