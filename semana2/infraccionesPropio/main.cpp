#include <iostream>
#include <iomanip>
#include "funcionesImpresion.h"
 
using namespace std;


int main(){
  int licencia, temp , dd , mm , aa, cod;
  char placa[50], tipCod,palabra[50], nombre[100];
  double multa;
  imprimeCabecera();
  while(1){
    cin >> licencia;    
    if (cin.eof())break;
    if (cin.fail()){
      cin.clear();
      cin >> placa; 
      dd = 0 ; mm = 0 ; aa = 0;
      cout << left;
      cout << setw(12) << placa;
      while(1){
        cin >> temp;
        if (cin.fail()){
          cin.clear();
          break;
        }else{
          dd = mm;
          mm = aa;
          aa = temp;
        }
      }
     
      cout << right;
      cout << setw(2) << dd << '/';
      cout << setw(2) << mm << '/';
      cout << setw(4) << aa;

      cout << setw(6) << cod;

      cout << setw(10) << "Muy grave";
      cout << setw(5) << 150;
      cout << setw(12) << multa << endl;

      cin >> tipCod;
      cin >> cod;
      cin >> palabra;
      cin >> multa;
    }else{
      imprimeCabeceraConductor();
      cin >> nombre;
      cout << setw(12) << licencia;
      cout << setw(40) <<  nombre << endl;

    }  

  }


  return 0;
}
