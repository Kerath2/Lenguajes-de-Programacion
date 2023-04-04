#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
#define TAM_LINEA 100
using namespace std;

void imprimeCabecera(ofstream &reporte){
  reporte << setw(50) << "EMPRESA REPORTE DE SALUD" << endl ;
  imprimeLinea('=',TAM_LINEA,reporte);
}

void imprimeLinea(char car , int tamano, ofstream &reporte){
  for (int i = 0 ; i < tamano ; i++){
    reporte<< car;
  }
  reporte<< endl;
}

void separaNombres(char * cadena, char * nombreDoctor, char * especialidad, char * especialidadMayuscula){
// EDGAR_MUNOZ_VERGEL_Urologia
  int i = 0;
  int j; // j guarda la posicion del ultimo guion
  while(cadena[i] != '\0'){
    if(cadena[i] == '_'){
      j = i; 
    }
    i++;
  }

  int aux = j+ 1; 

  int k = 0;
  while(cadena[aux] != '\0'){
    especialidad[k] = cadena[aux]; 
    aux++;
    k++;
  }

  especialidad[k] = '\0';
  cadena[j] = '\0';

  strcpy(nombreDoctor, cadena);
  strcpy(especialidadMayuscula ,especialidad);
 
  i = 0;
  while(especialidadMayuscula[i] != '\0'){
    if (especialidadMayuscula[i] >= 'a' &&  especialidadMayuscula[i]  <= 'z'){
      especialidadMayuscula[i] -= ('a' - 'A');
    }
    i++;
  }


}


void imprimeCabeceraPacientes(ofstream &reporte){

  imprimeLinea('-',TAM_LINEA,reporte);
  reporte<< setw(30) << "Pacientes atendidos" << setw(30) << "Medicinas recibidas" << endl;
  imprimeLinea('-',TAM_LINEA,reporte);
  reporte<< setw(10) << left <<  "DNI" << setw(20) <<  "Nombre" << setw(10) << "Cantidad";
  reporte<< setw(15) << "Codigo" << setw(15) << "Descripcion" <<  setw(10) << "F. de V" << setw(10) << "Observacion" << endl;
}

int compruebaVencido(int dd,int mm,int aa,int ddM,int mmM,int aaM){
  int vencido = 0; 
  if (aaM < aa){
    vencido = 1;  
  }else if (aaM == aa && mmM < mm){
    vencido = 1;
  }else if(mmM == mm && ddM < dd) {
    vencido = 1;
  }else{
    vencido = 0;
  }
  return vencido;
}
