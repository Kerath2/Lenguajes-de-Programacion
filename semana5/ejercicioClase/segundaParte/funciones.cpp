#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

void actualiza(){
  int dni, dd , mm , aa, cantMed, codMedicamento; 
  char car, codMed[10];
  double precio;
  ifstream cons("consultas.txt",ios::in );
  if (!cons){
    cout << "Error en la apertura del archivo consultas.txt" << endl;
    exit(1);
  }

  while(1){
    cons >> dni;
    if (cons.eof()) break;
    cons>> codMed; 
    cons >> dd >> car >> mm >> car >> aa >> cantMed;
    precio = 0;
    for (int i = 0 ; i < cantMed ; i++){
      cons >> codMedicamento; 
      precio += preciomed(codMedicamento);
    }
    actualiza_pac(dni,precio);
  }
}

double preciomed(int codMedicamento){
  char medicamento[100];
  int codMedicamento2;
  double precio;
  ifstream medBin("medicinas.bin",ios::in| ios::binary);
  if (!medBin){
    cout << "Error en la apertura del archivo medicinas.bin" << endl;
    exit(1);
  }

  while(1){
    medBin.read(reinterpret_cast<char *>(&codMedicamento2), sizeof(int));
    if(medBin.eof()) break;
    medBin.read(reinterpret_cast<char *>(medicamento), sizeof(char)* 100);
    medBin.read(reinterpret_cast<char *>(&precio), sizeof(double));
    if(codMedicamento == codMedicamento2){
      return precio;
    }
  }
  return 0;
}

void actualiza_pac(int dniC,double precio){
  int dni;
  char nombre[100];
  double gasto;
  fstream pacBin("pacientes.bin",ios::in | ios::out | ios::binary);
  if (!pacBin){
    cout << "Error en la apertura del archivo pacientes.bin" << endl;
    exit(1);
  }
  while(1){
    pacBin.read(reinterpret_cast<char *>(&dni), sizeof(int));
    if(pacBin.eof()) break;
    pacBin.read(reinterpret_cast<char *>(nombre), sizeof(char)* 100);
    pacBin.read(reinterpret_cast<char *>(&gasto), sizeof(double));
    if (dni == dniC){
      pacBin.seekg(-1*sizeof(double),ios::cur);
      gasto += precio;
      pacBin.write(reinterpret_cast<const char *>(&gasto), sizeof(double));
      pacBin.flush();
    }
  }
}

