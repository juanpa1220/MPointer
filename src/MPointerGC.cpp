//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#include "MPointerGC.h"

//Initialize pointer to 0, that it can be initialized in first call to getInstance

template<class T>
MPointerGC<T> *MPointerGC<T>::instance = 0;


template<class T>
MPointerGC<T>::MPointerGC() {
    linkedList = new LinkedList<T>;
}

template<class T>
MPointerGC<T> *MPointerGC<T>::getInstance() {
    if (!instance)
        instance = new MPointerGC<T>;
    return instance;
}

template<class T>
uint64_t MPointerGC<T>::addMPointer(T *data) {
    auto id = reinterpret_cast<uint64_t>(data);
    linkedList->insertarNodo(data, id);
    linkedList->aumentarRef(id);

    return id;
}

template<class T>
void MPointerGC<T>::reduceRef(uint64_t id) {
    linkedList->disminuirRef(id);
}

template<class T>
void MPointerGC<T>::updateList() {
    for (int i = 0; i < linkedList->getLenght(); ++i) {
        if (linkedList->getNodo(i).cantRef == 0) {
            linkedList->eliminarNodo(i);
        }
    }
}



