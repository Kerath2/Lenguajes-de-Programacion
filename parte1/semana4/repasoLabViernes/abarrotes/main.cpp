#include <iostream>
#include <iomanip>
#include "funcionesAuxiliares.h"
using namespace  std;


int main(){
  double descuento;;
  char codProductoVerificar[30], codProducto[30],nombre[100],car, descPro[100];
  int dni, telefono;
  double arrDesc[3];// 0-A 1-B 2-C
  double descAdic,cantComprada , precioUnit;
  int dd, mm ,aa;
  char categoria;
  //
  //
  int contProd;
  //
  cin  >>car  >> arrDesc[0]>> car >>car >> arrDesc[1] >> car >> car >>arrDesc[2] >> car;
  cin  >> codProductoVerificar;

  while(1){
    cin >> dni;
    if(cin.eof()) break;
    if(cin.fail()){
        cin.clear();
        //
        contProd++;
        //
        cin >> codProducto >> descPro; // descrpcuion producto
        cin >> cantComprada;
        if (cin.fail()){
          cin.clear();
          cin >> car >> descAdic;
          cin >> cantComprada;
        }
        cin >> precioUnit;
        cin >> dd >> car >> mm >> car >> aa ;
      }else{
      cin >> nombre >> telefono;
      //Reiniciar contadores por nombre
      contProd = 0;
      //
      categoria = obtenCategoria(nombre);
      cout << setw(12) << dni << setw(40) << nombre << setw(14) << telefono << setw(20) << categoria;

      switch(categoria){
        case 'A' :
          descuento = arrDesc[0];
          break;
        case 'B' :
          descuento = arrDesc[1];
          break;
        case 'C' :
          descuento = arrDesc[2];
          break;
      }

      cout << setw(10) << descuento;
      cout << endl;
    }
  }




  return 0;
}

