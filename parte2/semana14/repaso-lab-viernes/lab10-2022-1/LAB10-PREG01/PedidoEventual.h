/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEventual.h
 * Author: gkerath
 *
 * Created on June 27, 2023, 11:50 PM
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H

#include "Pedido.h"
#include <iostream>
#include <fstream>
using namespace std;

class PedidoEventual : public Pedido{
public:
    PedidoEventual();
    PedidoEventual(const PedidoEventual& orig);
    virtual ~PedidoEventual();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &arch,int codigo,double descuento,double flete);
    
private:
    double flete;
};

#endif /* PEDIDOEVENTUAL_H */

