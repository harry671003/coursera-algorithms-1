#ifndef NODE_HPP
#define NODE_HPP

template <typename Item>
class Node {
public:
    Item value;
    Node<Item>* next;
    Node<Item>* prev;
};

#endif