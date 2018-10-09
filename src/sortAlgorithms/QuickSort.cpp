//
// Created by Juan Pablo Martínez Brenes on 10/8/18.
//

#include "QuickSort.h"

QuickSort::QuickSort(DoublyLinkedList<MPointer<int>> list) {
    doublyLinkedList = list;
}

void QuickSort::sortList() {
    sortListAux(doublyLinkedList, 0, doublyLinkedList.getLenght() - 1);

}

void QuickSort::sortListAux(DoublyLinkedList<MPointer<int>> lista, int low, int high) {
    if (low < high) {
        int partIndx = partition(lista, low, high);

        sortListAux(lista, low, partIndx - 1);
        sortListAux(lista, partIndx + 1, high);
    }
}

int QuickSort::partition(DoublyLinkedList<MPointer<int>> lista, int low, int high) {
    MPointer<int> pivot = lista.getNodeData(high);
    int i = (low - 1);

    MPointer<int> tmp;
    for (int j = low; j < high; j++)
    {
        if (&lista.getNodeData(j) <= &pivot)
        {
            i++;
            tmp = lista.getNodeData(i);
            lista.setNodeData(i, lista.getNodeData(j));
            lista.setNodeData(j, tmp);
        }
    }
    tmp = lista.getNodeData(i+1);
    lista.setNodeData(i + 1, lista.getNodeData(high));
    lista.setNodeData(high, tmp);
    return (i + 1);
}

void QuickSort::displayList() {
    for (int i = 0; i < doublyLinkedList.getLenght(); ++i)
        std::cout << &doublyLinkedList.getNodeData(i) << " " << std::flush;
    std::cout << std::endl;
}
