#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename Item>
class Iterator {
public:
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Item Current() const = 0;
    virtual void First() = 0;
};

#endif