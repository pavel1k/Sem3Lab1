#pragma once
#include "Sort.h"
#include <cassert>

int compare_int(int a, int b) {
    if (a > b)
        return 1;
    return 0;
}

void test1(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(7);   // { 2, 5, 8, 3, 1, 6, 9 } 
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, 2);
    testing->Set(1, 5);
    testing->Set(2, 8);
    testing->Set(3, 3);
    testing->Set(4, 1);
    testing->Set(5, 6);
    testing->Set(6, 9);
    testing = sort(testing, compare_int);
    assert(1 == testing->Get(0));
    assert(2 == testing->Get(1));
    assert(3 == testing->Get(2));
    assert(5 == testing->Get(3));
    assert(6 == testing->Get(4));
    assert(8 == testing->Get(5));
    assert(9 == testing->Get(6));
    assert(7 == testing->GetLength());
}

void test2ForSame(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(5);   // {14, 1000, 1000, 1000, 1523 }
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, 14);
    testing->Set(1, 1000);
    testing->Set(2, 1000);
    testing->Set(3, 1000);
    testing->Set(4, 1523);
    testing = sort(testing, compare_int);
    assert(14 == testing->Get(0));
    assert(1000 == testing->Get(1));
    assert(1000 == testing->Get(2));
    assert(1000 == testing->Get(3));
    assert(1523 == testing->Get(4));
    assert(5 == testing->GetLength());
}

void test3For1Element(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(1);
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, 13);
    testing = sort(testing, compare_int);
    assert(13 == testing->Get(0));
    assert(1 == testing->GetLength());
}

void test4ForEmpty(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(0);
    Sequence<int>* testing = &arr_testing;
    testing = sort(testing, compare_int);
    assert(0 == testing->GetLength());
}

void test5ForNegative(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(6);
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, -13);
    testing->Set(1, -17);
    testing->Set(2, -19);
    testing->Set(3, -114);
    testing->Set(4, -12);
    testing->Set(5, -5);
    testing = sort(testing, compare_int);
    assert(-114 == testing->Get(0));
    assert(-19 == testing->Get(1));
    assert(-17 == testing->Get(2));
    assert(-13 == testing->Get(3));
    assert(-12 == testing->Get(4));
    assert(-5 == testing->Get(5));
}

void test6ForMixed(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(9);
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, 13);
    testing->Set(1, 133);
    testing->Set(2, 1333);
    testing->Set(3, 13333);
    testing->Set(4, 0);
    testing->Set(5, -12);
    testing->Set(6, -122);
    testing->Set(7, -1222);
    testing->Set(8, -12222);
    testing = sort(testing, compare_int);
    assert(-12222 == testing->Get(0));
    assert(-1222 == testing->Get(1));
    assert(-122 == testing->Get(2));
    assert(-12 == testing->Get(3));
    assert(0 == testing->Get(4));
    assert(13 == testing->Get(5));
    assert(133 == testing->Get(6));
    assert(1333 == testing->Get(7));
    assert(13333 == testing->Get(8));
    assert(9 == testing->GetLength());
}

void test7ForAllZero(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(5);
    Sequence<int>* testing = &arr_testing;
    for (int i = 0; i < 5; i++) {
        testing->Set(i, 0);
    }
    testing = sort(testing, compare_int);
    for (int i = 0; i < 5; i++) {
        assert(0 == testing->Get(i));
    }
    assert(5 == testing->GetLength());
}

void test8Backward(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(6);
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, 18);
    testing->Set(1, 17);
    testing->Set(2, 16);
    testing->Set(3, 15);
    testing->Set(4, 14);
    testing->Set(5, 13);
    testing = sort(testing, compare_int);
    for (int i = 0; i < 6; i++) {
        assert(i + 13 == testing->Get(i));
    }
    assert(6 == testing->GetLength());
}

void test9For2Elements(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(2);
    Sequence<int>* testing = &arr_testing;
    testing->Set(0, 22);
    testing->Set(1, -22);
    testing = sort(testing, compare_int);
    assert(-22 == testing->GetFirst());
    assert(22 == testing->GetLast());
    assert(2 == testing->GetLength());
}

void test10ForSorted(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    ArraySequence<int> arr_testing(10);
    Sequence<int>* testing = &arr_testing;
    for (int i = 0; i < 10; i++) {
        testing->Set(i, i - 15);
    }
    testing = sort(testing, compare_int);
    for (int i = 0; i < 10; i++) {
        assert(i - 15 == testing->Get(i));
    }
    assert(10 == testing->GetLength());
}


void testSort(Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    test1(sort);
    test2ForSame(sort);
    test3For1Element(sort);
    test4ForEmpty(sort);
    test5ForNegative(sort);
    test6ForMixed(sort);
    test7ForAllZero(sort);
    test8Backward(sort);
    test9For2Elements(sort);
    test10ForSorted(sort);
}

void testAllSorts() {
    testSort(bubbleSort);
    testSort(mergeSortForSeq);
    testSort(sortWithTree);
}