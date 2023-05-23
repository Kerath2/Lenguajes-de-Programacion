#include <iostream>
#include <iomanip>

using namespace std;

// Viktor 20 10 9    Cesar 11 20  Rony 15 11 12 16

int main(){
  char nombre[15];
  double nota, sumaNotas, promedio;
  int cantNotas;
  for (int i = 0 ; i < 3 ; i++){
    cin >> nombre;
    cout << nombre << " ";
    sumaNotas = 0;
    cantNotas = 0;
    while(1){
      cin >> nota;
      if (cin.fail()){
        cin.clear();
        break;
      }
      sumaNotas += nota;
      cantNotas ++;
    }
    promedio = sumaNotas / cantNotas;
    cout << fixed << setprecision(1) << "promedio"<< " " << promedio << endl;
    cout.unsetf(ios::fixed);
  }
  return 0;
}
