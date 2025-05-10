#include "connectedness.cpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> graph = {
      {0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 0}, {0, 1, 0, 0}};

  std::cout << (isConnected(graph) ? "Connected" : "Not connected")
            << std::endl;
  return 0;
}
