#pragma once
#include <iostream>
#include <stdexcept>
#include "List.h"
#include "DNode.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class DLinkedList : public List<E> {
private:
    DNode<E>* head;
    DNode<E>* tail;
    DNode<E>* current;
    int size;

public:
    DLinkedList() {
        head = new DNode<E>(nullptr, nullptr);
        tail = new DNode<E>(nullptr, head);
        head->next = tail;
        current = head;
        size = 0;
    }

    ~DLinkedList() {
        clear();
        delete head;
        delete tail;
    }

    void insert(E element) {
        DNode<E>* node = new DNode<E>(element, current->next, current);
        current->next->previous = node;
        current->next = node;
        size++;
    }

    void append(E element) {
        DNode<E>* node = new DNode<E>(element, tail, tail->previous);
        tail->previous->next = node;
        tail->previous = node;
        size++;
    }

    void setElement(E element) {
        if (current->next == tail)
            throw runtime_error("No current element.");
        current->next->element = element;
    }

    E getElement() {
        if (current->next == tail)
            throw runtime_error("No current element.");
        return current->next->element;
    }

    E remove() {
        if (current->next == tail)
            throw runtime_error("No current element.");
        DNode<E>* temp = current->next;
        E result = temp->element;
        current->next = temp->next;
        temp->next->previous = current;
        delete temp;
        size--;
        return result;
    }

    void clear() {
        current = head;
        while (head->next != tail) {
            DNode<E>* temp = head->next;
            head->next = temp->next;
            temp->next->previous = head;
            delete temp;
        }
        tail->previous = head;
        current = head;
        size = 0;
    }

    void goToStart() {
        current = head;
    }

    void goToEnd() {
        if (size == 0)
            current = head;
        else
            current = tail->previous;
    }

    void goToPos(int pos) {
        if (pos < 0 || pos > size)
            throw runtime_error("Index out of bounds.");
        current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
    }

    void next() {
        if (current->next != tail)
            current = current->next;
    }

    void previous() {
        if (current != head)
            current = current->previous;
    }

    bool atStart() {
        return current == head;
    }

    bool atEnd() {
        return current->next == tail;
    }

    int getPos() {
        DNode<E>* temp = head;
        int pos = 0;
        while (temp != current) {
            temp = temp->next;
            pos++;
        }
        return pos;
    }

    int getSize() {
        return size;
    }

    void print() {
        cout << "[ ";
        DNode<E>* temp = head->next;
        while (temp != tail) {
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};