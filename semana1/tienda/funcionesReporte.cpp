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
}
