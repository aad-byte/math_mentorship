#include "../headerFiles/triangulation.h"


bool checkTriangulation(vector<vector<int>> &graph){

    vector<bool> triangle(graph.size(), false); //initalize all nodes to be false

    for(int i = 0; i < graph.size(); i++){
        if(triangle[i] == false){//dont double check nodes that are already validated
            inTriangle(graph, i, triangle);
        }
    }

    bool answer = true;

    for(int i = 0; i < triangle.size(); i++){
        if(triangle[i] == false){
            answer = false;
            break;
        }
    }

   return answer;
}


//this method recives a graph, an node (int), and a boolean vec to keep track of node status, it updates the bool vec based on if node is part of atleast 1 cycle length 3
void inTriangle(const vector<vector<int>> &graph, int x, vector<bool> &triangle){

    for(int i = 0; i < graph[x].size(); i++){//iterate through each connecting node to x
        int index = graph[x][i];
        if(sharedNode(graph[x], graph[index]) != -1){//if the two nodes are a part of the same triangle
            triangle[sharedNode(graph[x], graph[index])] = true; //update node staus in bool array
            triangle[x] = true;
            triangle[index] = true;
            return; 
        }
    }

}

//this method recievs two lists and checks to see if they share a node. If they do the node is returned, else -1
int sharedNode(vector<int> x, vector<int> y){
    vector<int> slist = shorterList(x, y);
    vector<int> llist = longerList(x, y);

    for(int i = 0; i < slist.size(); i++){
        if(searchElement(slist[i], llist) != -1){//iterate through each node in the shorter list, checking to see if it exists in the other list
            return searchElement(slist[i], llist);
        }
    }

    return -1;
}
//this method recievs two lists and returns the shorter one
vector<int> shorterList(vector<int> &x, vector<int> &y){
    if(y.size() < x.size()){
        return y;
    }
    else{
        return x;
    }
}

//this method recievs two lists and returns the longer one
vector<int> longerList(vector<int> &x, vector<int> &y){
    if(y.size() >= x.size()){
        return y;
    }
    else{
        return x;
    }
}

//this method recievs an int and a int vector, it searches for the int in the list, and returns it if found
int searchElement(int x, vector<int> &list){
    for(int i = 0; i < list.size(); i ++){
        if(list[i] == x){
            return x;
        }
    }
    return -1;
}