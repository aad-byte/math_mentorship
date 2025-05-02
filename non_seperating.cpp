#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int node, vector<vector<int>> &graph, vector<bool> &visited);

int main(){
    int n1, n2, n3, edges; //the node pairs between vertices exsist
    cin >> edges; // first enter number of edges
    vector<vector<int>> graph;

    //in the input, an edge should not repeat - idk if this acctualy matters but I go with this assumption
    for (int i = 0; i < edges; i++){
        cin >> n1 >> n2; // get pair of nodes where the edge exists between them
        
        //go to the first nodes's index and stor n2 in it's personal vector
        if(graph.size() <= n1){
            graph.resize(n1 + 1);
        }
        graph[n1].push_back(n2); // add n2 to n1's list

        if(graph.size () <= n2){
            graph.resize(n2 + 1);
        }
        graph[n2].push_back(n1); // add n1 to n2's personal list
    }

    
    int numnodes = graph.size(); //to keep track of number of nodes
    int label = graph.size(); //use this as the starting node for dfs, cause this index will def be created

     //repeat same thing but directly remove the cycle

     cin >> edges; //get num of edges in the cycle 
    
     
    for(int i = 0; i < edges; i++ ){
        cin >> n1 >> n2 >> n3; // have to enter the 
        //now its like n1 and n2 dont exsists right? so for each of the things stored in their personl array i have to go to thoes which connected to n1 and n2 and change them to a new node
        for( int i = 0; i < graph[n1].size(); i++){
            int indexUD = graph[n1][i];
              if(indexUD != n2 && indexUD != n3) {
                replace(graph[indexUD].begin(), graph[indexUD].end(), n1, numnodes); //dont create branched node for neighbors part of the cycle
                graph.resize(graph.size() + 1);
                graph[numnodes].push_back(indexUD); //to the new node's personal list, add the n1's former element
                numnodes++; //update labele to be different for next node, also keeps track of the number of nodes
                }
        }
        graph[n1].clear(); //clear everything from this vec cause now this node is gone 
        //do the same thing for n2
    
    }

    //go through all the labels, and for the nodes that are floating, remove them??

   
    //Then DFS through graph, we should find num nodes number of vertices, if we dont, then the graph is dissconnected
    //sudo code

    vector<bool> visited(numnodes); //auto-intialized to false, each node has a stauts but may not be nesscarily visited cause some are removed with the cycle
    
   bool answer;
    if ((numnodes -= edges) ==  dfs(label, graph, visited)) //number of nodes after removing the cycle nodes
    {
         answer = true;
    }
    else if( (numnodes) < dfs(label, graph, visited)){
        cout << "erorr shouldnt be possible";
    }
    else{
        answer = false;
    }

    cout << answer;
}

int dfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
    visited[node] = true;
    int count = 1;

    for(int i = 0; i < graph[node].size(); i++){ //go through all neighbouring nodes and dfs them if they arent vistited
        if(visited[graph[node][i]] == false){
            count += dfs(graph[node][i], graph, visited); 
        }
    }

    return count;
}