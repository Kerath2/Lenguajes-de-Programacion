#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"

using namespace std;

void llenaClientesBin(ofstream & clientesBin , int dni,char * nombre,int telefono){
  char categoria;
  double monto = 0;
  categoria = devuelveCategoria(nombre);
  cambiaCaracter(nombre);
  clientesBin.write(reinterpret_cast<const char *>(&dni), sizeof(int)); 
  clientesBin.write(reinterpret_cast<const char *>(nombre),sizeof(char) * 100 ); 
  clientesBin.write(reinterpret_cast<const char *>(&categoria),sizeof(char)); 
  clientesBin.write(reinterpret_cast<const char *>(&telefono),sizeof(int)); 
  clientesBin.write(reinterpret_cast<const char *>(&monto),sizeof(double)); 
}
// LOYOLA_MORI_NICOLAS-FERNANDO-B
char devuelveCategoria(char * nombre){
  int ult_guion ;
  int flag = 0;
  for (int i = 0 ; nombre[i] != '\0'; i++){
    if (nombre[i] == '-' && nombre[i+2] == '\0'){
      ult_guion = i;
      flag = 1;
    }
  }
  if (flag){
    nombre[ult_guion] = 0;
  }else{
    return 'D';
  }
  return nombre[ult_guion+1];

}

void   cambiaCaracter(char * nombre){
  for (int i = 0 ; nombre[i] != '\0'; i++){
    if (nombre[i] == '_' || nombre[i] == '-')
      nombre[i] = ' ';
  }
}

void llenaProdBin(ofstream & productosBin,char *codPedido,char * descripcion, double descuento, double precioU){
  cout << descripcion << endl;
}
