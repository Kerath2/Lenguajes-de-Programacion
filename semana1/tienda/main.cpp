#include <iostream>
#include <iomanip>
#include "funcionesReporte.h"
#define TAM_LINEA 100
using namespace std;


int main(){
  int dato,dd,mm,aa,tipo,codigo,cant;
  char nombre[100], c,unidad[10];
  
  imprimeCabecera();

  while (1){
    cin >> dato;
    if (cin.eof()){
      break;
    }
    if (dato > 9990){
      cin >> nombre;
      cout << dato << " " <<nombre << endl;
      imprimeLinea('=',TAM_LINEA);
      imprimeCabeceraTienda();
    }else{
      dd = dato;
      cin >> c >> mm >> c >> aa >> tipo >> codigo >> nombre >> cant;
      cout << setw(2) << right<< setfill('0')<< dd << '/'<< setw(2) << mm << '/' << setw(4) << aa;
      cout << setfill(' ') << setw(10) << " ";
      cout << setw(8) << setfill('0') << codigo << setfill(' ')<<setw(30) << nombre << endl;
      if (cin.fail()){
        cin.clear();
      }
      cin >> unidad;
    }
  }

  return 0;
}
