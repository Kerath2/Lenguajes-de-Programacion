#include <iostream>
#include <iomanip>
#include <fstream>
#include  "funciones.h"
using namespace std;


int main(){
  generaAlumnosBin();
  generarConsolidado();
  imprimeConsolidado();
  actualizaConsolidado();
  return 0;
}
