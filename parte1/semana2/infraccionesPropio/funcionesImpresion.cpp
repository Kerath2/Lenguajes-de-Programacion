#include <iostream>
#include <iomanip>
#include "funcionesImpresion.h"
#define TAM_LINEA 120
using namespace std;

void imprimeLinea(char car , int tam){
  for (int i = 0 ; i < tam ; i++){
  cout << car;    
  }
  cout << endl;
}

void imprimeCabecera(){
  cout << setw(100) << "REGULADORA DE TRANSPORTE" << endl;
  imprimeLinea('=', TAM_LINEA); 
  
}

void imprimeCabeceraConductor(){

  cout << setw(50) << "CONDUCTOR";
  cout << setw(50) << "INFRACCIONES" << endl;
  imprimeLinea('-', TAM_LINEA);
  cout << setw(10) <<  "Licencia No";
  cout << setw(30) << "Nombre";
  cout << setw(15) << "placa";
  cout << setw(15) << "Fcha";
  cout << setw(15) << "Codigo";
  cout << setw(15) << "Gravedad";
  cout << setw(15) << "Puntos";
  cout << setw(15) << "Multa" << endl;
  imprimeLinea('-', TAM_LINEA);
}
