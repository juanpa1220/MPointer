//
// Created by Juan Pablo Martínez Brenes on 10/9/18.
//

#include "BubbleSort.h"

BubbleSort::BubbleSort(DoublyLinkedList<MPointer<int>> list) {
    lista = list;
    size = lista.getLenght();
}

void BubbleSort::sortList() {
    MPointer<int> tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (&lista.getNodeData(j) > &lista.getNodeData(j + 1)) {
                tmp = lista.getNodeData(j);
                lista.setNodeData(j, lista.getNodeData(j + 1));
                lista.setNodeData(j + 1, tmp);
            }
        }
    }
}

void BubbleSort::displayList() {
    for (int i = 0; i < lista.getLenght(); ++i)
        std::cout << &lista.getNodeData(i) << " " << std::flush;
    std::cout << std::endl;
}
