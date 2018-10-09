//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#ifndef MPOINTER_MPOINTERGC_H
#define MPOINTER_MPOINTERGC_H

#include "dataStructures/LinkedList.h"

template <class T>
class MPointerGC {
private:
    static MPointerGC<T> *instance;
    LinkedList<T> *linkedList;

    // Private constructor
    MPointerGC();

public:
    static MPointerGC *getInstance();

    uint64_t addMPointer(T *data);

    void reduceRef(uint64_t id);

    void updateList();

};

#endif //MPOINTER_MPOINTERGC_H
