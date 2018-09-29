//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#include "MPointerGC.h"

//Initialize pointer to 0, that it can be initialized in first call to getInstance
MPointerGC *MPointerGC::instance = 0;

MPointerGC::MPointerGC() {
    linkedList = new LinkedList();
}

MPointerGC *MPointerGC::getInstance() {
    if (!instance)
        instance = new MPointerGC;
    return instance;
}

void MPointerGC::test(int data) {
    linkedList->createnode(data);
}

//void MPointerGC::update() {
//
//}



