#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){

  int licencia,dd,mm,aa,codigo;
  char nombre[300], placa[100],letraCodigo,car;
  char descripcion[500], gravedad[20];
  double multa = 0;

  int nFaltasLeves= 0, nFaltasGraves = 0  , nFaltasMGraves= 0;
  double montoLeves =0 , montoGraves = 0 , montoMGraves = 0, total = 0;;

  ifstream infrCond("./Infracciones-Conductores.txt",ios::in);
  if (!infrCond){
    cout << "Error en la apertura del archivo ./Infracciones-Conductores.txt" << endl;
    exit(1);
  }
  ifstream infr("./Infracciones.txt",ios::in);
  if (!infr){
    cout << "Error en la apertura del archivo ./Infracciones.txt" << endl;
    exit(1);
  }

  ofstream conductores("Conductores.bin",ios::out|ios::binary);
  if(!conductores){
    cout << "Error en la apaertura del archivo Conductores.bin" << endl;
    exit(1);
  }

  ofstream faltasCometidas("FaltasCometidas.bin",ios::out|ios::binary);
  if(!faltasCometidas){
    cout << "Eror en la apertura del archivo FaltasCometidas.bin" << endl;
    exit(1);
  }

  while(1){
    infrCond >> licencia;
    conductores.write(reinterpret_cast<const char *>(&licencia), sizeof(int));
    if (infrCond.eof())
      break;
    if (infrCond.fail()){
      infrCond.clear();
      infrCond >> placa;
      faltasCometidas.write(reinterpret_cast<const char *>(placa), sizeof(char) * 100);
      faltasCometidas.write(reinterpret_cast<const char *>(&licencia), sizeof(int));
      infrCond >> dd >> car >>mm >> car >> aa;
      faltasCometidas.write(reinterpret_cast<const char *>(&dd), sizeof(int));
      faltasCometidas.write(reinterpret_cast<const char *>(&mm), sizeof(int));
      faltasCometidas.write(reinterpret_cast<const char *>(&aa), sizeof(int));
      infrCond >> letraCodigo >> codigo;
      switch (letraCodigo) {
        case 'L':
          strcpy(gravedad,"LEVE");
          break;
        case 'G':
          strcpy(gravedad,"GRAVE");
          break;
        case 'M':
          strcpy(gravedad,"MUY GRAVE");
          break;
      }
      faltasCometidas.write(reinterpret_cast<const char *>(gravedad), sizeof(char) * 20);
      faltasCometidas.write(reinterpret_cast<const char *>(&multa), sizeof(double));
    }
    infrCond >> nombre;
    conductores.write(reinterpret_cast<const char *>(nombre), sizeof(char) * 300);
    conductores.write(reinterpret_cast<const char *>(&nFaltasLeves), sizeof(int));
    conductores.write(reinterpret_cast<const char *>(&nFaltasGraves), sizeof(int));
    conductores.write(reinterpret_cast<const char *>(&nFaltasMGraves), sizeof(int));
    conductores.write(reinterpret_cast<const char *>(&montoLeves), sizeof(double));
    conductores.write(reinterpret_cast<const char *>(&montoGraves), sizeof(double));
    conductores.write(reinterpret_cast<const char *>(&montoMGraves), sizeof(double));
  }

  while(1){
    infr >> codigo;
    if (infr.eof())
      break;
    infr >> descripcion >> gravedad >> multa;
  }

  

  return 0;

}
