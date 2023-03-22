#include <iostream>
#include <iomanip>

using namespace std;


int main(){
  int dato,dd,mm,aa,tipo,codigo,cant;
  char nombre[100], c,unidad[10];
  
  while (1){
    cin >> dato;
    if (cin.eof()){
      break;
    }
    if (dato > 9990){
      cin >> nombre;
      cout << dato << " " <<nombre << endl;
    }else{
      dd = dato;
      cin >> c >> mm >> c >> aa >> tipo >> codigo >> nombre >> cant;
      if (cin.fail()){
        cin.clear();
      }
      cin >> unidad;
    }
  }

  return 0;
}
