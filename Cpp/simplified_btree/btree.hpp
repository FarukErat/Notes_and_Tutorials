#pragma once
#ifndef BB_TREE
#define BB_TREE

#include <vector>

template <typename T>
class BBTree {
private:
    std::vector<T> list;

public:
    void print();
    void add(T value, bool unique = false);
    void remove(T value);
    bool find(T value);
};

template <typename T>
void BBTree<T>::print() {
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void BBTree<T>::add(T value, bool unique) {
    unsigned start = 0;
    unsigned end = list.size();
    unsigned middle;

    while (start < end) {
        middle = (start + end) / 2;

        if (list[middle] == value && unique) {
            return;
        }
        else if (list[middle] < value) {
            start = middle + 1;
        }
        else {
            end = middle;
        }
    }

    list.insert(list.begin() + start, value);
}

template <typename T>
void BBTree<T>::remove(T value) {
    unsigned start = 0;
    unsigned end = list.size() - 1;
    unsigned middle;

    while (start <= end) {
        middle = (start + end) / 2;

        if (list[middle] == value) {
            list.erase(list.begin() + middle);
            return;
        }
        else if (list[middle] < value) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }
}

template <typename T>
bool BBTree<T>::find(T value) {
    unsigned start = 0;
    unsigned end = list.size() - 1;
    unsigned middle;

    while (start <= end) {
        middle = (start + end) / 2;

        if (list[middle] == value) {
            return true;
        }
        else if (list[middle] < value) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    return false;
}


#endif // BB_TREE