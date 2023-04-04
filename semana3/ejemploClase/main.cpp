#include <iostream>
#include <iomanip>
#include "funciones.h"
#include <fstream>
using namespace std;

int main(){
  char especialidad1[50] , especialidad2[50],cadena[100];  
  char codigoMedico[30],nombreMedico[100], nombreEspecialidad[50], especialidadMayuscula[50];
  int dd , mm , aa, dni, cantidad,codMedicina;
  int ddM, mmM, aaM;
  char car,nombrePaciente[100],nombreMedicina[100];
  int vencido = 0, contMedEsp1 =0, contMedEsp2 =0, contPacEsp1 =0, contPacEsp2 =0;
  int contVencEsp1 =0, contVencEsp2=0 ;

  //Apertura de archivos
  ifstream datos("./datos.txt",ios::in);
  if(!datos){
    cout << "Error en la apertura del archivo ./datos.txt" << endl;
    exit(1);
  }
  
  ofstream reporte("./reporte.txt",ios::out);
  if(!reporte){
    cout << "Error en la apertura del archivo ./reporte.txt" << endl;
    exit(1);
  }

  reporte << "hola" ;

  reporte << "ESPECIALIDAD MAYUSCULA :" << especialidadMayuscula << endl;



  datos>> especialidad1 >> especialidad2;
  datos>> dd >> car >> mm >> car >> aa;
  
  imprimeCabecera(reporte);
  reporte << "ESPECIALIDADES A VERIFICAR: " << especialidad1 << " Y " << especialidad2 << endl; 
  imprimeLinea('=', 100,reporte);
  reporte << "FECHA DEL PROCESO: ";
  reporte << setw(2) << dd << '/' << setw(2) << mm << '/' << setw(4) << aa << endl;
  
  int contadorPacientes = 0; 
  while(1){
    datos>> dni; 
    if (datos.eof())break;
    if (datos.fail()){
      // Si falla se lee el codigo del medico
      datos.clear();
      datos>> codigoMedico; 
      contadorPacientes = 0;
      datos>> cadena;
      separaNombres(cadena,nombreMedico,nombreEspecialidad, especialidadMayuscula);
      if(strcmp(especialidad1,especialidadMayuscula)){
        contMedEsp1++;
      }
      if(strcmp(especialidad2,especialidadMayuscula)){
        contMedEsp2++;
      }
      imprimeLinea('=', 100,reporte);
      reporte << setw(40) << left << nombreMedico << '[' << codigoMedico << ']' ;
      reporte << setw(10) << "" << setw(10)  << "Especialidad:" <<  setw(20) << right << nombreEspecialidad << endl;
      imprimeCabeceraPacientes(reporte);
    }else{
      // Si no falla se lee el dni del paciente
      datos>> nombrePaciente >> cantidad;
      contadorPacientes++;
      reporte << setfill('0');
      reporte <<right <<setw(2) << contadorPacientes << ')' << setfill(' ');
      reporte << setw(10) << dni << setw(20) << nombrePaciente << setw(5) << cantidad ;


      if(strcmp(especialidad1,especialidadMayuscula)){
        contPacEsp1++;
      }
      if(strcmp(especialidad2,especialidadMayuscula)){
        contPacEsp2++;
      }

      
      for (int i = 0 ; i < cantidad; i++){
        datos>> codMedicina >> nombreMedicina;
        datos>> ddM >> car >> mmM >> car >> aaM;

        if (i == 0){
          reporte << setw(10) << codMedicina;
        }else{
          reporte << setw(38) << ""<< setw(10) << codMedicina; 
        }

        vencido = compruebaVencido(dd,mm,aa,ddM,mmM,aaM);
        reporte << setw(40) << nombreMedicina ;
        reporte << setw(5) << " ";
        reporte << setfill('0') << setw(2) << ddM << '/' << setw(2) << mmM << '/'<< setw(4) << aaM << setfill(' ');
        if( vencido){
          reporte  << setw(12) << "VENCIDA" ;
          if(strcmp(especialidad1,especialidadMayuscula)){
            contVencEsp1++;
          }
          if(strcmp(especialidad2,especialidadMayuscula)){
            contVencEsp2++;
          }
        }else{
          reporte  << setw(12) << "" ;
        }
        reporte << endl;
      }
    }
  }
  
  imprimeLinea( '=', 100,reporte);
  reporte << "RESUMEN" << endl;

  reporte << left << "Especialidad : " << setw(14) << especialidad1 << ": ";
  reporte << setw(2) << contMedEsp1 << " medicos , " << setw(2) << contPacEsp1;
  reporte << " pacientes, " << setw(2) << contVencEsp1 << " medicinas vencidas" << endl;

  reporte << left << "Especialidad : " << setw(14) << especialidad2 << ": ";
  reporte << setw(2) << contMedEsp2<< " medicos , " << setw(2) << contPacEsp2;
  reporte << " pacientes, " << setw(2) << contVencEsp2 << " medicinas vencidas" << endl;



  return 0;
}
