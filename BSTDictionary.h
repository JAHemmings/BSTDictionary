#pragma once

#include <stdexcept>
#include "Dictionary.h"
#include "BSTree.h"
#include "Pair.h"
#include "DLinkedList.h"

using std::runtime_error;

template<typename K, typename V>
class BSTDictionary : public Dictionary<K, V> {

private:
    BSTree<Pair<K, V>> arbol;

public:

    BSTDictionary() {}

    ~BSTDictionary() {}

    void insert(K key, V value) {
        Pair<K, V> pair(key, value);
        if (arbol.contains(pair))
            throw runtime_error("Key already exists.");
        arbol.insert(pair);
    }

    V remove(K key) {
        Pair<K, V> temp(key, V());
        Pair<K, V> result = arbol.remove(temp);
        return result.value;
    }

    V getValue(K key) {
        Pair<K, V> temp(key, V());
        Pair<K, V> result = arbol.find(temp);
        return result.value;
    }

    void setValue(K key, V value) {
        Pair<K, V> temp(key, V());
        Pair<K, V> pair = arbol.find(temp);
        arbol.remove(temp);
        pair.value = value;
        arbol.insert(pair);
    }

    bool contains(K key) {
        Pair<K, V> temp(key, V());
        return arbol.contains(temp);
    }

    bool isEmpty() {
        return arbol.getSize() == 0;
    }

    void clear() {
        arbol.clear();
    }

    List<K>* getKeys() {
        List<K>* keys = new DLinkedList<K>();
        List<Pair<K, V>>* pairs = arbol.getElements();
        pairs->goToStart();
        while (!pairs->atEnd()) {
            keys->append(pairs->getElement().key);
            pairs->next();
        }
        delete pairs;
        return keys;
    }

    List<V>* getValues() {
        List<V>* values = new DLinkedList<V>();
        List<Pair<K, V>>* pairs = arbol.getElements();
        pairs->goToStart();
        while (!pairs->atEnd()) {
            values->append(pairs->getElement().value);
            pairs->next();
        }
        delete pairs;
        return values;
    }

    int getSize() {
        return arbol.getSize();
    }

    void update(Dictionary<K, V>* D) {
        List<K>* keys = D->getKeys();
        keys->goToStart();
        while (!keys->atEnd()) {
            K key = keys->getElement();
            V value = D->getValue(key);
            if (contains(key))
                setValue(key, value);
            else
                insert(key, value);
            keys->next();
        }
        delete keys;
    }

    void zip(List<K>* keys,
        List<V>* values) {
        keys->goToStart();
        values->goToStart();
        while (!keys->atEnd() && !values->atEnd()) {
            K key = keys->getElement();
            V value = values->getElement();
            if (contains(key))
                setValue(key, value);
            else
                insert(key, value);
            keys->next();
            values->next();
        }
    }

    void print() {
        arbol.print();
    }
};