#ifndef OPERADORES
#include <fstream>
#include "Estructuras.h"
using namespace std;
ifstream &operator >>(ifstream &entrada , Estructura_ClienteRegistrado &cliente);
void separaCategoria(char * nombre ,char * categoria);
void operator += (Estructura_ClienteRegistrado * clientes, Estructura_ClienteRegistrado nuevo);
void operator +=(Estructura_ClienteRegistrado &cliente,Estructura_PedidoRealizado pedidoNuevo);
void operator += (Estructura_ProductosEnAlmacen * arrProd, Estructura_ProductosEnAlmacen producto);
ofstream &operator <<(ofstream &salida, Estructura_ClienteRegistrado cliente);
ostream &operator <<(ostream &salida, Estructura_ClienteRegistrado cliente);
#endif // !OPERADORES
