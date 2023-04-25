#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void llenaClientesBin(ofstream & clientesBin , int dni,char * nombre,int telefono);
char devuelveCategoria(char * nombre);
void   cambiaCaracter(char * nombre);
void llenaProdBin(ofstream & productosBin,char *codPedido,char * descripcion, double descuento, double precioU);
#endif // !FUNCIONES_H

