#include <iostream>
#include <iomanip>
#include <fstream>
#include <fstream>
#include "Estructuras.h"
#include "operadores.h"
#include "funciones.h"
using namespace std;


int main(){
  Estructura_ClienteRegistrado clientes[100]; 
  inicializa(clientes,100);
  ifstream arch("./Clientes.txt",ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo clientes.txt" << endl;
    exit(1);
  }

  ofstream reporte("./reporte.txt",ios::out);
  if(!reporte){
    cout << "Error en la apertura de reporte.txt " << endl;
    exit(1);
  }

  


  int cont = 0;
  while(1){
   arch >> clientes[cont];
    if(arch.eof()) break;
  cout << clientes[cont].nombre<< " " << clientes[cont].categoria <<  endl;
   cont++; 
  }

  cout << "NUEVO" << endl;
  Estructura_ClienteRegistrado clienteNuevo;
  clienteNuevo.dni = 19896397;
  char nombre[100] = "Gerardo Miguel Tacay Terrazos";\
  char categoria[30] = "cliente nuevo";
  strcpy(clienteNuevo.nombre,nombre);
  strcpy(clienteNuevo.categoria,categoria);
  
  clientes += clienteNuevo;

  // imprimimos todo
  int i = 0;
  while(clientes[i].dni!=0){
    cout << clientes[i].nombre << endl;
    i++;
  }

  Estructura_PedidoRealizado pedidoNuevo;
  pedidoNuevo.fecha=3213123;
  char cod[7] = "INF321";
  strcpy(pedidoNuevo.codigo,cod);
  pedidoNuevo.cantidad = 20.5;

  clientes[0] += pedidoNuevo;

  cout << "Pedidos del cliente 0" << endl;
  for (int i = 0 ; i < clientes[0].numeroDePedidos ;i++){
    cout << clientes[0].pedidosRealizados[i].codigo << endl;
  }



// struct Estructura_ProductosEnAlmacen{
//     char codigo[7];
//     char descripcion[80];
//     double precioUnitario;
//     double descuento;
// };

  Estructura_ProductosEnAlmacen arrProd[100];
  char codigo[7] ="X";
  strcpy(arrProd[0].codigo,codigo); 


  Estructura_ProductosEnAlmacen producto;
  char codi[7] = "D3232";
  char descripcion[90] = "AQUI VA UNA DESCRIPCION DEL PRODUCTO";
  strcpy(producto.codigo,codi);
  producto.descuento = 0.6;
  strcpy(producto.descripcion,descripcion);
  producto.precioUnitario = 20;

  arrProd += producto;


  for (int i = 0;strcmp(arrProd[i].codigo,codigo) ;i++){
    cout << arrProd[i].codigo << endl;
  }


  cout << "impresion por cliente" << endl;
  cout << clientes[1];
  return 0;
}




