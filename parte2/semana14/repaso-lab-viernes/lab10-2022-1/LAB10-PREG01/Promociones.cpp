/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Promociones.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:57 PM
 */

#include "Promociones.h"
#include <iostream>
#include <fstream>
using namespace std;

Promociones::Promociones() {
}

Promociones::Promociones(const Promociones& orig) {
}

Promociones::~Promociones() {
}

void Promociones::leePedido(){
    ifstream arch("pedidos5.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir los pedidos5";
        exit(1);
    }
    while(1){
        this->lpedidos.insertaNodo(arch);
        if(arch.eof()) break;
    }
}

