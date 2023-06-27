/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 08:00 PM
 */

#include "PedidoEventual.h"

PedidoEventual::PedidoEventual() {
}

PedidoEventual::PedidoEventual(const PedidoEventual& orig) {
}

PedidoEventual::~PedidoEventual() {
}

void PedidoEventual::lee(int cod, ifstream &arch){
    
    arch.get();
    arch >> flete;
    Pedido::lee(cod,arch);
}

void PedidoEventual::imprime(ofstream& arch,double a, double b){
    Pedido::imprime(arch,0,flete);
    arch << "Flete : " << flete<< endl;;
    
}

void PedidoEventual::actualiza(){
    flete=0;    
}
