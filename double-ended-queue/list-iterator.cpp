#include "list-iterator.hpp"
#include "node.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

#ifndef LIST_ITERATOR_CPP
#define LIST_ITERATOR_CPP

template <typename Item>
ListIterator<Item>::ListIterator(Node<Item>* first) {
    _first = first;
}

template <typename Item>
bool ListIterator<Item>::IsDone() const {
    return _current != NULL;
}

template <typename Item>
void ListIterator<Item>::Next() {
    if(IsDone())
        _current = _current -> next;
    else
        throw overflow_error("No more items in the queue");
}

template <typename Item>
Item ListIterator<Item>::Current() const {
    return _current -> value;
}

template <typename Item>
void ListIterator<Item>::First() {
    _current = _first;
}

#endif