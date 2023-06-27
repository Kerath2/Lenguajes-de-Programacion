/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEspecial.h
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 07:59 PM
 */
#include <fstream>
#include "Pedido.h"

using namespace std;

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

class PedidoEspecial: public Pedido {
public:
    PedidoEspecial();
    PedidoEspecial(const PedidoEspecial& orig);
    virtual ~PedidoEspecial();
    void lee(int,ifstream &);
    void imprime(ofstream &,double,double);
    void actualiza(){};
private:
    double descuento;
};

#endif /* PEDIDOVIP_H */

