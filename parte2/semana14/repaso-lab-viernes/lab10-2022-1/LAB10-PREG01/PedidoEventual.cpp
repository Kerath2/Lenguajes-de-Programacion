/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:50 PM
 */

#include "PedidoEventual.h"


PedidoEventual::PedidoEventual() {
    flete = 0;
}

PedidoEventual::PedidoEventual(const PedidoEventual& orig) {
}

PedidoEventual::~PedidoEventual() {
}

void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}

void PedidoEventual::lee(ifstream& arch, int codigo, double descuento, double flete){
    char c;
    
    arch >> this->flete >> c;
    Pedido::lee(arch, codigo, 0, this->flete);

}

