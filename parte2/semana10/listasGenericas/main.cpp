#include <iostream>
#include "funcionesConTipo.h"
#include "funcionesGenericas.h"

int main(){
  void *lista;
  crealista(lista,leecadena,cmpcadena); 
  imprimeLista(lista,imprimeCadena);
  return 0;
}
