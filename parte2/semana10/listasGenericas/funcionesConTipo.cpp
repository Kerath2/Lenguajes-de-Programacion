#include "funcionesConTipo.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


void *leeentero(ifstream &arch){
  int codigo;
  char cad[200];
  arch >> codigo;
  if(arch.eof()) return nullptr;
  int * aux = new int;
  *aux = codigo;
  arch.getline(cad,200);
  return aux;
}


int cmpentero(void *a, void*b){
  int *pa = (int*)a;
  int *pb = (int*)b;
  cout << "comparando: " << *pa << "con" << *pb << endl;
  return (*pa) - (*pb);
}
