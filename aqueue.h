//
// Created by rowe on 2022/3/25.
//

#ifndef DSALGCPP_AQUEUE_H
#define DSALGCPP_AQUEUE_H

#include "queue.h"

template<typename E>
class AQueue : public Queue<E> {
private:
    int maxSize;
    int front;
    int rear;
    E *listArray;

public:
    AQueue(int size = 10) {
        maxSize = size + 1;
        rear = 0;
        front = 1;
        listArray = new E[maxSize];
    }

    ~AQueue() { delete[] listArray; }

    void clear() {
        rear = 0;
        front = 1;
    }

    void enqueue(const E& it) {
        if (((rear + 2) % maxSize) == front) {
            std::cout << "Queue is full" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        rear = (rear + 1) % maxSize;
        listArray[rear] = it;
    }

    E dequeue() {
        if (length() == 0) {
            std::cout << "Queue is empty.\n";
            std::exit(EXIT_FAILURE);
        }
        E it = listArray[front];
        front = (front + 1) % maxSize;
        return it;
    }

    const E &frontValue() const {
        if (length() == 0) {
            std::cout << "Queue is empty.\n";
            std::exit(EXIT_FAILURE);
        }
        return listArray[front];
    }

    virtual int length() const {                        //这里的virtual是什么意思？??
        return ((rear + maxSize) - front + 1) % maxSize;
    }
};


#endif //DSALGCPP_AQUEUE_H
