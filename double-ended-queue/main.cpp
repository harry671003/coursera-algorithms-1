#include <iostream>

#include "dequeue.cpp"
#include "iterator.hpp"
#include "list-iterator.cpp"

using namespace std;

int main() {

    Dequeue<int> dq = Dequeue<int>();
    dq.AddLast(1);
    dq.AddLast(2);
    dq.AddLast(3);

    Iterator<int>* it = dq.CreateIterator();

    for(it -> First(); it -> IsDone(); it -> Next()) {
        cout << it -> Current() << " ";
    }

    return 0;
}