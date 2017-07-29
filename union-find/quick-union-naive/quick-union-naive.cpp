#include "quick-union-naive.hpp"
#include <iostream>

using namespace std;

QuickUnionNaive::QuickUnionNaive(int totalSize) {
    _totalSize = totalSize;
    _data = new int[totalSize];

    for(int i = 0; i < totalSize; i++) {
        _data[i] = i;
    }
}

QuickUnionNaive::~QuickUnionNaive() {
    delete[] _data;
}

void QuickUnionNaive::Union(int elA, int elB) {
    if(Connected(elA, elB)) return;

    int rootElA = Root(elA);
    int rootElB = Root(elB);

    _data[rootElA] = rootElB;
}

bool QuickUnionNaive::Connected(int elA, int elB) {
    return Root(elA) == Root(elB);
}

void QuickUnionNaive::Print() {
    cout << endl;
    for(int i = 0; i < _totalSize; i++)
        cout << _data[i] << " ";
}

int QuickUnionNaive::Root(int el) {
    if(_data[el] == el)
        return el;
    return Root(_data[el]);
}
