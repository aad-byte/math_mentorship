#include <vector>
#include <iostream>

using namespace std;


// DFS function
void dfs(int node, const vector<vector<int>> &adjMatrix,
  vector<bool> &visited) {
  visited[node] = true;
  for (int neighbor = 0; neighbor < adjMatrix.size(); ++neighbor) {
    if (adjMatrix[node][neighbor] && !visited[neighbor]) {
      dfs(neighbor, adjMatrix, visited);
    }
  }
}

// check connectedness
bool isConnected(const vector<vector<int>> &adjMatrix) {
  int n = adjMatrix.size();
  if (n == 0)
    return true; // An empty graph is trivially connected

  vector<bool> visited(n, false);
  dfs(0, adjMatrix, visited);

  // Check if all nodes were visited
  for (bool v : visited) {
    if (!v)
      return false;
  }
  return true;
}

int main(){
  vector<vector<int>> graph = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 0}, {0, 1, 0, 0}};

  cout << (isConnected(graph) ? "Connected" : "Not connected") << endl;
  return 0;

}
