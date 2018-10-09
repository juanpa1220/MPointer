#include <iostream>
#include "src/MPointer.cpp"
#include "src/dataStructures/DoublyLinkedList.h"
#include "src/sortAlgorithms/InsertionSort.cpp"
#include "src/sortAlgorithms/QuickSort.cpp"
#include "src/sortAlgorithms/BubbleSort.cpp"


int main() {
    // ................................... test MPointer ................................... //

    std::cout << ".......Puebas a MPointer.......\n" << std::endl;

    // create MPointers to test them
    MPointer<int> mPointer1 = MPointer<int>::New();
    MPointer<int> mPointer2 = MPointer<int>::New();

    // assigns values to mPointer1 and print that value
    mPointer1 = 5;
    int valor = &mPointer1;
    std::cout << "Asigna un valor al mPointer1\nValor mPointer1: " << valor << std::endl;

    //
    mPointer2 = mPointer1;

    int valor2 = &mPointer2;
    std::cout << "\nAsigna mPointer1 al mPointer2\nvalor mPointer2: " << valor2 << std::endl;

    std::cout << "\nlibera mPointer1" << std::endl;
    mPointer1.destroyer();

    std::cout << "\nmPointer2 sigue almacenado su valor\nValor mPointer2: " << valor2 << std::endl;

    // ............................... test sort algorithms ............................... //

    std::cout << "\n\n.......Puebas a los algoritmos de ordenamiento.......\n" << std::endl;

    // create mPointers with integers inside
    MPointer<int> mPointer3 = MPointer<int>::New();
    MPointer<int> mPointer4 = MPointer<int>::New();
    MPointer<int> mPointer5 = MPointer<int>::New();
    MPointer<int> mPointer6 = MPointer<int>::New();
    MPointer<int> mPointer7 = MPointer<int>::New();
    MPointer<int> mPointer8 = MPointer<int>::New();
    MPointer<int> mPointer9 = MPointer<int>::New();
    MPointer<int> mPointer10 = MPointer<int>::New();
    MPointer<int> mPointer11 = MPointer<int>::New();
    MPointer<int> mPointer12 = MPointer<int>::New();
    MPointer<int> mPointer13 = MPointer<int>::New();
    MPointer<int> mPointer14 = MPointer<int>::New();
    MPointer<int> mPointer15 = MPointer<int>::New();
    MPointer<int> mPointer16 = MPointer<int>::New();
    MPointer<int> mPointer17 = MPointer<int>::New();
    mPointer3 = 87;
    mPointer4 = 23;
    mPointer5 = 100;
    mPointer6 = -1;
    mPointer7 = 76;
    mPointer8 = 34;
    mPointer9 = 2;
    mPointer10 = 435;
    mPointer11 = -76;
    mPointer12 = 51;
    mPointer13 = 43;
    mPointer14 = 14;
    mPointer15 = 241;
    mPointer16 = -23;
    mPointer17 = 74;

    // create a doubly linked list and add MPointers to them
    DoublyLinkedList<MPointer<int>> doublyLinkedList;
    DoublyLinkedList<MPointer<int>> doublyLinkedList2;
    DoublyLinkedList<MPointer<int>> doublyLinkedList3;
    doublyLinkedList.add(mPointer3);
    doublyLinkedList.add(mPointer4);
    doublyLinkedList.add(mPointer5);
    doublyLinkedList.add(mPointer6);
    doublyLinkedList.add(mPointer7);
    doublyLinkedList2.add(mPointer8);
    doublyLinkedList2.add(mPointer9);
    doublyLinkedList2.add(mPointer10);
    doublyLinkedList2.add(mPointer11);
    doublyLinkedList2.add(mPointer12);
    doublyLinkedList3.add(mPointer13);
    doublyLinkedList3.add(mPointer14);
    doublyLinkedList3.add(mPointer15);
    doublyLinkedList3.add(mPointer16);
    doublyLinkedList3.add(mPointer17);

    InsertionSort insertionSort(doublyLinkedList);
    QuickSort quickSort(doublyLinkedList2);
    BubbleSort bubbleSort(doublyLinkedList3);

    // display doubly linked list without sort
    std::cout << "Lista doble con MPointers sin insertion sort" << std::endl;
    insertionSort.displayList();

    // sort the list with insertion sort algorithm and display the list
    std::cout << "Lista doble con MPointers con insertion sort" << std::endl;
    insertionSort.sortList();
    insertionSort.displayList();

    // display doubly linked list without sort
    std::cout << "\nLista doble con MPointers sin quick sort" << std::endl;
    quickSort.displayList();

    // sort the list with insertion sort algorithm and display the list
    std::cout << "Lista doble con MPointers con quick sort" << std::endl;
    quickSort.sortList();
    quickSort.displayList();

    // display doubly linked list without sort
    std::cout << "\nLista doble con MPointers sin bubble sort" << std::endl;
    bubbleSort.displayList();

    // sort the list with insertion sort algorithm and display the list
    std::cout << "Lista doble con MPointers con bubble sort" << std::endl;
    bubbleSort.sortList();
    bubbleSort.displayList();


    return 0;
}