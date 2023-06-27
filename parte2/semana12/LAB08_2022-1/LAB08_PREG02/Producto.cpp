/*

 */

#include "Producto.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
Producto::Producto() {
    codprod = 0;
    nombre = nullptr;
    precio = 0;
    stock = 0;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(char* cad) {
    if(nombre != nullptr)delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Producto::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::cargaDatos(int cod){
    ifstream arch("productos3.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo productos3" << endl;
        exit(1);
    }
    double precio;
    int codigo, stock;
    char buffer[500], nombre[100],c;
    while(1){
        arch >> codigo;
        if(arch.eof()) break;
        if(codigo == cod){
            //leo correctamente
            arch.get();
            arch.getline(nombre,100,',');
            arch >> precio >> c >> stock;
            this->codprod = codigo;
            SetNombre(nombre);
            this->precio = precio;
            this->stock = stock;
            break;
        }else{
            // me barro todo
            arch.getline(buffer,500,'\n');
        }
    }
    
    
}
