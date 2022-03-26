//
// Created by rowe on 2022/3/25.
//

#ifndef DSALGCPP_LQUEUE_H
#define DSALGCPP_LQUEUE_H
#include "queue.h"
#include "link.h"

template<typename E>
class LQueue: public Queue<E>{
private:
    Link<E> *front;
    Link<E> *rear;
    int size;

public:
    LQueue(int sz = 10){
        front = nullptr ;rear = nullptr; size = 0;
    }
    ~LQueue(){clear();}

    void clear(){
        while (front != nullptr){
            rear = front;
            front = front->next;
            delete rear;
        }
        rear = nullptr;
        size = 0;
    }

    void enqueue(const E& it){
        if(rear == nullptr)
            front = rear = new Link<E>(it, nullptr);
        else{
            rear->next = new Link<E>(it, nullptr);
            rear = rear->next;
        }
        ++size;
    }

    E dequeue(){
        if(size == 0){
            std::cout << "Queue is empty.\n";
            std::exit(EXIT_FAILURE);
        }
        E it = front->element;
        Link<E> *ltemp = front;
        front = front->next;
        delete ltemp;
        if(front == nullptr)    rear = nullptr;
        --size;
        return it;
    }

     const E& frontValue() const {
        if(size == 0){
            std::cout << "Queue is empty.\n";
            std::exit(EXIT_FAILURE);
        }
         return front->element;
    }

    int length() const{
        return size;
    }
};


#endif //DSALGCPP_LQUEUE_H
