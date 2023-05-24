#include <iostream>
#include <cstdlib>
#include "funcionesGenericas.h"
#include "funcionesConTipo.h"

using namespace std;


//tendremos una funcion leeentero, leecadena y leeregistro

int main(){
  void * lista = nullptr;
  //nuestra funcion crealista es generica
  crealista(lista,leeentero,cmpentero);
  return 0;
}
