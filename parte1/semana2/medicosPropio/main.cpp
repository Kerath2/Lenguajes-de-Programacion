#include <iostream>
#include <iomanip>
#include "funciones.h"
using namespace std;

int main(){
  char especialidad1[50] , especialidad2[50],cadena[100];  
  char codigoMedico[30],nombreMedico[100], nombreEspecialidad[50], especialidadMayuscula[50];
  int dd , mm , aa, dni, cantidad,codMedicina;
  int ddM, mmM, aaM;
  char car,nombrePaciente[100],nombreMedicina[100];
  int vencido = 0, contMedEsp1 =0, contMedEsp2 =0, contPacEsp1 =0, contPacEsp2 =0;
  int contVencEsp1 =0, contVencEsp2=0 ;
  cout << "ESPECIALIDAD MAYUSCULA :" << especialidadMayuscula << endl;



  cin >> especialidad1 >> especialidad2;
  cin >> dd >> car >> mm >> car >> aa;
  
  imprimeCabecera();
  cout << "ESPECIALIDADES A VERIFICAR: " << especialidad1 << " Y " << especialidad2 << endl; 
  imprimeLinea('=', 100);
  cout << "FECHA DEL PROCESO: ";
  cout << setw(2) << dd << '/' << setw(2) << mm << '/' << setw(4) << aa << endl;
  
  int contadorPacientes = 0; 
  while(1){
    cin >> dni; 
    if (cin.eof())break;
    if (cin.fail()){
      // Si falla se lee el codigo del medico
      cin.clear();
      cin >> codigoMedico; 
      contadorPacientes = 0;
      cin >> cadena;
      separaNombres(cadena,nombreMedico,nombreEspecialidad, especialidadMayuscula);
      if(strcmp(especialidad1,especialidadMayuscula)){
        contMedEsp1++;
      }
      if(strcmp(especialidad2,especialidadMayuscula)){
        contMedEsp2++;
      }
      imprimeLinea('=', 100);
      cout << setw(40) << left << nombreMedico << '[' << codigoMedico << ']' ;
      cout << setw(10) << "" << setw(10)  << "Especialidad:" <<  setw(20) << right << nombreEspecialidad << endl;
      imprimeCabeceraPacientes();
    }else{
      // Si no falla se lee el dni del paciente
      cin >> nombrePaciente >> cantidad;
      contadorPacientes++;
      cout << setfill('0');
      cout <<right <<setw(2) << contadorPacientes << ')' << setfill(' ');
      cout << setw(10) << dni << setw(20) << nombrePaciente << setw(5) << cantidad ;


      if(strcmp(especialidad1,especialidadMayuscula)){
        contPacEsp1++;
      }
      if(strcmp(especialidad2,especialidadMayuscula)){
        contPacEsp2++;
      }

      
      for (int i = 0 ; i < cantidad; i++){
        cin >> codMedicina >> nombreMedicina;
        cin >> ddM >> car >> mmM >> car >> aaM;

        if (i == 0){
          cout << setw(10) << codMedicina;
        }else{
          cout << setw(38) << ""<< setw(10) << codMedicina; 
        }

        vencido = compruebaVencido(dd,mm,aa,ddM,mmM,aaM);
        cout << setw(40) << nombreMedicina ;
        cout << setw(5) << " ";
        cout << setfill('0') << setw(2) << ddM << '/' << setw(2) << mmM << '/'<< setw(4) << aaM << setfill(' ');
        if( vencido){
          cout  << setw(12) << "VENCIDA" ;
          if(strcmp(especialidad1,especialidadMayuscula)){
            contVencEsp1++;
          }
          if(strcmp(especialidad2,especialidadMayuscula)){
            contVencEsp2++;
          }
        }else{
          cout  << setw(12) << "" ;
        }
        cout << endl;
      }
    }
  }
  
  imprimeLinea( '=', 100);
  cout << "RESUMEN" << endl;

  cout << left << "Especialidad : " << setw(14) << especialidad1 << ": ";
  cout << setw(2) << contMedEsp1 << " medicos , " << setw(2) << contPacEsp1;
  cout << " pacientes, " << setw(2) << contVencEsp1 << " medicinas vencidas" << endl;

  cout << left << "Especialidad : " << setw(14) << especialidad2 << ": ";
  cout << setw(2) << contMedEsp2<< " medicos , " << setw(2) << contPacEsp2;
  cout << " pacientes, " << setw(2) << contVencEsp2 << " medicinas vencidas" << endl;



  return 0;
}
