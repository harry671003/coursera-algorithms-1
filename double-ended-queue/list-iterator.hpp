#include "node.hpp"
#include "iterator.hpp"

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

template <typename Item>
class ListIterator: public Iterator<Item> {
private:
    Node<Item>* _current;
    Node<Item>* _first;
public:
    ListIterator(Node<Item>* first);
    bool IsDone() const;
    void Next();
    void First();
    Item Current() const;
};

#endif