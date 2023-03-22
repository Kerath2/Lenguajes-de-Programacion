#include <iostream>
#include <iomanip>
#include "funcionesReporte.h"

using namespace std;

void imprimeLinea(char car, int num){
  for (int i = 0 ; i < num ; i ++){
    cout << car;
  }
  cout << endl;
}

void imprimeCabecera(){
  cout << setw(50) << "REPORTE KARDEX" << endl;
  imprimeLinea('=',100);
}

void imprimeCabeceraTienda(){
  cout << setw(20) << left << "FECHA";
  cout << setw(20) << "CODIGO";
  cout << setw(30) << "DESCRIPCION";
  cout << setw(20) << "CANTIDAD";
  cout << setw(20) << "UNIDAD" << endl;
  imprimeLinea('-', 100);
}
