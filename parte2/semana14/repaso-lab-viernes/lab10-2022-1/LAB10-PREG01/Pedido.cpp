/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:37 PM
 */

#include "Pedido.h"
#include <iostream>
#include <cstring>

Pedido::Pedido() {
    codigo = 0;
    nombre = nullptr;
    cantidad = 0;
    dni = 0;
    fecha = 0;
    total = 0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(char* cad) {
  if(nombre != nullptr) delete nombre;
  nombre = new char[strlen(cad)+1];
  strcpy(nombre,cad);
}

void Pedido::GetNombre(char *cad) const {
  strcpy(cad,nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream& arch, int codigo, double descuento, double flete){
    int cant, dniCliente, dd, mm, aa, fecha;
    char nombre[200], c;
    double monto;
    
    arch.getline(nombre, 200, ',');
    arch >> cant >> c >> monto >> c >> dniCliente >> c >> dd >> c >> mm >> c >> aa;
    fecha = dd + mm*100 + aa*10000;
    
    double montoDescuento = monto*(descuento/100);
    double montoFlete = monto*(flete/100);
    
    double montoactualizado = monto - montoDescuento + montoFlete;
    
    
    this->SetCodigo(codigo);
    this->SetNombre(nombre);
    this->SetCantidad(cant);
    this->SetDni(dniCliente);
    this->SetFecha(fecha);
    this->SetTotal(montoactualizado);

}