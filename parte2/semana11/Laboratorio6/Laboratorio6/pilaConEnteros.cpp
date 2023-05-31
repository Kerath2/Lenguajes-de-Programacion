#include <iostream>
#include <iomanip>
#include <fstream>
#include "pilaConEnteros.h"


using namespace std;

int cmpnumero(const void*a, const void *b){
  // guarda la direccion de memoria por eso es puntero doble
  void ** aux1 = (void**)a;
  void ** aux2 = (void**)b;
  
  int *num1 = (int*)(aux1);
  int *num2 = (int*)(aux2);


  return *num2- *num1;
}

void * leenumero(ifstream & arch){
  int aux;
  int *num;
  arch >> aux;
  if(arch.eof()) return nullptr;
  num = new int;
  *num = aux;
  return num;
}




