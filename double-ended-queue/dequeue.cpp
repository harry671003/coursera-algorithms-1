#include <iostream>
#include <stdexcept>

#include "dequeue.hpp"
#include "node.hpp"
#include "iterator.hpp"
#include "list-iterator.hpp"

using namespace std;

#ifndef DEQUEUE_CPP
#define DEQUEUE_CPP

template <typename Item>
Dequeue<Item>::Dequeue() {
    _first = NULL;
    _last = NULL;
    _size = 0;
}

template <typename Item>
Dequeue<Item>::~Dequeue() {
    while(_first != NULL) {
        Node<Item>* temp = _first;
        _first = _first -> next;
        delete temp;
    }
}

template <typename Item>
int Dequeue<Item>::Size() {
    return _size;
}

template <typename Item>
void Dequeue<Item>::AddFirst(Item item) {
    Node<Item>* newNode = new Node<Item>;
    newNode -> value = item;
    newNode -> next = _first;
    newNode -> prev = NULL;
    _first = newNode;

    if(_size = 0) {
        _last = newNode;
    }

    // Increment size
    _size++;
}

template <typename Item>
void Dequeue<Item>::AddLast(Item item) {
    Node<Item>* newNode = new Node<Item>;
    newNode -> value = item;
    newNode -> next = NULL;
    newNode -> prev = _last;

    if(_size > 0) {
        _last -> next = newNode;
    }
    else {
        _first = newNode;
    }

    _last = newNode;

    _size ++;
}

template <typename Item>
Item Dequeue<Item>::RemoveFirst() {
    if(_size == 0) {
        throw underflow_error("Cannot remove item from an empty queue.");
    }

    Node<Item>* temp = _first;
    Item value = temp -> value;

    _first = _first -> next;

    if(_size == 1) {
        _last = NULL;
    }
    else {
        _first -> prev = NULL;
    }

    _size--;
    delete temp;
    return value;
}

template <typename Item>
Item Dequeue<Item>::RemoveLast() {
    if(_size == 0) {
        throw underflow_error("Cannot remove item from an empty queue.");
    }

    Item value = _last -> value;
    Node<Item>* prevNode = _last -> prev;

    delete _last;
    _last = prevNode;

    if(_size == 1) {
        _first = NULL;
    }
    else {
        prevNode -> next = NULL;
    }

    _size --;

    return value;
}

template <typename Item>
void Dequeue<Item>::Print() {
    Node<Item>* temp = _first;
    while(temp != NULL) {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
}

template <typename Item>
Iterator<Item>* Dequeue<Item>::CreateIterator() {
    return new ListIterator<Item>(_first);
}


#endif