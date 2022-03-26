//
// Created by rowe on 2022/3/25.
//

#ifndef DSALGCPP_QUEUE_H
#define DSALGCPP_QUEUE_H

template<typename E>
class Queue {
private:
    void operator=(const Queue<E>&){}
    Queue(const Queue<E>&){}

public:
    Queue(){}
    virtual ~Queue(){}

    virtual void clear() = 0;
    virtual void enqueue(const E&) = 0;
    virtual E dequeue() = 0;
    virtual const E& frontValue() const = 0;
    virtual int length() const = 0;
};


#endif //DSALGCPP_QUEUE_H
