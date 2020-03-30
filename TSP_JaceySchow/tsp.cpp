
#include "tsp.h"

Graph::Graph(int vertices)
:mVertices(vertices){
    edges.resize(mVertices+1);
    for(size_t i = 0;i < edges.size();i++){
        edges[i].resize(mVertices+1);
    }

}

void Graph::addEdge(int v0,int v1,double weight){
    if (weight < mLow){
        mLow = weight;
    }
    if (weight > mHigh){
        mHigh = weight;
    }
    if(v0 > -1 && v0 <= mVertices){
        edges[v0][v1] = weight;
    }
}
    


    
std::vector<double> Graph::findAnyPath(int v0){
    std::vector<bool> visited;
    std::vector<double> path;
    visited.resize(mVertices+1);
    for(size_t f = 0;f<visited.size();f++){
        visited[f] = false;
    }
    visited[0] = true;
    visited[v0] = true;
    path.push_back(v0);
    double newWeight;
    double totalWeight;
    bool done = false;
    while(done == false){
        done = true;
        int nextIndex = mVertices + 2;
        for(size_t i = 0; i < edges[v0].size();i++){
            if(visited[i] == false && i < nextIndex){
                nextIndex = i;
                newWeight = edges[v0][i];
            }
        }
        v0 = nextIndex;
        totalWeight += newWeight;
        visited[v0] = true;
        path.push_back(v0);
        for(size_t j = 0;j < visited.size();j++){
            if(visited[j] == false){
                done = false;
            }
        }
        
    }
    path.push_back(totalWeight);
    double lowest = mLow * mVertices;
    double heaviest = mHigh * mVertices;
    double quality = 1-(totalWeight-lowest)/(heaviest-lowest);
    path.push_back(quality);
    return path;
}


std::vector<double> Graph::findBestPath(int v0){
    std::vector<bool> visited;
    std::vector<double> path;
    visited.resize(mVertices+1);
    for(size_t f = 0;f<visited.size();f++){
        visited[f] = false;
    }
    visited[0] = true;
    visited[v0] = true;
    path.push_back(v0);
    double totalWeight;
    bool done = false;
    while(done == false){
        double newWeight = 1000000000;
        done = true;
        int nextIndex = mVertices + 2;
        for(size_t i = 0; i < edges[v0].size();i++){
            if(visited[i] == false && edges[v0][i] < newWeight){
                nextIndex = i;
                newWeight = edges[v0][i];
            }
        }
        v0 = nextIndex;
        totalWeight += newWeight;
        visited[v0] = true;
        path.push_back(v0);
        for(size_t j = 0;j < visited.size();j++){
            if(visited[j] == false){
                done = false;
            }
        }
        
    }
    path.push_back(totalWeight);
    double lowest = mLow * mVertices;
    double heaviest = mHigh * mVertices;
    double quality = 1-(totalWeight-lowest)/(heaviest-lowest);
    path.push_back(quality);
    return path;
}

std::vector<double> Graph::findWorstPath(int v0){
    std::vector<bool> visited;
    std::vector<double> path;
    visited.resize(mVertices+1);
    for(size_t f = 0;f<visited.size();f++){
        visited[f] = false;
    }
    visited[0] = true;
    visited[v0] = true;
    path.push_back(v0);
    double totalWeight;
    bool done = false;
    while(done == false){
        double newWeight = 0;
        done = true;
        int nextIndex = mVertices + 2;
        for(size_t i = 0; i < edges[v0].size();i++){
            if(visited[i] == false && edges[v0][i] > newWeight){
                nextIndex = i;
                newWeight = edges[v0][i];
            }
        }
        v0 = nextIndex;
        totalWeight += newWeight;
        visited[v0] = true;
        path.push_back(v0);
        for(size_t j = 0;j < visited.size();j++){
            if(visited[j] == false){
                done = false;
            }
        }
        
    }
    path.push_back(totalWeight);
    double lowest = mLow * mVertices;
    double heaviest = mHigh * mVertices;
    double quality = 1-(totalWeight-lowest)/(heaviest-lowest);
    path.push_back(quality);
    return path;
}

    


