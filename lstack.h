//
// Created by rowe on 2022/3/24.
//

#ifndef DSALGCPP_LSTACK_H
#define DSALGCPP_LSTACK_H

#include "link.h"
#include "stack.h"

template<typename E>
class LStack : public Stack<E> {
private:
    Link<E> *top;
    int size;

public:
    LStack(int sz = 10) {
        top = nullptr;
        size = 0;
    }

    ~LStack() { clear(); }

    void clear() {
        while (top != nullptr) {
            Link<E> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const E &it) {
        top = new Link<E>(it, top);
        size++;
    }

    E pop() {
        Assert(top != nullptr, "Stack is empty");
        E it = top->element;
        Link<E> *ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    const E &topValue() const {
        Assert(top != 0, "Stack is empty");
        return top->element;
    }

    int length() const {
        return size;
    }
};


#endif //DSALGCPP_LSTACK_H
