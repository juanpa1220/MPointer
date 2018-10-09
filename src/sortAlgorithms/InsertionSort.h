//
// Created by Juan Pablo Martínez Brenes on 10/3/18.
//

#ifndef MPOINTER_INSERTIONSORT_H
#define MPOINTER_INSERTIONSORT_H

#include "../dataStructures/DoublyLinkedList.h"

class InsertionSort {
private:
    DoublyLinkedList<MPointer<int>> doublyLinkedList;
public:
    InsertionSort(DoublyLinkedList<MPointer<int>> list);

    void sortList();

    void displayList();
};


#endif //MPOINTER_INSERTIONSORT_H
