#include <iostream>
#include <iomanip>
#include "funciones.h"
using namespace std;



int main(){
  int dd , mm ,aa, dni ,cant ,codMed;
  int ddM, mmM, aaM;
  char esp1[50] , esp2[50], car, codDoctor[20], nombreDoctor[100], nombreMedicina[50];
  char nombrePaciente[100],nomEsp[50], espMin[50];
  cin >> esp1 >> esp2;
  cin >> dd >> car >> mm >> car >> aa;

  while(1){
    cin >> dni;
    if(cin.eof()) break;
    if (cin.fail()){
      cin.clear();
      cin >> codDoctor >> nombreDoctor;
      cortaEspecialidad(nombreDoctor,nomEsp,espMin);
      cout << left << endl;
      cout << setw(40) << nombreDoctor << right << setw(20)  << codDoctor <<  setw(20) << espMin << endl;
    }else{
      cin >> nombrePaciente >> cant; 
      cout <<left <<  setw(20)<<dni <<  setw(50) << nombrePaciente << endl;
      for (int i = 0 ; i < cant ;i++){
        cin >> codMed; 
        cin >> nombreMedicina;
        cin >> ddM >> car >> mmM >> car >> aaM;
      }
    }

  }
  return 0;
}
