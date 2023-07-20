/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:53 PM
 */

#include "Lista.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"
Lista::Lista() {
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::insertaNodo(ifstream& arch){
    //Creamos el nodo
    Nodo * nuevoNodo= new Nodo;
    leerDatos(arch,nuevoNodo);
    if(arch.eof()) return;
    
}

void Lista::leerDatos(ifstream& arch, Nodo*& nuevoNodo){
     int codigo;    
    arch >> codigo;
    if(arch.eof()) return;
    arch.get(); // coma
    
    if(codigo < 400000) nuevoNodo->ped = new PedidoEspecial;
    if(codigo >= 400000 && codigo < 600000) nuevoNodo->ped = new PedidoUsual;
    if(codigo >= 600000) nuevoNodo->ped = new PedidoEventual;
    
    //arch, cod , descuento y flete
    nuevoNodo->ped->lee(arch,codigo,0,0);
}

