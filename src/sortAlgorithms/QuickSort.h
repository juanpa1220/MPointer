//
// Created by Juan Pablo Martínez Brenes on 10/8/18.
//

#ifndef MPOINTER_QUICKSORT_H
#define MPOINTER_QUICKSORT_H

#include "../dataStructures/DoublyLinkedList.h"


class QuickSort {
private:
    DoublyLinkedList<MPointer<int>> doublyLinkedList;
    void sortListAux(DoublyLinkedList<MPointer<int>> lista, int low, int high);
    int partition(DoublyLinkedList<MPointer<int>> lista, int low, int high);

public:
    QuickSort(DoublyLinkedList<MPointer<int>> list);

    void sortList();

    void displayList();
};


#endif //MPOINTER_QUICKSORT_H
