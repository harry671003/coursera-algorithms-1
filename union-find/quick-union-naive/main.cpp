#include <fstream>
#include <iostream>

#include "quick-union-naive.hpp"

using namespace std;

int main(int argc, char** argv) {
    char* inputFilename = argv[1];
    char* connectedFilename = argv[2];
    QuickUnionNaive *qun;

    ifstream inputFile(inputFilename);
    ifstream connectedFile(connectedFilename);

    if(inputFile.is_open()) {
        int totalElements;
        inputFile >> totalElements;

        qun = new QuickUnionNaive(totalElements);

        int elementA, elementB;
        while(inputFile >> elementA >> elementB) {
            qun->Union(elementA, elementB);
            cout << endl << "union(" << elementA << ", " << elementB << ")";
        }
    }

    if(connectedFile.is_open()) {
        int elementA, elementB;
        while(connectedFile >> elementA >> elementB) {
            cout << endl << "connected(" << elementA << ", " << elementB << ") = " << qun->Connected(elementA, elementB);
        }
    }

    qun->Print();

    return 0;
}