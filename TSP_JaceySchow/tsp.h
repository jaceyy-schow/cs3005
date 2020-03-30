#ifndef tsp_hpp
#define tsp_hpp
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>



class Graph{
public:
    Graph(int vertices);
    void addEdge(int v0,int v1,double weight);
    std::vector<double> findAnyPath(int v0);
    std::vector<double> findBestPath(int v0);
    std::vector<double> findWorstPath(int v0);

    
    
private:
    int mVertices;
    std::vector<std::vector<double>> edges;
    double mHigh = 1000000;
    double mLow;

};

#endif /* tsp_hpp */
