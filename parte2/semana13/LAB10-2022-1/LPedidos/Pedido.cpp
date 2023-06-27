/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: cueva
 * 
 * Created on 6 de junio de 2022, 05:41 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Pedido.h"

using namespace std;


Pedido::Pedido() {
    codigo=0;
    nombre=NULL;
    cantidad=0;
    dni=0;
    fecha=0;
    total=0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}


void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::SetNombre(char* cad) { //modificado
    if(nombre!=NULL) delete[]nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
void Pedido::GetNombre(char *nom) const {
    strcpy(nom,nombre);
}

void Pedido::SetTotal(double precio) {
    this->total = precio;
}

double Pedido::GetTotal() const {
    return total;
}

/*
118050,10,PAPAYA,8,8,79475585,16/12/2019
118050,10,PAPAYA,5,5,79475585,30/04/2020
118050,10,PAPAYA,11,11,81114108,09/03/2020
 */
void Pedido::lee(int cod,ifstream& arch){
    char nombre[100],c;
    int  dni,stock,fecha,dd,mm,aa;
    double total;
    
        arch.get();
        SetCodigo(cod);
        arch.getline(nombre,100,',');
        SetNombre(nombre);
        arch >> stock;
        arch.get();
        SetCantidad(stock);
        arch >> total;
        SetTotal(total);
        arch.get();
        arch >> dni;
        SetDni(dni);
        arch.get();
        arch >> dd >>c>>mm>>c>>aa;
        arch.get();
        fecha=aa*10000+mm*100+dd;
        SetFecha(fecha);
 }


void Pedido::imprime(ofstream &arch,double desc,double fle){
    char cad[100];
    double monto;
    
    arch<<endl<<left <<setw(10)<<GetFecha()<<endl;
    GetNombre(cad);
    arch <<setw(10)<<codigo<<setw(50)<< cad <<endl;
    arch<<"DNI: "<< dni << endl;
    arch <<"Monto Total: "<<right<<setprecision(2)<<fixed;
    monto = GetTotal()+(GetTotal()*fle/100)-(GetTotal()*desc/100);
    arch <<setw(10)<< monto <<endl;
}