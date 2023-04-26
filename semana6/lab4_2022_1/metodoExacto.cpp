#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "metodoExacto.h"
using namespace std;
  

void cargaClientes(int*&cli_dni,char **&cli_nombre,char *&cli_categoria){
  int auxdni[1000], cont = 0;
  char *auxNombre[1000] ,  auxcate[1000], *cad;
  char temp[100];
  ifstream arch("./Clientes.csv",ios::in); 
  if(!arch){
    cout << "Error en la apertura del archivo clientes.csv" << endl;
    exit(1);
  }

  while(1){
    arch >> auxdni[cont];
    if (arch.eof()) break;
    arch.get(); 
    leercadena(arch,cad);
    int tamano = strlen(cad);
    if(cad[tamano-2] == ' '){
      auxcate[cont] = cad[tamano-1];
      cad[tamano-2] = 0;
    }else
      auxcate[cont] = '-';
    
    auxNombre[cont] = cad;
    arch.getline(temp,100);
    cont ++;
  }
  auxdni[cont] = -1;
  cont ++;
  cli_dni = new int[cont]; 
  cli_nombre = new char*[cont];
  cli_categoria =  new char[cont];

  for (int i = 0 ; i < cont ; i++){
    cli_dni[i] = auxdni[i];
    cli_nombre[i] = auxNombre[i];
    cli_categoria[i] = auxcate[i];
  }
}
    
void leercadena(ifstream &arch,char * &cad){
  char buff[200];
  arch.getline(buff,200,',');
  cad = new char[strlen(buff)+1];
  strcpy(cad,buff);
}
