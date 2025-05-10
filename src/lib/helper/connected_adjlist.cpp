#include "../headerFiles/connected_adjlist.h"


bool isConnected(const vector<vector<int>> &adj, int n){
    
    vector<bool> visited(n, false);
    
    stack<int> dfs_stack;

    dfs_stack.push(0);

    while (!dfs_stack.empty()){
        int node = dfs_stack.top();
        dfs_stack.pop();
        if (visited[node]){
            continue;
        }
        visited[node] = true;
        for (int u : adj[node]){
            if (!visited[u]) {
                dfs_stack.push(u);
            }
        }
    }

    bool connected = true;

    for (bool i : visited){
        if (!i){
            connected = false;
            break;
        }
    }

    return (connected ? true : false);
}

