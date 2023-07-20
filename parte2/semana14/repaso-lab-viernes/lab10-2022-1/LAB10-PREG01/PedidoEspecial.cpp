/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:46 PM
 */

#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento = 0; 
}

PedidoEspecial::PedidoEspecial(const PedidoEspecial& orig) {
}

PedidoEspecial::~PedidoEspecial() {
}

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(ifstream& arch, int codigo, double descuento, double flete){
    char c;    
    arch >> this->descuento >> c;
    Pedido::lee(arch, codigo, this->descuento, 0);

}

