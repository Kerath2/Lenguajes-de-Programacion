#include <iostream>
#include <iomanip>

using namespace std;


int main(){
  int licencia, temp, dd , mm ,aa;
  char placa[10] , tipo[10] , cadena[20], nombre[100] ;
  double multa;
  while(1){
    cin >> licencia;
    if (cin.eof()){
      break;
    }
    if (cin.fail()){
      cin.clear();
      cin >> placa;
      dd = 0; mm = 0; aa = 0;
      while(1){
      // LECTURA DE FECHAS
        cin >> temp;
        if (cin. fail()){
          cin.clear();
          break;
        }else{
          dd = mm;
          mm = aa;
          aa = temp;
        }
      }
      cin >> tipo >> cadena >> multa;
    }else{
      cin >> nombre;
    }
     
  }
  return 0;
}
