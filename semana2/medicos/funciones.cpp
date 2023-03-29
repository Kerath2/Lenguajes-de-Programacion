#include <iostream>
#include <iomanip>
#include "funciones.h"

using namespace std;

void cortaEspecialidad(char *nomDoc , char * nomEsp , char *espMin){
  int i = 0, j=0 ,aux; 
  while(nomDoc[i] != '\0') i++;
  while(nomDoc[i] != '_') i--;
  aux = i;

  while(nomDoc[i] != '\0'){
    
    if(nomDoc[i]>='a' && nomDoc[i]<='z')
      nomEsp[j] = nomDoc[i] - ('a'-'A');
    else
      nomEsp[j] = nomDoc[i];


    espMin[j] = nomDoc[i];
    j++; i++;
  }
  nomDoc[aux] = '\0';
  espMin[j] = '\0';
  nomEsp[j] = '\0';
}
