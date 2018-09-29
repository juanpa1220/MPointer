//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//
#include <iostream>
#include "MPointer.h"

// constructor implementation
template<class T>
MPointer<T>::MPointer() {
    data = (T *) malloc(sizeof(T));
    gcInstance = MPointerGC::getInstance();
    gcInstance->test(123);
}

// New method call the constructor
template<class T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();
}

// operators implementations to the MPointer class
// ..............................................

// * operator
template<class T>
T &MPointer<T>::operator*() {
    return *this->data;
}

// = operator to not MPointers objects
template<class T>
T &MPointer<T>::operator=(const T &_data) {
    if (typeid(*this->data).name() == typeid(_data).name()) {
        *this->data = _data;
    }
    return *this->data;
}

// = operator to MPointers objects
template<class T>
MPointer<T> &MPointer<T>::operator=(const MPointer<T> &_pointer) {
    if (typeid(this->data).name() == typeid(_pointer.data).name()) {
        this->data = _pointer.data;
    }
    return *this;
}

// & operator
template<class T>
T &MPointer<T>::operator&() {
    return *this->data;
}
// ..........................................

// destroyer implementation
template<class T>
void MPointer<T>::destroyer() {
    free(*this);
}
