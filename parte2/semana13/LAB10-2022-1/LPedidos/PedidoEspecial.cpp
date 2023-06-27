/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 07:59 PM
 */

#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento=0;
}

PedidoEspecial::PedidoEspecial(const PedidoEspecial& orig) {
}

PedidoEspecial::~PedidoEspecial() {
}

void PedidoEspecial::lee(int cod, ifstream&arch){
    
    arch.get();
    arch >> descuento;
    Pedido::lee(cod,arch);
  
}
void PedidoEspecial::imprime(ofstream& arch,double a,double b){
    Pedido::imprime(arch,descuento,0);
    arch << "Descuento: " << descuento << endl;

}