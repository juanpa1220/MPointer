//
// Created by Juan Pablo Martínez Brenes on 9/19/18.
//

#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H


#include <iostream>
#include <string>

using namespace std;

/**
 * Estructura para la lista simple del Garbage Collector
 * @tparam T tipo de dato
 */
template<class T>
struct node {
    T *data;
    int cantRef;
    uint64_t ID;
    node<T> *siguiente;
};

/**
 * Lista Genérica adaptada para el Garbage Collector
 * @tparam T
 */
template<class T>
class LinkedList {

private:
    //Atributos
    node<T> *first;
    int lenght = 0;
    //Fin de Atributos

public:

    /**
     * Constructor
     */
    LinkedList() {
        first = nullptr;
    }

    /**
     * Obtiene el nodo en la posición dada
     */
    node<T> getNodo(int pos) {
        int i = 0;
        node<T> *aux = first;
        while (i < pos) {
            aux = aux->siguiente;
            i++;
        }
        return *aux;
    };

    /**
     * Inserta un nuevo nodo a la lista
     * @param dato dirección de memoria a guardar como dato
     * @param ID ID asignado a este dato
     */
    void insertarNodo(T *dato, uint64_t ID) {
        auto *newNode = new node<T>();
        newNode->data = dato;
        if (this->first == nullptr) {
            newNode->ID = ID;
            first = newNode;
        } else {
            node<T> *aux;
            aux = this->first;
            while (aux->siguiente) {
                aux = aux->siguiente;
            }
            newNode->ID = ID;
            aux->siguiente = newNode;
        }
//        newNode->cantRef++;
        this->lenght++;
    };

    /**
     * Obtiene el dato en la posición dada
     * @param pos posición donde se encuentra el dato
     * @return dato
     */
    T *getData(int pos) {
        int i = 0;
        node<T> *aux = first;
        while (i < pos) {
            aux = aux->siguiente;
            i++;
        }
        return aux->data;
    };

    /**
     * Obtiene la cantidad de referencias que tiene un dato
     * @param id ID del dato
     * @return cantidad de referencias
     */
    int getCantRefPorID(uint64_t id) {
        node<T> *aux = first;
        for (int i = 0; i < this->lenght; i++) {
            if (id == this->getNodo(i).ID) {
                return this->getNodo(i).cantRef;
            }
        }
    }

    /**
     * Obtiene el largo de la lista
     * @return
     */
    int getLenght() const {
        return lenght;
    }

    /**
     * Retorna el ID de la posición dada
     * @param pos posición del que se necesita el ID
     * @return ID
     */
    uint64_t idNecesitado(int pos) {
        node<T> *aux = this->first;
        for (int i = 0; i < pos; i++) {
            aux = aux->siguiente;
        }
        return aux->ID;
    }

    /**
     * Elimina el nodo de la posición dada
     * @param pos posicion del nodo a eliminar
     */
    void eliminarNodo(int pos) {
        node<T> *aux = first;
        if (pos == 0) {
            first = aux->siguiente;
            free(aux);
        } else {
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->siguiente;
            }
            free(aux->siguiente);
            aux->siguiente = aux->siguiente->siguiente;
        }
        this->lenght--;
    }

    /**
     * Elimina el nodo por el ID
     * @param id ID del nodo a eliminar
     */
    void eliminarNodo(uint64_t id) {
        for (int i = 0; i < this->lenght; i++) {
            if (this->getNodo(i).ID == id) {
                eliminarNodo(i);
                break;
            }
        }
    }

    /**
     * Disminuye la cantidad de referencias del nodo con el ID solicitado
     * @param id ID del nodo a disminuir referencias
     */
    void disminuirRef(uint64_t id) {
        node<T> *aux = first;
        for (int i = 0; i < this->lenght; i++) {
            if (aux->ID == id) {
                aux->cantRef--;
                break;
            }
            aux = aux->siguiente;
        }
    }

    /**
     * Aumenta la cantidad de referencias del nodo con el ID solicitado
     * @param id ID del nodo a aumentar referencias
     */
    void aumentarRef(uint64_t id) {
        node<T> *aux = first;
        for (int i = 0; i < this->lenght; i++) {
            if (aux->ID == id) {
                aux->cantRef++;
                break;
            }
            aux = aux->siguiente;
        }
    }
};


#endif //MPOINTER_LINKEDLIST_H
