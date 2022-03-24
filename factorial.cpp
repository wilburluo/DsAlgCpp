//
// Created by rowe on 2022/3/24.
//
//使用栈实现阶乘的非递归版本
#include <iostream>
#include "stack.h"
#include "lstack.h"
#include "book.h"

using std::cout;
using std::cin;
using std::endl;

long factorial(int n, Stack<int> &S);

long factorial(int);

int main() {
    int n=12;
    LStack<int> S;
//    cin >> n;
    cout << factorial(n, S) << endl;
//    cout << factorial(n, S) << endl;
    return 0;
}

long factorial(int n, Stack<int> &S) {
    Assert((n >= 0) && (n <= 12), "n out of range.\n");
    while (n > 1) S.push(n--);
    long result = 1;
    while (S.length() > 0) result = result * S.pop();
    return result;
}

long factorial(int n) {
    Assert((n >= 0) && (n <= 12), "n out of range.\n");
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}