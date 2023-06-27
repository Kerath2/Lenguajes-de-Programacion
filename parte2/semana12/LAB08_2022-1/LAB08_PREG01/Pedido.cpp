/*

 */

#include "Pedido.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
Pedido::Pedido() {
    codigo = 0;
    cantidad = 0;
    dni = 0;
    fecha = 0;
    total = 0;
    obs = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetObs(char* cad) {
    if(obs!=nullptr) delete obs;
    obs = new char[strlen(cad)+1];
    strcpy(obs,cad);
}

void Pedido::GetObs(char *cad) const {
    strcpy(cad,obs);
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

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::leePedido(ifstream& arch){
    int codigo, cant, dni,fecha;
    int dd, mm ,aa;
    char c;
    arch >> codigo;
    if(arch.eof()) return;
    arch >>  c >> cant >> c >> dni >> c >> dd >> c >> mm >> c>> aa;
    fecha = aa * 10000 + mm*100 +dd;
    this->codigo = codigo;
    this->cantidad = cant;
    this->dni = dni;
    this->fecha = fecha;
    
    //Cargar los datos del padre Producto
    this->cargaDatos(codigo);
}

