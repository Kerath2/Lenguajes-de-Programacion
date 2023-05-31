//
//  BibliotecaPilaGenerica.cpp
//  Lab6-2022-2
//
//  Created by gkerath on 30/05/23.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "BibliotecaPilaGenerica.h"
using namespace std;



void cargaarreglo(void *&arreglo,int (*cmp)(const void *, const void*),
                  void *(*lee)(ifstream &),const char * nombreArch){
    ifstream arch(nombreArch,ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo" << endl;
        exit(1);
    }
    void *buffer[200];
    int cont = 0;
    while(1){
        buffer[cont] = lee(arch);
        if(buffer[cont] == nullptr) break;
        cont++;
    }
    
    void **aux = new void*[cont+1];
    for (int i = 0 ; i <cont ; i++)
        aux[i] = buffer[i];
    aux[cont] = nullptr;
    qsort(aux,cont,sizeof(void*),cmp);
    arreglo = aux;
}


void cargapila(void *&pila,void *arr){
    construyePila(pila);
    void **arreglo = (void**)arr;
    for(int i = 0 ; arreglo[i] ; i++){
        push(pila,arreglo[i]);        
    }
}

void construyePila(void *&pila){
    void ** cabeza= new void*[2];
    cabeza[0] = nullptr;
    cabeza[1] = new int;
    
    int *n = (int*)(cabeza[1]);
    *n = 0;
    pila = cabeza;
}

int pilaVacia(void *pila){
    void ** cabeza = (void**)pila;
    if (cabeza[0] == nullptr)
        return 1;
    return 0;
}

void push(void *pila, void*dato){
    void ** cabeza = (void**)pila;
    //Construimos el nuevo nodo (dupla)
    void ** dupla = new void*[2];
    dupla[1] = dato;
    dupla[0] = cabeza[0]; 

    cabeza[0] = dupla;
    int *n = (int*)cabeza[1]; 
    (*n)++;
}

void* pop(void*pila){
    void ** cabeza = (void**)pila;
    if (pilaVacia(pila)) return nullptr;
    void *dato;
    void **primero = (void**)cabeza[0];
    dato = primero[1];
    cabeza[0] = primero[0];
    return dato;
}

void muevepila(void *pilaini,void * pilafin){
    void *pilaaux;
    void **cabezaIni = (void**)pilaini;
    construyePila(pilafin); 
    construyePila(pilaaux); 
    int *n = (int*)(cabezaIni[1]);  

    hanoi(*n,pilaini,pilaaux,pilafin);

}
    

void hanoi(int n,void  * origen,void *auxiliar,void *destino){
    if (n == 1){
        void *dato = pop(origen);
        push(destino,dato);
        return;
    }
    hanoi(n-1,origen,destino,auxiliar);
    void *dato = pop(origen);
    push(destino,dato);
    hanoi(n-1,auxiliar,origen,destino);
}

void imprimepila(void *pila,void (*imprime)(ofstream &,const void*),const char *nombreArch){
    ofstream arch(nombreArch,ios::out);
    if(!arch){
        cout << "Error en la apertura del archivo reporte " << endl;
        exit(1);
    }

    void * dato;
    while(!pilaVacia(pila)){
        dato = pop(pila);
        imprime(arch,dato);
    }
}
