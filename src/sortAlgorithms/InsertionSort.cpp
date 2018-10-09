//
// Created by Juan Pablo Martínez Brenes on 10/3/18.
//

#include "InsertionSort.h"

InsertionSort::InsertionSort(DoublyLinkedList<MPointer<int>> list) {
    doublyLinkedList = list;
}

void InsertionSort::sortList() {
    for (int i = 1; i < doublyLinkedList.getLenght(); ++i) {
        int j = i - 1;
        int key = &doublyLinkedList.getNodeData(i);

        while (j >= 0 && &doublyLinkedList.getNodeData(j) > key) {
            doublyLinkedList.getNodeData(j + 1) = &doublyLinkedList.getNodeData(j);
            --j;
        }
        doublyLinkedList.getNodeData(j + 1) = key;
    }
}

void InsertionSort::displayList() {
    for (int i = 0; i < doublyLinkedList.getLenght(); ++i)
        std::cout << &doublyLinkedList.getNodeData(i) << " " << std::flush;
    std::cout << std::endl;
}


