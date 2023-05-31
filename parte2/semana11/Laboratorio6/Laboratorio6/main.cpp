//
//  main.cpp
//  Laboratorio6
//
//  Created by gkerath on 30/05/23.
//
#include "bibliotecaPilaGenerica.h"
#include "pilaConEnteros.h"

#include <iostream>

int main(int argc, const char * argv[]) {
  void * arreglo, *pilaini, *pilafin;
  cargaArreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
  cargaPila(pilaini,arreglo);  
  muevePila(pilaini,pilafin);
  return 0;
}
