#include <iostream>
#include <iomanip>
#include <fstream>
#include "Estructuras.h"
#include "operadores.h"
#include <cstring>
using namespace std;

ifstream &operator >>(ifstream &entrada , Estructura_ClienteRegistrado& cliente){
  int telefono;
  entrada >> cliente.dni >> cliente.nombre >> telefono; 
  cliente.numeroDePedidos = 0;
  cliente.montoTotalGastado = 0;
  separaCategoria(cliente.nombre,cliente.categoria);
  return entrada;
}


void separaCategoria(char * nombre ,char * categoria){
  char cat;
  char sinCategoria[100] = "sin Categoria";
  char muyFrecuente[100] = "cliente Muy Frecuente";
  char frecuente[100] = "cliente Frecuente";
  char ocasional[100] = "cliente Ocasional";
  int tam = strlen(nombre); 
  if (nombre[tam-2] == '-'){
    cat = nombre[tam-1];
    switch (cat) {
      case 'A':
        strcpy(categoria,muyFrecuente);
      break;
      case 'B':
        strcpy(categoria,frecuente);
      break;
      case 'C':
        strcpy(categoria,ocasional);
      break;
    }
    nombre[tam-2] = 0;
  }else{
    strcpy(categoria,sinCategoria);
  }
}


void operator += (Estructura_ClienteRegistrado * clientes, Estructura_ClienteRegistrado nuevo){
  int pos = 0;
  while(1){
    if (clientes[pos].dni == 0){
      break; 
    } 
    pos++;
  }

  clientes[pos].dni = nuevo.dni;
  strcpy(clientes[pos].nombre,nuevo.nombre);
  strcpy(clientes[pos].categoria,nuevo.categoria);
  clientes[pos].numeroDePedidos = nuevo.numeroDePedidos;
  clientes[pos].montoTotalGastado = nuevo.montoTotalGastado;

  //pasando pedidos
  for(int i = 0 ; i < nuevo.numeroDePedidos; i++){
    clientes[pos].pedidosRealizados[i].fecha = nuevo.pedidosRealizados[i].fecha;
    strcpy(clientes[pos].pedidosRealizados[i].codigo, nuevo.pedidosRealizados[i].codigo);
    clientes[pos].pedidosRealizados[i].cantidad= nuevo.pedidosRealizados[i].cantidad;
  }
  
  pos++;
  clientes[pos].dni = 0;

}

void operator +=(Estructura_ClienteRegistrado &cliente,Estructura_PedidoRealizado pedidoNuevo){
  cliente.pedidosRealizados[cliente.numeroDePedidos].cantidad = pedidoNuevo.cantidad;
  strcpy(cliente.pedidosRealizados[cliente.numeroDePedidos].codigo,pedidoNuevo.codigo);
  cliente.pedidosRealizados[cliente.numeroDePedidos].fecha= pedidoNuevo.fecha;
  cliente.numeroDePedidos++;
}

void operator += (Estructura_ProductosEnAlmacen * arrProd, Estructura_ProductosEnAlmacen producto){
  char codFinal[7] = "X";
  int esta = 0;
  int i = 0;
  while(1){
    if (!strcmp(arrProd[i].codigo,producto.codigo)){
      esta = 1;
      return;
    }
    if (!strcmp(arrProd[i].codigo,codFinal)){
      break;
    }
    i++;
  }

  strcpy(arrProd[i].codigo , producto.codigo);
  arrProd[i].precioUnitario =  producto.precioUnitario;
  strcpy(arrProd[i].descripcion ,producto.descripcion);
  arrProd[i].descuento = producto.descuento;
  strcpy(arrProd[i+1].codigo,codFinal);

}

ofstream &operator <<(ofstream &salida, Estructura_ClienteRegistrado cliente){
  salida << "DNI" << setw(12) << "NOMBRE" << endl; 
  salida << setw(12) <<cliente.dni <<  setw(40) << cliente.nombre << endl;
  salida << setw(30) << cliente.categoria; 
  for (int i = 0 ; i < cliente.numeroDePedidos; i++){
    salida << i+1 << setw(12) << cliente.pedidosRealizados[i].codigo << setw(12)<<
          cliente.pedidosRealizados[i].cantidad << cliente.pedidosRealizados[i].fecha << endl;
  }
  salida <<"Monto total gastado :" << cliente.montoTotalGastado << endl;
  return salida;
}


ostream &operator <<(ostream &salida, Estructura_ClienteRegistrado cliente){
  salida << "DNI" << setw(12) << "NOMBRE" << endl; 
  salida << setw(12) <<cliente.dni <<  setw(40) << cliente.nombre << endl;
  salida << setw(30) << cliente.categoria; 
  for (int i = 0 ; i < cliente.numeroDePedidos; i++){
    salida << i+1 << setw(12) << cliente.pedidosRealizados[i].codigo << setw(12)<<
          cliente.pedidosRealizados[i].cantidad << cliente.pedidosRealizados[i].fecha << endl;
  }
  salida <<"Monto total gastado :" << cliente.montoTotalGastado << endl;
  return salida;
}
