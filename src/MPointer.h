//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include "MPointerGC.cpp"
#include "client/MCliente.h"

template<class T>
class MPointer {
private:
    T *data;
    uint64_t id;
    MPointerGC<MPointer<T>> *gcInstance;
    MCliente *cliente;
    JSONMakerClient jsonMaker;
    std::string IDServer;
public:
    // basic constructor
    MPointer();

    // new method
    static MPointer<T> New();

    // operators to overwrite
    T &operator*();

    T operator&();

    T operator=(const T &_data);

    MPointer<T> &operator=(const MPointer<T> &_pointer);


    // destroyer to free memory
    void destroyer();


    static void MPointer_init(std::string IP, int puerto);
};


#endif //MPOINTER_MPOINTER_H
