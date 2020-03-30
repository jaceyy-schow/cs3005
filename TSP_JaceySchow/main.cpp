
#include <stdio.h>
#include "tsp.h"


int main(){
    
    int vertices;
    std::cout << "Integer Value? " << std::endl;
    std::cin >> vertices ;

    Graph myGraph(vertices);
    
    std::cout << "Insert Edges and Weights " << std::endl;
    while(std::cin){
        int x,y;
        double j;
        std::cin >> x >> y >> j;
        myGraph.addEdge(x,y,j);
    }
    std::vector<double> anypath = myGraph.findAnyPath(1);
    std::vector<double> bestpath = myGraph.findBestPath(1);
    std::vector<double> worstpath = myGraph.findWorstPath(1);


    
    for(size_t i = 0;i<anypath.size();i++){
        std::cout << anypath[i] << ',';
    }
    std::cout << "" <<std::endl;
    for(size_t i = 0;i<bestpath.size();i++){
         std::cout << bestpath[i] << ',';
    }
    std::cout << "" <<std::endl;
    for (size_t i = 0; i < worstpath.size(); i++){
        std::cout << worstpath[i] << ',';
    }
    std::cout << "" <<std::endl;
    
    
    
    return 0;
}
