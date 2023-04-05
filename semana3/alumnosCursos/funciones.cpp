#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"


using namespace std;


void generaAlumnosBin(){
  char tipo, nombre[100], esp[100], fac[4];
  int codigo,carnet;
  ifstream arch("./Alumnos.txt",ios::in);
  if (!arch){
    cout << "Error en la apertura del archivo Alumnos.txt" << endl;
    exit(1);
  }

  ofstream archBin("alumnosbin.bin",ios::out|ios::binary);
  if (!archBin){
    cout << "Error en la apertura del archivo alumnosbin.bin" << endl;
    exit(1);
  }

  
  while(1){
    arch >> tipo;
    if(arch.eof())
      break;
    arch >> codigo >> nombre;
    arch >> carnet;
    if (arch.fail()){
      arch.clear();
      carnet = 0;
    }
    arch >> esp >> fac;
    archBin.write(reinterpret_cast<const char *>(&codigo),sizeof(int));
    archBin.write(reinterpret_cast<const char *>(nombre),sizeof(char) * 100);
    archBin.write(reinterpret_cast<const char *>(&tipo),sizeof(char) );
    archBin.write(reinterpret_cast<const char *>(&carnet),sizeof(int) );
    archBin.write(reinterpret_cast<const char *>(&fac),sizeof(char) * 4);
    archBin.write(reinterpret_cast<const char *>(&esp),sizeof(char) * 100 );
  }
}
