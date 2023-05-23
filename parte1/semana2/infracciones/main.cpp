#include <iostream>
#include <iomanip>

using namespace std;


int main(){
  int licencia, temp, dd , mm ,aa,codigo;
  char placa[10] , tipo , cadena[20], nombre[100] ;
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
      cout << endl << setw(20) << placa;
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

      cout << setw(2) << " ";
      cout << setfill('0');
      if (dd ==0)
        cout << setw(2) <<  "--";
      else
        cout << setw(2) << dd;
      cout <<  "/";
    
      if (mm ==0)
        cout << setw(2) <<  "--";
      else
        cout << setw(2)<< mm;
      cout << "/";
      cout << setw(4) <<  aa;
      cout << setfill(' ');
      cout << setw(2) << " ";
      cin >> tipo >> codigo >> cadena >> multa;
      cout << setw(5) << codigo << "  ";
      cout << right;
      if (tipo == 'G')
        cout << setw(10) << "Grave" << setw(4) << "70";
      if (tipo == 'L')
        cout << setw(10) << "Leve" <<setw(4) << 5;
      if (tipo == 'M')
        cout << setw(10) << "Muy Grave" << setw(4) << 150;
    }else{
      cin >> nombre;
      cout << endl<< setw(20) << licencia << setw(50) << nombre << endl;
    }
     
  }
  return 0;
}
