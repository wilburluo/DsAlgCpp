//
// Created by Rowe on 2022/2/21.
//

#ifndef DSALGCPP_LINK_H
#define DSALGCPP_LINK_H

template<typename E>
class Link {
public:
    E element;
    Link *next;

    Link(const E &elemval, Link *nextval = nullptr) {
        element = elemval;
        next = nextval;
    }

    Link(Link *nextval = nullptr) {
        next = nextval;
    }
};

#endif //DSALGCPP_LINK_H
