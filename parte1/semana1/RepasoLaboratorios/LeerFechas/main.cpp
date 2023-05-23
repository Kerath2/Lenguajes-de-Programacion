#include <iostream>
#include <iomanip>
#include "funcionesLectura.h"
using namespace std;

// TIPOS DE ENTRADA DE FECHAS 
// dd/mm/aa R
// mm/aa R
// aa R


int main(){
  int dd = 0, mm = 0 ,aa =0;

  leerFecha(dd,mm,aa); 

  cout << "La fecha leida es: ";
  cout << setw(2) << dd << '/' << setw(2) << mm << '/' << setw(4) << aa << endl;
  return 0;
}
