/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: gkerath
 *
 * Created on June 27, 2023, 11:53 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>
#include <fstream>
using namespace std;

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void insertaNodo(ifstream &arch);
    void leerDatos(ifstream &arch,class Nodo *&nuevoNodo);
private:
    class Nodo * lini;
    class Nodo * lfin;
    
};

#endif /* LISTA_H */

