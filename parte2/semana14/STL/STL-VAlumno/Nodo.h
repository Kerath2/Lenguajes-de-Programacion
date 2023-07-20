/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: cueva
 *
 * Created on 18 de noviembre de 2022, 08:28 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
#include "Alumno.h"

using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void leenodo(ifstream &);
    void imprimenodo(ofstream &);
private:
    Alumno dalumno;
};

#endif /* NODO_H */

