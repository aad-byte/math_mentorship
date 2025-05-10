#include "../headerFiles/percentageTrue.h"

double percentageTrue(const string& filename, int columnIndex) {
    ifstream file(filename);
    string line;
    int total = 0;
    int trueCount = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        int col = 0;
        while (getline(ss, cell, ',')) {
            if (col == columnIndex) {
                if (cell == "true")
                    trueCount++;
                total++;
                break;
            }
            col++;
        }
    }

    return total > 0 ? (100.0 * trueCount / total) : 0.0;
}