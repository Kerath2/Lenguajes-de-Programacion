#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
#define MAXCAD 100
using namespace std;


void leerArchivos(){
  int dni,dd,mm,aa, cantMed, codMedicamento;
  char nombre[100], medico[100], codMed[10], car, medicamento[100];
  double precio;
  ifstream arch("entrada.txt",ios::in);
  if (!arch){
    cout << "Error en la apertura del archivo entrada.txt " << endl;
    exit(1);
  }

  ofstream med("Medicos.txt",ios::out);
  if (!med){
    cout << "Error en la apertura del archivo Medicos.txt " << endl;
    exit(1);
  }

  ofstream pacBin("pacientes.bin",ios::out | ios::binary);
  if (!pacBin){
    cout << "Error en la apertura del archivo pacientes.bin" << endl;
    exit(1);
  }


  ofstream medBin("medicinas.bin",ios::out | ios::binary);
  if (!medBin){
    cout << "Error en la apertura del archivo medicinas.bin" << endl;
    exit(1);
  }


  ofstream cons("consultas.txt",ios::out );
  if (!cons){
    cout << "Error en la apertura del archivo consultas.txt" << endl;
    exit(1);
  }

  while(1){
    arch >> dni;  
    if (arch.eof()) break;
    if (arch.fail()){
      arch.clear();
      arch >> codMed >> medico; 
      inserta_medico(med,codMed,medico);
    }else{
      arch >> nombre >> codMed; 
      arch >> dd >> car >> mm >> car >> aa >> cantMed;
      inserta_paciente(pacBin,dni,nombre);
      inserta_consulta(cons,dni,codMed,dd,mm,aa,cantMed);

      for (int i = 0 ; i < cantMed ; i++){
        arch >> codMedicamento >> medicamento >> precio;
        inserta_medicamento(medBin,codMedicamento,medicamento,precio);
        inserta_consulta_med(cons , codMedicamento);
      }
      cons << endl;
    }
  }

  cout << "lecutura correcta " << endl; 

}


void inserta_medico(ofstream &med, char * codMed, char * medico){
  char esp[50];
  saca_especialidad(medico,esp);
  med <<setw(10) << codMed << setw(50) <<medico << setw(20) << esp  << endl;
}

void saca_especialidad(char * medico, char * esp){
  int flag = 0 , j = 0;
  for (int i = 0 ; i <MAXCAD ; i++){
    if (medico[i] == '_' && medico[i+2] <= 'z' && medico[i+2] >= 'a'){
      medico[i] = '\0';
      flag = 1;
    } 
    if(flag){
      esp[j] = medico[i+1];
      j++;
      if(medico[i+1] == '\0') break;
    }
  }
}

void inserta_paciente(ofstream &pacBin,int dni,char * nombre){
  int flag;
  double gasto=0;
  char archivo[20] = "pacientes.bin";
  flag = verifica(dni,archivo);
  if(!flag){
    pacBin.write(reinterpret_cast<const char *>(&dni), sizeof(int));
    pacBin.write(reinterpret_cast<const char *>(nombre), sizeof(char)* 100);
    pacBin.write(reinterpret_cast<const char *>(&gasto), sizeof(double));
    pacBin.flush();
  }
}

int verifica(int dni,char *cad){
  // Si esta se devuelve 1
  // Si no esta se devuelve 0 
  int dni2;
  char nombre[100];
  double gasto;
  ifstream paciente(cad,ios::in| ios::binary);
  if (!paciente){
    cout << "Error en la apertura del archivo pacientes.bin/med" << endl;
    cout << cad << endl;
    exit(1);
  }
  while(1){
    paciente.read(reinterpret_cast<char *>(&dni2), sizeof(int));
    if(paciente.eof()) return 0;
    paciente.read(reinterpret_cast<char *>(nombre), sizeof(char)* 100);
    paciente.read(reinterpret_cast<char *>(&gasto), sizeof(double));
    if (dni == dni2) return 1;
  }
}

void inserta_consulta(ofstream & cons,int dni,char  * codMed,int dd,int mm,int aa, int cantMed){
  cons <<  setw (10) << dni << setw(10) <<  codMed << setw(4) <<  dd << '/' << mm << '/' << aa << setw(6) << cantMed ;

}


void inserta_medicamento(ofstream &medBin,int codMedicamento,char * medicamento,double precio){
  char archivo[20] = "medicinas.bin";
  int flag = verifica(codMedicamento, archivo); 
  if(!flag){
    medBin.write(reinterpret_cast<const char *>(&codMedicamento), sizeof(int));
    medBin.write(reinterpret_cast<const char *>(medicamento), sizeof(char)* 100);
    medBin.write(reinterpret_cast<const char *>(&precio), sizeof(double));
    medBin.flush();
  }
}

void inserta_consulta_med(ofstream &cons , int codMedicamento){
  cons << setw(12) << codMedicamento;
}

  
void imprimeArchivo(){

  ifstream med("Medicos.txt",ios::in);
  if (!med){
    cout << "Error en la apertura del archivo Medicos.txt " << endl;
    exit(1);
  }

  ifstream pacBin("pacientes.bin",ios::in| ios::binary);
  if (!pacBin){
    cout << "Error en la apertura del archivo pacientes.bin" << endl;
    exit(1);
  }


  ifstream medBin("medicinas.bin",ios::in | ios::binary);
  if (!medBin){
    cout << "Error en la apertura del archivo medicinas.bin" << endl;
    exit(1);
  }


  ifstream cons("consultas.txt",ios::in);
  if (!cons){
    cout << "Error en la apertura del archivo consultas.txt" << endl;
    exit(1);
  }
  
  ofstream arch("reportes.txt",ios::out);
  if(!arch){
    cout << "Error en la apertura del archivo reportes.txt" << endl;
    exit(1);
  }
  imprimirMedicos(arch, med);
}

void imprimirMedicos(ofstream &arch,ifstream &med){
  char codMed[10] , medico[100] , esp[50];
  while(1){
    med >> codMed;
    if(med.eof()) break;
    med >> medico >> esp;
    arch <<setw(10) << codMed << setw(50) <<medico << setw(20) << esp  << endl;
  }
}
