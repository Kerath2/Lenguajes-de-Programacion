#include "funcionesGenericas.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//para la plantilla si usar const void * . Como es nuestra funcion si podemos dejarlo como void *
void crealista(void *&lista,void*(*lee)(ifstream&),int (*cmp)(void *, void *)){
  void *dato;
  ifstream arch("entrada.csv",ios::in);
  if(!arch){
    cout << "Error en la apertura del arhivo " << endl;
    exit(1);
  }
  construyeLista(lista);
  while(1){
    dato = lee(arch);
    if(dato == nullptr) break;
    insertarlista(lista,dato,cmp);
  }

}

void insertarlista(void *&lista,void *dato,int (*cmp)(void*, void*)){
  void ** aux  = (void**)lista;
  void **ant  = nullptr, **nuevo;
  nuevo = new void*[2];
  nuevo[0] = dato;
  nuevo[1] = nullptr;

  if(!lista){
    cout << "la lista es null" << endl;
  }else{

    cout << "la lista  NO es null" << endl;
  }

  while(aux != nullptr){
    ant = aux; 
    aux = (void**)(aux[1]); // pasa al siguiente
    if(cmp(aux[0],dato) > 0) break;
  }    

  cout << "pasa" << endl;
  nuevo[1] = aux;
  if (ant == nullptr){
    lista = nuevo;
  }else{
    ant[1] = nuevo;
  }

}
  

void construyeLista(void *&lista){
  lista = nullptr;
}
