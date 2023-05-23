#include <iostream>
#include <iomanip>
#include "alumno.h"

using namespace std;

double operator ++(tregistro &notas, int b){
  int suma = 0;
  for (int i = 0 ; i < notas.canNotas; i++){
    suma = suma + notas.notas[i];
  }
  return (double)suma/notas.canNotas;
}

ostream & operator<<(ostream &out,const tregistro &notas){
  for (int i = 0 ; i < notas.canNotas; i++){
    out << setw(4) << notas.notas[i];
  }
  return out;
}

tregistro operator+(const tregistro &a,const tregistro&b){
  tregistro nuevo;
  for (int i = 0 ; i < a.canNotas ; i++){
    nuevo.notas[i] = a.notas[i] + b.notas[i];
  }
  nuevo.canNotas= a.canNotas;


  return nuevo;
}


void operator*(const tregistro &a, double factor){
  tregistro nuevo;
  for (int i = 0 ; i < a.canNotas ; i++){
    nuevo.notas[i] = a.notas[i] * factor; 
  }
  nuevo.canNotas= a.canNotas;

  cout << "Sus notas multiplicadas por el factor son: ";
  cout << nuevo << endl;
}
