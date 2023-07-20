/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEspecial.h
 * Author: gkerath
 *
 * Created on June 27, 2023, 11:46 PM
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedido.h"
#include <iostream>
#include <fstream>
using namespace std;

class PedidoEspecial : public Pedido {
public:
    PedidoEspecial();
    PedidoEspecial(const PedidoEspecial& orig);
    virtual ~PedidoEspecial();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch,int codigo,double descuento,double flete);
private:
    double descuento; 
};

#endif /* PEDIDOESPECIAL_H */

