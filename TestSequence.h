#pragma once
#include <cassert>
#include "ArraySequence.h"
#include "ListSequence.h"
using namespace std;


void testArrSeq1GetLast() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(13);
    assert(13 == seq->GetLast());
    seq->Append(15);
    assert(15 == seq->GetLast());
    seq->Append(0);
    seq->Append(-13);
    assert(-13 == seq->GetLast());
}

void testListSeq1GetLast() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    assert(14 == seq->GetLast());
    seq->Append(15);
    assert(15 == seq->GetLast());
    seq->Append(0);
    seq->Append(-11);
    assert(-11 == seq->GetLast());
}

void testArrSeq2GetFirst() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(13);
    assert(13 == seq->GetFirst());
    seq->Prepend(16);
    assert(16 == seq->GetFirst());
    seq->Prepend(111);
    assert(111 == seq->GetFirst());
}

void testListSeq2GetFirst() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(17);
    assert(17 == seq->GetFirst());
    seq->Prepend(5);
    assert(5 == seq->GetFirst());
    seq->Prepend(1114);
    assert(1114 == seq->GetFirst());
}

void testArrSeq3Get() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Prepend(12);
    seq->Prepend(14);
    seq->Prepend(16);
    assert(14 == seq->Get(1));
    assert(16 == seq->Get(0));
    assert(12 == seq->Get(2));
}

void testListSeq3Get() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Prepend(-12);
    seq->Prepend(-14);
    seq->Prepend(-16);
    assert(-14 == seq->Get(1));
    assert(-16 == seq->Get(0));
    assert(-12 == seq->Get(2));
}

void testArrSeq4Insert() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->InsertAt(14, 0);
    seq->InsertAt(15, 1);
    seq->InsertAt(16, 2);
    seq->InsertAt(17, 3);
    assert(14 == seq->Get(0));
    assert(15 == seq->Get(1));
    assert(16 == seq->Get(2));
    assert(17 == seq->Get(3));
}

void testListSeq4Insert() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->InsertAt(114, 0);
    seq->InsertAt(115, 1);
    seq->InsertAt(116, 2);
    seq->InsertAt(117, 3);
    assert(114 == seq->Get(0));
    assert(115 == seq->Get(1));
    assert(116 == seq->Get(2));
    assert(117 == seq->Get(3));
    assert(seq->GetLength() == 4);
}


void testArrSeq5GetLength() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    assert(0 == seq->GetLength());
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    assert(4 == seq->GetLength());
}

void testListSeq5GetLength() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    assert(0 == seq->GetLength());
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    assert(4 == seq->GetLength());
}

void testArrSeq6Delete() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    seq->delete_i(0);
    assert(124 == seq->GetFirst());
    assert(144 == seq->GetLast());
    assert(3 == seq->GetLength());
    seq->delete_i(2);
    assert(124 == seq->GetFirst());
    assert(134 == seq->GetLast());
    assert(2 == seq->GetLength());
}

void testListSeq6Delete() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    seq->delete_i(0);
    assert(124 == seq->GetFirst());
    assert(144 == seq->GetLast());
    assert(3 == seq->GetLength());
    seq->delete_i(2);
    assert(124 == seq->GetFirst());
    assert(134 == seq->GetLast());
    assert(2 == seq->GetLength());
}

void testArrSeq7SubSeq() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    assert(14 == seq->GetSubSequence(0, 2)->Get(0));
    assert(124 == seq->GetSubSequence(0, 2)->Get(1));
    assert(2 == seq->GetSubSequence(0, 2)->GetLength());
}

void testListSeq7SubSeq() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    assert(14 == seq->GetSubSequence(0, 2)->Get(0));
    assert(124 == seq->GetSubSequence(0, 2)->Get(1));
    assert(2 == seq->GetSubSequence(0, 2)->GetLength());
}

void testArrSeq8Concat() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    ArraySequence<int> testing2;
    Sequence<int>* seq2 = &testing;
    seq2->Concat(seq);
    assert(seq2->GetLength() == 4);
    assert(14 == seq2->Get(0));
    assert(144 == seq2->Get(3));
}

void testListSeq8Concat() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    ArraySequence<int> testing2;
    Sequence<int>* seq2 = &testing;
    seq2->Concat(seq);
    assert(seq2->GetLength() == 4);
    assert(14 == seq2->Get(0));
    assert(144 == seq2->Get(3));
}

void testArrSeq9Concat() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    ArraySequence<int> testing2;
    Sequence<int>* seq2 = &testing;
    seq->Concat(seq2);
    assert(seq->GetLength() == 4);
    assert(14 == seq->Get(0));
    assert(144 == seq->Get(3));
}

void testListSeq9Concat() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    ArraySequence<int> testing2;
    Sequence<int>* seq2 = &testing;
    seq->Concat(seq2);
    assert(seq->GetLength() == 4);
    assert(14 == seq->Get(0));
    assert(144 == seq->Get(3));
}

void testArrSeq10Concat() {
    ArraySequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    ArraySequence<int> testing2;
    Sequence<int>* seq2 = &testing;
    seq2->Append(134);
    seq2->Append(144);
    seq->Concat(seq2);
    assert(seq->GetLength() == 6);
    assert(14 == seq->Get(0));
    assert(144 == seq->Get(5));
    assert(144 == seq->Get(3));
}


void testListSeq10Concat() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(14);
    seq->Append(124);
    seq->Append(134);
    seq->Append(144);
    ArraySequence<int> testing2;
    Sequence<int>* seq2 = &testing;
    seq2->Append(134);
    seq2->Append(144);
    seq->Concat(seq2);
    assert(seq->GetLength() == 6);
    assert(14 == seq->Get(0));
    assert(144 == seq->Get(5));
    assert(144 == seq->Get(3));
}

void testArrSeq11Construct() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ArraySequence<int> testing(a, 5);
    Sequence<int>* seq = &testing;
    for (int i = 0; i < 5; i++) {
        assert(a[i] == seq->Get(i));
    }
    assert(5 == seq->GetLength());
}

void testArrSeq12Construct() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ArraySequence<int> testing(5);
    Sequence<int>* seq = &testing;
    for (int i = 0; i < 5; i++) {
        seq->InsertAt(a[i], i);
    }
    assert(10 == seq->GetLength());
    for (int i = 0; i < 5; i++) {
        assert(seq->Get(i) == a[i]);
    }
}

void testArrSeq13Construct() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ArraySequence<int> testing(a, 5);
    Sequence<int>* seq = &testing;
    Sequence <int>* copied(seq);
    for (int i = 0; i < 5; i++) {
        assert(a[i] == seq->Get(i));
    }
    assert(5 == seq->GetLength());
}

void testListSeq11Construct() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ListSequence<int> testing(a, 5);
    Sequence<int>* seq = &testing;
    for (int i = 0; i < 5; i++) {
        assert(a[i] == seq->Get(i));
    }
    assert(5 == seq->GetLength());
}

void testListSeq12Construct() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    for (int i = 0; i < 5; i++) {
        seq->InsertAt(i + 2, i);
    }
    Sequence <int>* copied(seq);
    for (int i = 0; i < 5; i++) {
        assert(i + 2 == seq->Get(i));
    }
    assert(5 == seq->GetLength());
}

void testArrSeq14Set() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ArraySequence<int> testing(a, 5);
    Sequence<int>* seq = &testing;
    seq->Set(3, 14);
    assert(5 == seq->GetLength());
    assert(14 == seq->Get(3));
    assert(4 == seq->Get(2));
    assert(6 == seq->Get(4));
}

void testListSeq13Set() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ListSequence<int> testing(a, 5);
    Sequence<int>* seq = &testing;
    seq->Set(3, 14);
    assert(5 == seq->GetLength());
    assert(14 == seq->Get(3));
    assert(4 == seq->Get(2));
    assert(6 == seq->Get(4));
}

void testArrSeq15Set() {
    ArraySequence<int> testing(1);
    Sequence<int>* seq = &testing;
    seq->Set(0, 14);
    assert(14 == seq->Get(0));
    assert(1 == seq->GetLength());
}

void testListSeq14Set() {
    ListSequence<int> testing;
    Sequence<int>* seq = &testing;
    seq->Append(10);
    seq->Set(0, 111);
    assert(1 == seq->GetLength());
    assert(111 == seq->Get(0));
}

void testListSeq15Set() {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
    }
    ListSequence<int> testing(a, 5);
    Sequence<int>* seq = &testing;
    for (int i = 0; i < 5; i++) {
        seq->Set(i, i);
    }
    assert(5 == seq->GetLength());
    for (int i = 0; i < 5; i++) {
        assert(seq->Get(i) == i);
    }

}

void testSeq() {
    testArrSeq1GetLast();
    testArrSeq2GetFirst();
    testArrSeq3Get();
    testArrSeq4Insert();
    testArrSeq5GetLength();
    testArrSeq6Delete();
    testArrSeq7SubSeq();
    testArrSeq8Concat();
    testArrSeq9Concat();
    testArrSeq10Concat();
    testArrSeq11Construct();
    testArrSeq12Construct();
    testArrSeq13Construct();
    testArrSeq14Set();
    testArrSeq15Set();
    testListSeq1GetLast();
    testListSeq2GetFirst();
    testListSeq3Get();
    testListSeq4Insert();
    testListSeq5GetLength();
    testListSeq6Delete();
    testListSeq7SubSeq();
    testListSeq8Concat();
    testListSeq9Concat();
    testListSeq10Concat();
    testListSeq11Construct();
    testListSeq12Construct();
    testListSeq13Set();
    testListSeq14Set();
    testListSeq15Set();
}