/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include "funcionesGenericas.h"
using namespace std;

void crealista(void *&lista,void*(*lee)(ifstream&),int (*cmp)(void *, void*)){
    void * dato;
    
    

    
    ifstream arch("Alumnos.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo Alumnos.csv" << endl;
        exit(1);
    }
    

    
    construyeLista(lista);
    
    while(1){
        dato = lee(arch);
        if(dato == nullptr) break;
        insertarenLista(lista,dato,cmp); 
    }
    
}

void construyeLista(void *&lista){
    lista = nullptr;
}

void insertarenLista(void *&lista,void *dato,int (*cmp)(void *, void*)){
  //creamos el nuevo nodo
  void ** nodo = new void*[2];
  nodo[0] = dato;
  nodo[1] = nullptr;
  //Si esta vacia
  if(lista == nullptr){
    lista = nodo;
  }else{
    void **aux = (void**)lista;
    void **ant = nullptr;

    while(aux!=nullptr){
      if(cmp(dato,aux[0]) < 0) break;
      ant = aux;
      aux = (void**)(aux[1]);
    }
      // Colocamos el dato al principio de la lista
      if (ant == nullptr) {
        nodo[1] = lista;
        lista = nodo;
      } else {
        // Colocamos el dato en medio de la lista
        nodo[1] = aux;
        ant[1] = nodo;
      }
      
  }
}



void imprimeLista(void *lista,void(*imprime)(ofstream&,void*)){
  ofstream arch("salida.txt",ios::out);
  if(!arch){
    cout << "Error en la apertura del archivo salida" << endl;
    exit(1);
  }
  
  void **recorrido = (void**)lista;
  while(recorrido!=nullptr){
    imprime(arch,recorrido); 
    recorrido = (void**)(recorrido[1]);
  }

}
