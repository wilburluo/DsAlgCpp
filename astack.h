//
// Created by rowe on 2022/3/12.
//

#ifndef DSALGCPP_ASTACK_H
#define DSALGCPP_ASTACK_H

#include "stack.h"

template<typename E>
class Astack : public Stack<E> {
private:
    int maxSize;
    int top;
    E *listArray;

public:
    Astack(int size = defaultSize) {
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }

    void clear() {
        top = 0;
    }

    void push(const E &it) {
        Assert(top != maxSize, "Stack is full!");
        listArray[top++] = it;
    }

    E pop() {
        Assert(top != 0, "Stack is empty!");
        return listArray[--top];
    }

    const E &topValue() const {
        Assert(top != 0, "Stack is empty!");
        return listArray[top - 1];
    }

    int length() const { return top; }
};

#endif //DSALGCPP_ASTACK_H
