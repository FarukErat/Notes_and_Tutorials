#pragma once
#ifndef UNORDERED_MAP
#define UNORDERED_MAP

#include "DLList.hpp"

template <typename K, typename V>
class UnorderedMap {
private:
    int size = 0;
    DLList<K> keys;
    DLList<V> values;

public:
    int search(K key) {
        for (int i = 0; i < size; i++) {
            if (key == keys[i]) {
                return i;
            }
        }
        return -1;
    }
    V& operator[](K key) {
        // search key
        int index = search(key);

        // when found
        if (index != -1) { return values[index]; }

        // when not found
        size++;
        keys.append(key);
        values.append((V)(NULL));
        return values[values.getSize() - 1];
    }
    int getSize() const { return size; }
    bool containsKey(K key) const {
        return search(key) != -1;
    }
    bool isEmpty() const { return size == 0; }
    V getValue(K key) const {
        int index = search(key);
        if (index != -1) { return values[index]; }
        return (V)(NULL);
    }
    void removeKey(K key) {
        int index = search(key);
        if (index != -1) {
            size--;
            keys.remove(index);
            values.remove(index);
        }
    }
};

#endif // UNORDERED_MAP
