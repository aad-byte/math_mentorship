#include "../headerFiles/er_graph.h"

vector<vector<int>> generateErGraph(int n, double p){

    //generate 1 percent of total possible graphs
    //start at 5 maybe go until 10?

    vector<vector<int>> erGraph(n); //Erdos-Renyi graph with n nodes set-up

    bool edge;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(withProbability(p)){ //based on proability add an edge between each node
                erGraph[i].push_back(j);
                erGraph[j].push_back(i);
            }
        }
    }

    return erGraph;


}



bool withProbability(double p){
    return (static_cast<double>(rand()) / RAND_MAX) < p;
}