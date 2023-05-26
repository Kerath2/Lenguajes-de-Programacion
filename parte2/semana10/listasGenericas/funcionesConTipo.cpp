/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesConTipo.h"

using namespace std;

void *leeentero(ifstream &arch){
    int cod;
    char car,*nombre;
    arch >> cod;
    if(arch.eof()) return nullptr;
    int *codigo = new int;
    *codigo = cod;
    arch >> car;
    leerCadena(arch,nombre);
    return codigo;
}

void *leecadena(ifstream &arch){
    int cod;
    char car,*nombre;
    arch >> cod;
    if(arch.eof()) return nullptr;
    int *codigo = new int;
    *codigo = cod;
    arch >> car;
    leerCadena(arch,nombre);
    delete codigo;
    return nombre;
}

void leerCadena(ifstream &arch, char *&cad){
    char buff[200];
    arch.getline(buff,200);
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
}

int cmpentero(void *a , void*b){
  int *pa = (int*)a; 
  int *pb = (int*)b; 
  return ((*pa) - (*pb));
}
int cmpcadena(void *a , void*b){
  char *pa = (char*)a; 
  char *pb = (char*)b; 
  return strcmp(pa,pb);
}


void imprimeEntero(ofstream &arch,void *nd){
  void **nodo = (void**)nd;
  int *cod = (int*)(nodo[0]);
  arch << *cod << endl;

} 

void imprimeCadena(ofstream &arch,void *nd){
  void **nodo = (void**)nd;
  char *nombre = (char*)(nodo[0]);
  arch << nombre << endl;

} 
