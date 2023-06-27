/*

 */
#include <iostream>
#include "Tienda.h"
#include <fstream>
#include <iomanip>
using namespace std;
Tienda::Tienda() {
}

Tienda::Tienda(const Tienda& orig) {

}

Tienda::~Tienda() {
}

void Tienda::carga(){
    ifstream arch("pedidos3.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo pedidos3" << endl;
        exit(1);
    }
    ifstream archClientes("clientes2.csv",ios::in);
    if(!archClientes){
        cout << "Error abriendo el archivo de clientes" << endl;
        exit(1);
    }
    int i = 0;
    
    while(1){
        lpedidos[i].leePedido(arch);
        if(arch.eof()) break;
        i++;       
    }
    
     i = 0;
    while(1){
        lclientes[i].leeCliente(archClientes);
        if(archClientes.eof())break;
        i++;
    }
 

}

void Tienda::muestra(){
    ofstream arch("muestra.txt",ios::out); 
    if(!arch){
        cout << "Error en la apertura del archivo para el reporte" << endl;
        exit(1);
    }
    
    arch << "Fecha    Codigo Descripcion del Prod.                                             Cant. Precio   Total    Observaciones" << endl;
    
    for (int i = 0 ; lpedidos[i].GetCodigo(); i++){
        char nombre[100];
        lpedidos[i].GetNombre(nombre);
        arch << lpedidos[i].GetFecha() << " " << lpedidos[i].GetCodigo() <<" "  << left << setw(60) <<
                nombre << " " << right <<  setw(8) <<  lpedidos[i].GetCantidad() << setw(8) << lpedidos[i].GetPrecio() << " " <<
                lpedidos[i].GetTotal() << endl;
    }
}