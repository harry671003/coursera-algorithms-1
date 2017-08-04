#include "union-find.hpp"
#include <iostream>

using namespace std;

UnionFind::UnionFind(int totalSize) {
    _totalSize = totalSize;
    _data = new int[totalSize];

    for(int i = 0; i < totalSize; i++) {
        _data[i] = i;
    }
}

UnionFind::~UnionFind() {
    delete[] _data;
}

void UnionFind::Union(int elA, int elB) {
    if(Connected(elA, elB)) return;

    int valueToBeReplacedWith = _data[elB];
    int searchValue = _data[elA];
    for(int i = 0; i < _totalSize; i++) {
        if(_data[i] == searchValue) {
            _data[i] = valueToBeReplacedWith;
        }
    }
}

bool UnionFind::Connected(int elA, int elB) {
    return _data[elA] == _data[elB];
}

void UnionFind::Print() {
    cout << endl;
    for(int i = 0; i < _totalSize; i++)
        cout << _data[i] << " ";
}