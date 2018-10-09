//
// Created by Juan Pablo Martínez Brenes on 10/9/18.
//

#ifndef MPOINTER_BUBBLESORT_H
#define MPOINTER_BUBBLESORT_H

#include "../dataStructures/DoublyLinkedList.h"

class BubbleSort {
private:
    DoublyLinkedList<MPointer<int>> lista;
    int size;



public:
    BubbleSort(DoublyLinkedList<MPointer<int>> list);

    void sortList();

    void displayList();
};


#endif //MPOINTER_BUBBLESORT_H
