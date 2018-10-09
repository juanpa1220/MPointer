//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//
#include <iostream>
#include "MPointer.h"

// constructor implementation
template<class T>
MPointer<T>::MPointer() {
    if (MCliente::esActivo()) {
        cliente = MCliente::getInstance();
        rapidjson::Document doc = cliente->conectar(jsonMaker.solicitarMemoria(typeid(T).name()));
        this->IDServer = doc["ID"].GetString();

    } else {
        data = (T *) malloc(sizeof(T));
        gcInstance = MPointerGC<MPointer<T>>::getInstance();
        id = gcInstance->addMPointer(this);
    }
}

// New method call the constructor
template<class T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();
}

// operators implementations to the MPointer class
// ..............................................

// * operator
template<class T>
T &MPointer<T>::operator*() {
    return *this->data;
}

// = operator to not MPointers objects
template<class T>
T MPointer<T>::operator=(const T &_data) {
    if (MCliente::esActivo()) {
        cliente->conectar(jsonMaker.solicitarAsignacion(IDServer, _data));
        return _data;
    }
    *this->data = _data;
    return *this->data;
}

// = operator to MPointers objects
template<class T>
MPointer<T> &MPointer<T>::operator=(const MPointer<T> &_pointer) {
    if (MCliente::esActivo()) {
        this->IDServer = _pointer.IDServer;
    }
    this->data = _pointer.data;
    return *this;
}

// & operator
template<class T>
T MPointer<T>::operator&() {
    if (MCliente::esActivo()) {
        rapidjson::Document doc = cliente->conectar(jsonMaker.solicitarValor(IDServer));
        if (typeid(T).name() == typeid(int).name()) {
            return doc["dato"].GetInt();
        }
    } else {
        return *this->data;
    }
}
// ..........................................

// destroyer implementation
template<class T>
void MPointer<T>::destroyer() {
    gcInstance->reduceRef(this->id);
    gcInstance->updateList();
    free(this->data);
}

template<class T>
void MPointer<T>::MPointer_init(std::string IP, int puerto) {
    MCliente::getInstance(IP, puerto);
}
