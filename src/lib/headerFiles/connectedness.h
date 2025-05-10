#pragma once

#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>> &adjMatrix, vector<bool> &visited);
bool isConnected(const vector<vector<int>> &adjMatrix);

