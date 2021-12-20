#pragma once
#include "ArraySequence.h"
using namespace std;

template <typename T>
Sequence <T>* bubbleSort(Sequence <T>* seq, int (*cmp)(T, T)) {
    for (int i = 0; i < seq->GetLength(); i++) {
        for (int j = 0; j < seq->GetLength() - 1; j++) {
            if (cmp(seq->Get(j), seq->Get(j + 1))) { // j > j + 1?
                T tmp = seq->Get(j);
                seq->Set(j, seq->Get(j + 1));
                seq->Set(j + 1, tmp);
            }
        }
    }
    return seq;
}


template <typename T>
void merge(Sequence<T>* seq, int (*cmp)(T, T), int left, int mid, int right) {
    int i, j, k;
    int left_leng = mid - left + 1;
    int right_leng = right - mid;


    ArraySequence<T> first_tmp(left_leng), second_tmp(right_leng);
    Sequence<T>* left_seq = &first_tmp;
    Sequence<T>* right_seq = &second_tmp;

    for (i = 0; i < left_leng; i++) {
        left_seq->Set(i, seq->Get(i + left));
    }
    for (j = 0; j < right_leng; j++) {
        right_seq->Set(j, seq->Get(mid + 1 + j));
    }

    i = 0; j = 0; k = left;

    while (i < left_leng && j < right_leng) {
        if (cmp(right_seq->Get(j), left_seq->Get(i))) {
            seq->Set(k, left_seq->Get(i));
            i++;
        }
        else {
            seq->Set(k, right_seq->Get(j));
            j++;
        }
        k++;
    }

    while (i < left_leng) {
        seq->Set(k, left_seq->Get(i));
        i++;
        k++;
    }

    while (j < right_leng) {
        seq->Set(k, right_seq->Get(j));
        j++;
        k++;
    }
}


template <typename T>
void mergeSort(Sequence<T>* seq, int (*cmp)(T, T), int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(seq, cmp, left, mid);
        mergeSort(seq, cmp, mid + 1, right);

        merge(seq, cmp, left, mid, right);
    }
}

template <typename T>
Sequence <T>* mergeSortForSeq(Sequence <T>* seq, int (*cmp)(T, T)) {
    if (seq->GetLength())
        mergeSort(seq, cmp, 0, seq->GetLength() - 1);
    return seq;
}


template <typename T>
class BST {
private:
    struct node {
        T data;
        node* left;
        node* right;
    };
    node* root;
    int count_for_KLP;
    void destroyTree(node* branch) {
        if (branch != nullptr) {
            destroyTree(branch->left);
            destroyTree(branch->right);
            delete branch;
        }
    }

    int cmpForBst(T a, T b) {
        if (a > b)
            return 1;
        return 0;
    }

    void insertHelp(node* branch, T item) {
        node* cur = branch;
        if (cmpForBst(cur->data, item)) {
            if (cur->left != nullptr) {
                insertHelp(cur->left, item);
            }
            else {
                cur->left = new node;
                cur->left->data = item;
                cur->left->left = nullptr;
                cur->left->right = nullptr;
            }
        }
        else {
            if (cur->right != nullptr) {
                insertHelp(cur->right, item);
            }
            else {
                cur->right = new node;
                cur->right->data = item;
                cur->right->left = nullptr;
                cur->right->right = nullptr;
            }
        }
    }



    Sequence<T>* lkpHelp(node* branch, Sequence<T>* seq) {
        node* tmp = branch;
        if (tmp) {
            lkpHelp(branch->left, seq);
            seq->Set(this->count_for_KLP, branch->data);
            this->count_for_KLP++;
            lkpHelp(branch->right, seq);;
        }
        return seq;
    }

public:
    BST() {
        this->root = nullptr;
        count_for_KLP = 0;
    };

    ~BST() {
        destroyTree(this->root);
        count_for_KLP = 0;
    };

    Sequence <T>* LKP(Sequence<T>* seq) {
        return lkpHelp(this->root, seq);
    }

    void insert(T item) {
        if (this->root != nullptr)
            insertHelp(this->root, item);
        else {
            this->root = new node;
            this->root->data = item;
            this->root->right = nullptr;
            this->root->left = nullptr;
        }
    }
};

template <typename T>
Sequence<T>* sortWithTree(Sequence<T>* seq, int (*cmp)(T, T)) {
    BST<T> assist_tree;
    for (int i = 0; i < seq->GetLength(); i++) {
        assist_tree.insert(seq->Get(i));
    }
    return assist_tree.LKP(seq);
}