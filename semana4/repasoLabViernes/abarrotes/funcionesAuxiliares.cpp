#include <iostream>
#include <iomanip>
#include "funcionesAuxiliares.h"
using namespace  std;


char obtenCategoria(char *cadena){
  int largoCadena;
  char car;
  for (int i = 0 ; cadena[i]!='\0';i++)
    largoCadena = i;

  car = cadena[largoCadena];
  cadena[largoCadena-1] = 0;

  for (int i = 0 ; cadena[i]!='\0';i++)
    if (cadena[i] == '/' || cadena[i] == '-')
      cadena[i] = ' ';

  return car;
}
