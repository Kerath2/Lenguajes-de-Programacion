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

void generarConsolidado(){
  char tipo, nombre[100], esp[100], fac[4];
  int codigo,carnet,sumaNota=0,cantCur =0 , estado = 0;
  double cantCred =0 , credCur = 0;
  ifstream archBin("./alumnosbin.bin",ios::in|ios::binary);
  if(!archBin){
    cout << "Error en la apertura del archivo alumnosbin.bin" << endl;
    exit(1);
  }
    
  ofstream cons("consolidado.bin",ios::out|ios::binary);
  if (!cons){
    cout << "Error en la apertura del archivo consolidado.bin" << endl;
    exit(1);
  }

  while(1){
    archBin.read(reinterpret_cast<char *>(&codigo),sizeof(int));
    if(archBin.eof())
      break;
    archBin.read(reinterpret_cast<char *>(nombre),sizeof(char) * 100);
    archBin.read(reinterpret_cast<char *>(&tipo),sizeof(char) );
    archBin.read(reinterpret_cast<char *>(&carnet),sizeof(int) );
    archBin.read(reinterpret_cast<char *>(&fac),sizeof(char) * 4);
    archBin.read(reinterpret_cast<char *>(&esp),sizeof(char) * 100 );


    cons.write(reinterpret_cast<const char *>(&codigo),sizeof(int));
    cons.write(reinterpret_cast<const char *>(nombre),sizeof(char) *100);
    cons.write(reinterpret_cast<const char *>(&credCur),sizeof(double));
    cons.write(reinterpret_cast<const char *>(&cantCred),sizeof(double));
    cons.write(reinterpret_cast<const char *>(&sumaNota),sizeof(int));
    cons.write(reinterpret_cast<const char *>(&cantCur),sizeof(int));
    cons.write(reinterpret_cast<const char *>(fac),sizeof(char) * 4);
    cons.write(reinterpret_cast<const char *>(esp),sizeof(char) * 100);
  }

}

void imprimeConsolidado(){
  char tipo, nombre[100], esp[100], fac[4];
  int codigo,carnet,sumaNota=0,cantCur =0 , estado = 0;
  double cantCred =0 , credCur = 0;
    
  ifstream cons("consolidado.bin",ios::out|ios::binary);
  if (!cons){
    cout << "Error en la apertura del archivo consolidado.bin" << endl;
    exit(1);
  }

  ofstream reporte("reporte.txt",ios::out);
  if(!reporte){
    cout << "Error en la apertura del archivo reporte.txt" << endl;
    exit(1);
  }

  while(1){
    cons.read(reinterpret_cast<char *>(&codigo),sizeof(int));
    if (cons.eof())break;
    cons.read(reinterpret_cast<char *>(nombre),sizeof(char) *100);
    cons.read(reinterpret_cast<char *>(&credCur),sizeof(double));
    cons.read(reinterpret_cast<char *>(&cantCred),sizeof(double));
    cons.read(reinterpret_cast<char *>(&sumaNota),sizeof(int));
    cons.read(reinterpret_cast<char *>(&cantCur),sizeof(int));
    cons.read(reinterpret_cast<char *>(fac),sizeof(char) * 4);
    cons.read(reinterpret_cast<char *>(esp),sizeof(char) * 100);



    reporte << setw(10) << codigo << setw(30) << nombre << setw(5) << credCur << setw(5) << cantCred ;
    reporte << setw(5) << sumaNota << setw(5) << cantCur << setw(10) <<fac << setw(20) <<  esp << endl;
  }


}

void actualizaConsolidado(){
  char tipo, nombre[100], esp[100], fac[4],codCur[10], otros[10];
  int codigo,carnet,sumaNota=0,cantCur =0 , estado = 0,codAlum, nota;
  double cantCred =0 , credCur = 0, cred;
    
  fstream cons("./consolidado.bin",ios::in| ios::out |ios::binary);
  if (!cons){
    cout << "Error en la apertura del archivo consolidado.bin" << endl;
    exit(1);
  }

  ifstream cursos("./Cursos.txt",ios::in);
  if (!cursos){
    cout << "Error en la apertura del archivo cursos.txt" << endl;
    exit(1);
  }
  
  while(1){
    cursos >> codAlum;
    if(cursos.eof()) break;
    cursos >> otros >> nota >> otros >>cred;
    
    int tamanoRegistro = sizeof(int) *3  + sizeof(char) * 204 + sizeof(double) *2;
    cons.seekg(0,ios::end);
    int total = cons.tellg();
    int numReg = total /tamanoRegistro;
    
    cout << "tam registro  " << numReg <<  endl;
  
    cons.seekg(0,ios::beg);
    
    

    // for (int i = 0 ; i < ; i ++){

    // }
  }

}
