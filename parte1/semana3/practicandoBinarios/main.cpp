#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
  
  int dd, mm , aa;
  char nombre[100] = "Gerardo_Miguel_Tacay_Terrazos";
  double mmr;

  ofstream archBin("Registro.bin",ios::out | ios::binary);
  if(!archBin){
    cout << "Error en la apertura del archivo  Registro.bin " << endl;
    exit(1);
  }

  dd = 6;
  mm = 10;
  aa = 2001;
  mmr = 5.4;

  
  archBin.write(reinterpret_cast<const char *>(&dd), sizeof(int));
  archBin.write(reinterpret_cast<const char *>(&mm), sizeof(int));
  archBin.write(reinterpret_cast<const char *>(&aa), sizeof(int));
  archBin.write(reinterpret_cast<const char *>(nombre), sizeof(char) * 100);
  archBin.write(reinterpret_cast<const char *>(&mmr), sizeof(double) );
  return 0;
}

