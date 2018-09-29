//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include "MPointerGC.cpp"

template<class T>
class MPointer {
private:
    T *data;
    int id;
    MPointerGC *gcInstance;
public:
    // basic constructor
    MPointer();

    // new method
    static MPointer<T> New();

    // operators to overwrite
    T &operator*();

    T &operator&();

    T &operator=(const T &_data);

    MPointer<T> &operator=(const MPointer<T> &_pointer);


    // destroyer to free memory
    void destroyer();
};


#endif //MPOINTER_MPOINTER_H
