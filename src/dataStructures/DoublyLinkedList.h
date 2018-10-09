//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#ifndef MPOINTER_DOUBLYLINKEDLIST_H
#define MPOINTER_DOUBLYLINKEDLIST_H

#include "../MPointer.h"
#include <iostream>

template<class T>
struct nodoD {
    T data;
    nodoD *next;
    nodoD *prev;
};

template<class T>
class DoublyLinkedList {

    int lenght;
    nodoD<T> *head;

public :
    DoublyLinkedList() {
        head = nullptr;
        lenght = 0;
    }

    void add(T p_data) {
        auto *nuevo = new nodoD<T>;
        nuevo->data = p_data;
        if (this->head == nullptr) {
            head = nuevo;
        } else {
            nodoD<T> *temp;
            temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = nuevo;
            nuevo->prev = temp;
        }
        this->lenght++;
    }

    T getNodeData(int pos) {
        auto *temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void setNodeData(int pos, T newData) {
        auto temp = head;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        temp->data = newData;
    }

    int getLenght() {
        return this->lenght;
    }
};

#endif //MPOINTER_DOUBLYLINKEDLIST_H
