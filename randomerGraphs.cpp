#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool withProbability(double p); 

int main(){
    srand(time(0));
    int n;
    double p;
    cin >> n >> p; //input the number of nodes and probability that an edge exists between the two nodes

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

    for(int i = 0; i < erGraph.size(); i++){
        for(int j = 0; j < erGraph[i].size(); j++){
            cout << "Edge between: " << i << " " << erGraph[i][j];
        }
    }


}



bool withProbability(double p){
    return (rand()%100 < p*100);
}