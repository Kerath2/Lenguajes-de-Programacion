#include <iostream>
#include <iomanip>
#include "funcionesLectura.h"

using namespace std;

// TIPOS DE ENTRADA DE FECHAS 
// dd/mm/aa R
// mm/aa R
// aa R
void  leerFecha(int &dd,int &mm,int &aa){
  char car;
  for (int i = 0 ; i < 3 ; i++){
    if (i == 1) { // mm/aaaa
      mm = aa;  
    }
    if (i == 2) { // mm/aaaa
      dd = mm;  
      mm = aa;
    }
    cin >> aa; 
    cin >> car;
    if (car != '/'){
      break;
    }
  }

}
