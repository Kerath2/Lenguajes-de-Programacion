/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.h
 * Author: cueva
 *
 * Created on 9 de julio de 2022, 08:02 PM
 */

#include <vector>
#include "Lista.h"
#include "NProductos.h"

#ifndef PROGRAMA_H
#define PROGRAMA_H

class Programa {
public:
    Programa();
    Programa(const Programa& orig);
    virtual ~Programa();
  void carga();
  void muestra();
private:
  vector <NProductos> vproductos;
  void cargaproductos();
};

#endif /* PROGRAMA_H */

