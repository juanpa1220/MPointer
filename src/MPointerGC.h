//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#ifndef MPOINTER_MPOINTERGC_H
#define MPOINTER_MPOINTERGC_H

#include "dataStructures/LinkedList.cpp"

class MPointerGC {
    static MPointerGC *instance;
    LinkedList *linkedList;

    // Private constructor
    MPointerGC();

public:
    static MPointerGC *getInstance();

    void test(int data);

//    void update();
};

#endif //MPOINTER_MPOINTERGC_H
