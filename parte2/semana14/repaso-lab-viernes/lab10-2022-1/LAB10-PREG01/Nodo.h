/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: gkerath
 *
 * Created on June 27, 2023, 11:52 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"
#include "Lista.h"
class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    
    friend class Lista;
private:
    Pedido * ped;
    Nodo * sig;
    Nodo * ant;
};

#endif /* NODO_H */

