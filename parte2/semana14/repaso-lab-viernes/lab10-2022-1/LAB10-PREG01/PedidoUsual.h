/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoUsual.h
 * Author: gkerath
 *
 * Created on June 27, 2023, 11:48 PM
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H

#include "Pedido.h"
#include <iostream>
#include <fstream>
using namespace std;

class PedidoUsual : public Pedido{
public:
    PedidoUsual();
    PedidoUsual(const PedidoUsual& orig);
    virtual ~PedidoUsual();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch,int codigo,double descuento,double flete);
private:
    double descuento;
    double flete;
    
};

#endif /* PEDIDOUSUAL_H */

