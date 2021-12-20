#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include "Sort.h"
using namespace chrono;

int compare_int(int, int);

double time_sort(Sequence<int>* seq, Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    auto start = high_resolution_clock::now();
    sort(seq, compare_int);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

bool auto_check(Sequence<int>* seq, int (*cmp)(int a, int b)) {
    if (seq->GetLength() == 0)
        return 1;
    for (int i = 0; i < seq->GetLength() - 1; i++) {
        if (cmp(seq->Get(i), seq->Get(i + 1)))
            return 0;
    }
    return 1;
}

void Menu() {
    int indikator = 1;
    cout << "*** INT SORTER ***" << endl;
    while (indikator) {
        cout << "1) to sort sequence" << endl;
        cout << "2) to find out the best sort for concrete sequence" << endl;
        cout << "3) to create random sequence and sort it(from your length)" << endl;
        cout << "4) to find out what sort better in sorted, " << endl << "unsorted and randomly sorted sequence" << endl;
        cout << "0) to exit" << endl;
        cin >> indikator;

        if (indikator == 1) {
            cout << "length of sequence [0, 32000] : " << endl;
            int length = 0;
            cin >> length;
            if (0 > length || length > 32000)
                throw out_of_range(IndexOutOfRangeEx);
            ArraySequence<int> arr_seq(length);
            Sequence <int>* seq = &arr_seq;
            cout << "enter elements of your sequence: " << endl;
            for (int i = 0; i < length; i++) {
                int cur_element = 0;
                cin >> cur_element;
                seq->Set(i, cur_element);
            }
            cout << "1) bubble sort" << endl;
            cout << "2) merge sort" << endl;
            cout << "3) sort with Binary Tree" << endl;
            cin >> indikator;
            cout << "your sequence:" << endl;
            seq->print();
            if (indikator == 1) {
                bubbleSort(seq, compare_int)->print();
            }
            else if (indikator == 2) {
                mergeSortForSeq(seq, compare_int)->print();
            }
            else if (indikator == 3) {
                sortWithTree(seq, compare_int)->print();
            }
            indikator = 1;
        }

        else if (indikator == 2) {
            cout << "length of sequence [0, 32000] : " << endl;
            int length = 0;
            cin >> length;
            if (0 > length || length > 32000)
                throw out_of_range(IndexOutOfRangeEx);
            ArraySequence<int> arr_seq1(length);
            Sequence <int>* seq1 = &arr_seq1;
            cout << "enter elements of your sequence: " << endl;
            for (int i = 0; i < length; i++) {
                int cur_element = 0;
                cin >> cur_element;
                seq1->Set(i, cur_element);
            }
            ArraySequence<int> arr_seq2(seq1);
            Sequence <int>* seq2 = &arr_seq2;
            ArraySequence<int> arr_seq3(seq1);
            Sequence <int>* seq3 = &arr_seq3;

            double best_time = time_sort(seq1, bubbleSort);
            string best_name = "bubble sort";
            cout << "taken " << best_time << " microsecond by bubble sort" << endl;

            double time_for_merge = time_sort(seq2, mergeSortForSeq);
            if (time_for_merge < best_time) {
                best_time = time_for_merge;
                best_name = "merge sort";
            }
            else if (time_for_merge == best_time) {
                best_name += " and merge sort";
            }
            cout << "taken " << time_for_merge << " microsecond by merge sort" << endl;

            double time_for_BST = time_sort(seq3, sortWithTree);
            if (time_for_BST < best_time) {
                best_time = time_for_BST;
                best_name = "sort with Binary tree";
            }
            else if (time_for_BST == best_time) {
                best_name += " and sort with binary tree";
            }
            cout << "taken " << time_for_BST << " microsecond by sort with binary tree" << endl;
            cout << "the best sort for your sequence is " << best_name << ";" <<
                 endl << "sorted for " << best_time << " microseconds" << endl;
        }

        else if (3 == indikator) {
            cout << "enter your length [0, 32000];" << endl << "length = ";
            int length = 0;
            cin >> length;
            if (0 > length || length > 32000)
                throw out_of_range(IndexOutOfRangeEx);
            ArraySequence<int> random_arr(length);
            Sequence<int>* seq = &random_arr;
            for (int i = 0; i < length; i++) {
                seq->Set(i, -5000 + rand() % 10000);
            }
            cout << "generated sequence:" << endl;
            seq->print();

            cout << "1) bubble sort" << endl;
            cout << "2) merge sort" << endl;
            cout << "3) sort with Binary Tree" << endl;
            cin >> indikator;
            if (indikator == 1) {
                cout << "sorted sequence:" << endl;
                bubbleSort(seq, compare_int)->print();
            }
            else if (indikator == 2) {
                cout << "sorted sequence:" << endl;
                mergeSortForSeq(seq, compare_int)->print();
            }
            else if (indikator == 3) {
                cout << "sorted sequence:" << endl;
                sortWithTree(seq, compare_int)->print();
            }
            indikator = 3;
        }

        else if (indikator == 4) {
            cout << "1) best sort for sorted sequence" << endl;
            cout << "2) best sort for backward sorted sequence" << endl;
            cout << "3) best sort for random sorted sequence" << endl;
            cin >> indikator;
            if (1 == indikator) {
                cout << "length of sequence [0, 32000] : " << endl;
                int length = 0;
                cin >> length;
                if (0 > length || length > 32000)
                    throw out_of_range(IndexOutOfRangeEx);
                ArraySequence<int> sorted_arr(length);
                Sequence<int>* seq1 = &sorted_arr;
                for (int i = 0; i < length; i++) {
                    seq1->Set(i, i - length / 2);
                }
                cout << "sorted sequence:" << endl;
                seq1->print();

                ArraySequence<int> arr_seq2(seq1);
                Sequence <int>* seq2 = &arr_seq2;
                ArraySequence<int> arr_seq3(seq1);
                Sequence <int>* seq3 = &arr_seq3;

                double best_time = time_sort(seq1, bubbleSort);
                string best_name = "bubble sort";
                cout << "taken " << best_time << " microsecond by bubble sort" << endl;

                double time_for_merge = time_sort(seq2, mergeSortForSeq);
                if (time_for_merge < best_time) {
                    best_time = time_for_merge;
                    best_name = "merge sort";
                }
                else if (time_for_merge == best_time) {
                    best_name += " and merge sort";
                }
                cout << "taken " << time_for_merge << " microsecond by merge sort" << endl;

                double time_for_BST = time_sort(seq3, sortWithTree);
                if (time_for_BST < best_time) {
                    best_time = time_for_BST;
                    best_name = "sort with Binary tree";
                }
                else if (time_for_BST == best_time) {
                    best_name += " and sort with binary tree";
                }
                cout << "taken " << time_for_BST << " microsecond by sort with binary tree" << endl;
                cout << "the best sort is " << best_name << ";" <<
                     endl << "sorted for " << best_time << " microseconds" << endl;
            }

            else if (2 == indikator) {
                cout << "length of sequence [0, 32000] : " << endl;
                int length = 0;
                cin >> length;
                if (0 > length || length > 32000)
                    throw out_of_range(IndexOutOfRangeEx);
                ArraySequence<int> sorted_arr(length);
                Sequence<int>* seq1 = &sorted_arr;
                for (int i = 0; i < length;i++) {
                    seq1->Set(i, length / 2 - i);
                }
                cout << "backward sorted sequence:" << endl;
                seq1->print();

                ArraySequence<int> arr_seq2(seq1);
                Sequence <int>* seq2 = &arr_seq2;
                ArraySequence<int> arr_seq3(seq1);
                Sequence <int>* seq3 = &arr_seq3;

                double best_time = time_sort(seq1, bubbleSort);
                string best_name = "bubble sort";
                cout << "taken " << best_time << " microsecond by bubble sort" << endl;

                double time_for_merge = time_sort(seq2, mergeSortForSeq);
                if (time_for_merge < best_time) {
                    best_time = time_for_merge;
                    best_name = "merge sort";
                }
                else if (time_for_merge == best_time) {
                    best_name += " and merge sort";
                }
                cout << "taken " << time_for_merge << " microsecond by merge sort" << endl;

                double time_for_BST = time_sort(seq3, sortWithTree);
                if (time_for_BST < best_time) {
                    best_time = time_for_BST;
                    best_name = "sort with Binary tree";
                }
                else if (time_for_BST == best_time) {
                    best_name += " and sort with binary tree";
                }
                cout << "taken " << time_for_BST << " microsecond by sort with binary tree" << endl;
                cout << "the best sort is " << best_name << ";" <<
                     endl << "sorted for " << best_time << " microseconds" << endl;
            }

            else if (3 == indikator) {
                cout << "length of sequence [0, 32000] : " << endl;
                int length = 0;
                cin >> length;
                if (0 > length || length > 32000)
                    throw out_of_range(IndexOutOfRangeEx);
                ArraySequence<int> sorted_arr(length);
                Sequence<int>* seq1 = &sorted_arr;
                for (int i = 0; i < length; i++) {
                    seq1->Set(i, -length / 2 + rand() % length);
                }
                cout << "randomly sorted sequence:" << endl;
                seq1->print();

                ArraySequence<int> arr_seq2(seq1);
                Sequence <int>* seq2 = &arr_seq2;
                ArraySequence<int> arr_seq3(seq1);
                Sequence <int>* seq3 = &arr_seq3;

                double best_time = time_sort(seq1, bubbleSort);
                string best_name = "bubble sort";
                cout << "taken " << best_time << " microsecond by bubble sort" << endl;

                double time_for_merge = time_sort(seq2, mergeSortForSeq);
                if (time_for_merge < best_time) {
                    best_time = time_for_merge;
                    best_name = "merge sort";
                }
                else if (time_for_merge == best_time) {
                    best_name += " and merge sort";
                }
                cout << "taken " << time_for_merge << " microsecond by merge sort" << endl;

                double time_for_BST = time_sort(seq3, sortWithTree);
                if (time_for_BST < best_time) {
                    best_time = time_for_BST;
                    best_name = "sort with Binary tree";
                }
                else if (time_for_BST == best_time) {
                    best_name += " and sort with binary tree";
                }
                cout << "taken " << time_for_BST << " microsecond by sort with binary tree" << endl;
                cout << "the best sort is " << best_name << ";" <<
                     endl << "sorted for " << best_time << " microseconds" << endl;
            }
            indikator = 4;
        }
    }
}

