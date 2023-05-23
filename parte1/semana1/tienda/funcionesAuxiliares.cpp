#include <iostream>
#include <iomanip>
#include "funcionesAuxiliares.h"
#include <cmath>

using namespace std;

void actualizaCondicion(int tipo, char &condicion){
  //503
  //inician 5 entrada
  //terminan 3 saida
  int primerDigito, ultimoDigito;
  primerDigito  = floor(tipo/100);
  ultimoDigito = tipo%10; 
  if (primerDigito == 5)
    condicion= 'E';
  else if (ultimoDigito == 3){
    condicion = 'S';
  }
  else {
    condicion = 'N';
  }
}
