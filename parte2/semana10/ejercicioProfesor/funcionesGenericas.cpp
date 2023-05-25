/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */
#include <iomanip>
#include <iostream>
#include <fstream>
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
        
    }
    
}

void construyeLista(void *&lista){
    lista = nullptr;
}