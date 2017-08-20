#include "node.hpp"
#include "iterator.hpp"


#ifndef DEQUEUE_HPP
#define DEQUEUE_HPP

template <typename Item>
class Dequeue {
private:
    Node<Item>* _first;
    Node<Item>* _last;
    int _size;

public:
    Dequeue();
    ~Dequeue();
    int Size();
    void AddFirst(Item item);
    void AddLast(Item item);
    Item RemoveFirst();
    Item RemoveLast();
    void Print();
    Iterator<Item>* CreateIterator();
};

#endif