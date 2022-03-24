//
// Created by rowe on 2022/3/24.
//
#include "book.h"
#include "astack.h"
#include "StackTest.h"

int main(int argc, char** argv){
    Astack<Int> S1;
    Astack<Int> S2(15);
    Astack<int> S3;

    StackTest<Int>(S1);
    StackTest<int>(S3);
    return 0;
}
