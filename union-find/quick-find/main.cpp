#include <fstream>
#include <iostream>

#include "union-find.hpp"

using namespace std;

int main(int argc, char** argv) {
    char* inputFilename = argv[1];
    char* connectedFilename = argv[2];
    UnionFind *uf;

    ifstream inputFile(inputFilename);
    ifstream connectedFile(connectedFilename);

    if(inputFile.is_open()) {
        int totalElements;
        inputFile >> totalElements;

        uf = new UnionFind(totalElements);

        int elementA, elementB;
        while(inputFile >> elementA >> elementB) {
            uf->Union(elementA, elementB);
            cout << endl << "union(" << elementA << ", " << elementB << ")";
        }
    }

    if(connectedFile.is_open()) {
        int elementA, elementB;
        while(connectedFile >> elementA >> elementB) {
            cout << endl << "connected(" << elementA << ", " << elementB << ") = " << uf->Connected(elementA, elementB);
        }
    }

    uf->Print();

    return 0;
}