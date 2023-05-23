#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(){
  int dd , mm ,aa;
  char nombre[100];
  double mmr;

  ifstream archBin("./Registro.bin", ios::in | ios::binary);
  if (!archBin){
    cout << "Error en la apertura del archivo Registro.bin" << endl;
    exit(1);
  }

  ofstream reporte("Reporte.txt", ios::out | ios::binary);
  if(!reporte){
    cout << "Error en la apertura del archivo Reporte.txt" << endl;
    exit(1);
  }

  archBin.read(reinterpret_cast<char *>(&dd),sizeof(int));
  archBin.read(reinterpret_cast<char *>(&mm),sizeof(int));
  archBin.read(reinterpret_cast<char *>(&aa),sizeof(int));
  archBin.read(reinterpret_cast<char *>(nombre),sizeof(char) * 100);
  archBin.read(reinterpret_cast<char *>(&mmr),sizeof(double));

  reporte << dd << mm << aa << endl;
  reporte << nombre << endl;
  reporte << mmr ;
  return 0;
}
