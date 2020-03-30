CXXFLAGS := -std=c++11
TSP-3: TSP-3.o tsp.o
	g++ $(CXXFLAGS) -o TSP-3 TSP-3.o tsp.o

TSP-3.o: main.cpp tsp.h
	g++ $(CXXFLAGS) -c main.cpp

tsp.o: tsp.cpp tsp.h
	g++ $(CXXFLAGS) -c tsp.cpp