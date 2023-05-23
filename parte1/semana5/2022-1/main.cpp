#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"

using namespace std;

int main(){
  int dni, telefono, codCli , dd , mm ,aa;
  char nombre[100], codPedido[50], descripcion[100], car;
  double descuento, cantidad, precioU;

  ifstream arch("./entrada.txt", ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo entrada.txt" << endl;
    exit(1);
  }

  ofstream clientesBin("Clientes.bin",ios::out | ios::binary);
  if (!clientesBin){
    cout << "Error en la apertura del archivo clientes.bin" << endl;
    exit(1);
  }
  ofstream productosBin("Productos.bin",ios::out | ios::binary);
  if (!productosBin){
    cout << "Error en la apertura del archivo Productos.bin" << endl;
    exit(1);
  }

  while(1){
    arch >> dni;
    if(arch.eof()) break;
    if(arch.fail()){
      arch.clear();
      arch >> codPedido >> descripcion;
      arch >> cantidad;
      if(arch.fail()){
        arch.clear();
        arch >> car >> descuento >> cantidad;
      }else{
        descuento = 0;
      }
      arch >>  precioU >> codCli >> dd >> car >> mm >> car >> aa;
      // cout << descripcion << endl;
      llenaProdBin(productosBin,codPedido, descripcion, descuento, precioU);
    }else{
      arch >> nombre >> telefono;
      llenaClientesBin(clientesBin,dni,nombre,telefono);
    }
  }
  
  
  return 0;
}

