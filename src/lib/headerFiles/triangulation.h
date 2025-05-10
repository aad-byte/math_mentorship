#pragma once

#include <vector>
using namespace std;

int searchElement(int x, vector<int> &list);
vector<int> longerList(vector<int> &x, vector<int> &y);
vector<int> shorterList(vector<int> &x, vector<int> &y);
int sharedNode(vector<int> x, vector<int> y);
void inTriangle(const vector<vector<int>> &graph, int x, vector<bool> &triangle);
bool checkTriangulation(vector<vector<int>> &graph);

