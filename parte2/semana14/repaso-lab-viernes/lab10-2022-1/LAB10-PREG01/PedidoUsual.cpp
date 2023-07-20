/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:48 PM
 */

#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
     descuento = 0;
     flete = 0;
}

PedidoUsual::PedidoUsual(const PedidoUsual& orig) {
}

PedidoUsual::~PedidoUsual() {
}

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::lee(ifstream& arch, int codigo, double descuento, double flete){
    char c;
    
    arch >> this->descuento >> c >> this->flete >> c;
    Pedido::lee(arch, codigo, this->descuento, this->flete);

}