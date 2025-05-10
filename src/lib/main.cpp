#include <iostream>
#include "headerFiles/triangulation.h"
#include "headerFiles/er_graph.h"
#include "headerFiles/connected_adjlist.h"
#include <sstream> 
#include <fstream>
#include "headerFiles/percentageTrue.h"


using namespace std;

string graphToString(vector<vector<int>>& graph) {
    ostringstream oss;
    oss << "\"[";  // start quote for CSV and open bracket
    for (size_t i = 0; i < graph.size(); ++i) {// for every row, create another list with it's items"
        oss << "[";
        for (size_t j = 0; j < graph[i].size(); ++j) {
            oss << graph[i][j];
            if (j + 1 < graph[i].size()){
                oss << ","; // dont add a comma for the last element 
            }
        }
        oss << "]";
        if (i + 1 < graph.size()) oss << ","; //dont add comma for last row
    }
    oss << "]\"";  // close bracket and quote
    return oss.str();
}

int main(){
    srand(time(0));
    int n;
    cin >> n; //num of node

   //int edges = (n*(n-1))/2;
   //int graphs = pow(2, edges) * 0.01;
   int graphs = 1000;

   // generate E-R grpah with determined probability

   
   int filenumber = 0;
   string filename;  
   double p = 1/128; 
do{
    if(filenumber <6){
        p = 1/pow(2, 7-filenumber);
    }
    else{
        p = 1- (1/pow(2, filenumber -5)); //adjust probiality each iteration
    }
    
    filename = "result" + to_string(filenumber) + "n" + to_string(n)+ "p"+to_string(p)+ ".csv"; //dynmically name files
    ofstream file(filename);
   file << "Triangulated,Connected,Graph\n"; //create csv columns
   for(int i = 0; i < graphs; i ++){
    vector<vector<int>> generate = generateErGraph(n,  p); //generate er graphs 

   bool triResult = checkTriangulation(generate); //determine if its triangulated, connected
   bool conResult = isConnected(generate, n);
     string graphStr = graphToString(generate); //convert graph to string to store in csv

     //write to file
    file 
        << (triResult ? "true" : "false" ) << ","
         << (conResult ? "true" : "false") << ","
         << graphStr << "\n";
        
   }
   file.close();
   filenumber++; //increase number
}while(percentageTrue(filename, 0) < 90);//repeat the process for number of n node grpahs until the percentage of triangulated grpahs exceeds 90%
   

}