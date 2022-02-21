//
// Created by Rowe on 2022/2/21.
//

#ifndef DSALGCPP_LINKFL_H
#define DSALGCPP_LINKFL_H

template<typename E> class Link{
private:
    static Link<E>* freelist;

public:
    E element;
    Link* next;

    Link(const E& elemval, Link* nextval = nullptr){
        element = elemval;
        next = nextval;
    }

    Link(Link* nextval = nullptr){
        next = nextval;
    }

    void* operator new(size_t){
        if(freelist == nullptr) return ::new Link;
        Link<E>* temp = freelist;
        freelist = freelist->next;
        return temp;
    }

    void operator delete(void* ptr){
        ((Link<E>*)ptr)->next = freelist;
        freelist = (Link<E>*)ptr;
    }
};

template<typename E>
Link<E>* Link<E>::freelist = nullptr;

#endif //DSALGCPP_LINKFL_H
