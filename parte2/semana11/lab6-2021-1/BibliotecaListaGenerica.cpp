//
//  BibliotecaListaGenerica.cpp
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#include "BibliotecaListaGenerica.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;


void creaLista(void *&lista,void * (*lee)(ifstream &),int (*cmp)(const void *, const void *),
               const char * nombreArch){
   //Creamos el arreglo para ordenarlo
    ifstream arch(nombreArch,ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo de lectura " << endl;
        exit(1);
    }
    void *buff[2000];
    int cont = 0;
    while(1){
        buff[cont] = lee(arch); 
        if (buff[cont] == nullptr) break;
        cont++;
    }

    void **aux = new void*[cont+1];
    aux[cont] = nullptr;
    for (int i = 0 ; i < cont; i++)
        aux[i] = buff[i];
    
    qsort(aux,cont,sizeof(void*),cmp);
    //Creamos la lista y metemos los datos
    construyeLista(lista);
    for (int i = 0 ; i < cont ; i++){
        insertaLista(lista,aux[i],cmp);
    }

}

void construyeLista(void *&lista){
    void **cabeza= new void*[2];
    cabeza[0] = nullptr;
    cabeza[1] = nullptr;
    lista = cabeza;
}
        

void insertaLista(void *lista,void * dato,int (*cmp)(const void *, const void *)){
    void ** cabeza = (void**)lista;
    //Creamos el nuevo nodo
    void **nodo = new void*[2];
    nodo[0] = dato;
    nodo[1] = nullptr;
    //
    if (listavacia(lista)){//Lista Vacia
        cabeza[0] = nodo;
        cabeza[1] = nodo;
    }else{//Lista con elementos
        void ** ultimo = (void**)cabeza[1];
        
        // int *a = (int*)ultimo[0];
        // int *b = (int*)nodo[0];

        if (cmp(&ultimo[0],&nodo[0])!= 0){
            ultimo[1] = nodo;
            cabeza[1] = nodo;
        }

    }
}

int listavacia(void*lista){
    void **cabeza = (void**)lista;
    if (cabeza[0] == nullptr)
        return 1;
    return 0;

}
    

void imprimeLista(void *lista, void (*imprime)(ofstream &,const void *),
                  const char * nombreArch){
    ofstream arch(nombreArch,ios::out);
    if(!arch){
        cout << "Error en la apertura del archivo para reporte" << endl;
        exit(1);
    }

    void ** cabeza = (void**)lista;
    void **recorrido = (void**)cabeza[0];
    while(recorrido!=nullptr){
        void * dato = recorrido[0];
        imprime(arch,dato);
        recorrido = (void**)recorrido[1];
    }
}
    

void unelista(void *lista1,void *lista2){
    void ** cabeza1 = (void**)lista1;
    void ** cabeza2 = (void**)lista2;

    void **ultimo1 = (void**)cabeza1[1];
    ultimo1[1] = cabeza2[0];
    cabeza1[1] = cabeza2[1];
}
