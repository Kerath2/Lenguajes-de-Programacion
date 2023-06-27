/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 08:00 PM
 */

#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
    descuento=0;
    flete=0;
}

PedidoUsual::PedidoUsual(const PedidoUsual& orig) {
}

PedidoUsual::~PedidoUsual() {
}

void PedidoUsual::lee(int cod, ifstream &arch ){
      arch.get();
      arch >> descuento;
      arch.get();
      arch >> flete;
      Pedido::lee(cod,arch);
}
void PedidoUsual::imprime(ofstream&arch,double a,double b){
    Pedido::imprime(arch,descuento,flete);
    arch << "Descuento: " << descuento<< endl;;
    arch << "Flete : " << flete << endl;;
    
}

void PedidoUsual::actualiza(){
    flete=0;
}