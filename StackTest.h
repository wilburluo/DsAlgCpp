//
// Created by rowe on 2022/3/24.
//

#ifndef DSALGCPP_STACKTEST_H
#define DSALGCPP_STACKTEST_H

#include "stack.h"

template<typename E>
void StackTest(Stack<E> &St) {
    E temp;
    if (St.length() > 0) {
        temp = St.pop();
        cout << "Top is " << temp << endl;
    } else cout << "Nothing in stack\n";
    St.push(10);
    St.push(20);
    St.push(15);
    cout << "Size is " << St.length() << endl;
    if (St.length() > 0) {
        temp = St.pop();
        cout << "Top is " << temp << endl;
    } else cout << "Nothing in stack\n";
    while (St.length() > 0) {
        temp = St.pop();
        cout << temp << " ";
    }
    cout << endl;
    if (St.length() > 0) {
        temp = St.pop();
        cout << "Top is " << temp << endl;
    } else cout << "Nothing in stack\n";
    cout << "Size is " << St.length() << endl;
    St.clear();
    cout << "Size is " << St.length() << endl;
    cout << "That is all.\n\n";
}

#endif //DSALGCPP_STACKTEST_H
