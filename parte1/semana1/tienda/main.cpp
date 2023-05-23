#include <iostream>
#include <iomanip>
#include "funcionesReporte.h"
#include "funcionesAuxiliares.h"
#define TAM_LINEA 100
using namespace std;


int main(){
  int dato,dd,mm,aa,tipo,codigo;
  double cant;
  char nombre[100], c,unidad[10];
  char condicion; // se refiere a si es ingreso o salida
  
  imprimeCabecera();

  while (1){
    cin >> dato;
    if (cin.eof()){
      break;
    }
    if (dato > 9990){
      cin >> nombre;
      imprimeLinea('=',TAM_LINEA);
      cout << dato << " " <<nombre << endl;
      imprimeLinea('=',TAM_LINEA);
      imprimeCabeceraTienda();
    }else{
      dd = dato;
      cin >> c >> mm >> c >> aa >> tipo >> codigo >> nombre >> cant;
      actualizaCondicion(tipo,condicion);
      cout << setw(2) << right<< setfill('0')<< dd << '/'<< setw(2) << mm << '/' << setw(4) << aa;
      cout << setfill(' ') << setw(10) << " ";
      cout << setw(8) << setfill('0') << codigo << setfill(' ')<<setw(50) << nombre;
      if (cin.fail()){
        cant = 1;
        cin.clear();
      }
      cin >> unidad;
      //Actualizando la cantidad 
      if (condicion == 'S'){
        cant = cant * -1;
      }
      cout << setw(10) << fixed << setprecision(2) <<  cant ;
      cout << setw(5) << "" << setw(4) << left <<  unidad << endl;

    }
  }

  return 0;
}
