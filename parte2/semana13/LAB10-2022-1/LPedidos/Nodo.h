/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: cueva.r
 *
 * Created on 21 de junio de 2023, 10:28 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"


class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    int cmp(Nodo &); // Se pasa por referencia en caso tenga un atributo cadena
    friend class Lista;
private:
    Pedido *ped;
    Nodo *sig;
    Nodo *ant;
};

#endif /* NODO_H */

