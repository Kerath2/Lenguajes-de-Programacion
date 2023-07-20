/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Promociones.h
 * Author: gkerath
 *
 * Created on June 27, 2023, 11:57 PM
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H

#include "Lista.h"


class Promociones {
public:
    Promociones();
    Promociones(const Promociones& orig);
    virtual ~Promociones();
    void leePedido();
private:
    Lista lpedidos;
};

#endif /* PROMOCIONES_H */

