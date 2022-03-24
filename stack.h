//
// Created by rowe on 2022/3/12.
//

#ifndef DSALGCPP_STACK_H
#define DSALGCPP_STACK_H

template<typename E>
class Stack {
private:
    void operator=(const Stack &) {}

    Stack(const Stack &) {}

public:
    Stack() {}

    virtual ~Stack() {}

    virtual void clear() = 0;

    virtual void push(const E &) = 0;

    virtual E pop() = 0;

    virtual const E &topValue() const = 0;

    virtual int length() const = 0;
};

#endif //DSALGCPP_STACK_H
