//
//  PilaConEnteros.cpp
//  Lab6-2022-2
//
//  Created by gkerath on 30/05/23.
//
#include "PilaConEnteros.h"
#include <fstream>
using namespace std;
void *leenumero(ifstream& arch){
    int aux;
    arch >> aux;
    if(arch.eof()) return nullptr;
    int *numero = new int;
    *numero = aux;
    return numero;
}


int cmpnumero(const void *a, const void*b){
    void ** datoA = (void**)a;
    void ** datoB = (void**)b;
    
    int *numA = (int*)*datoA;
    int *numB = (int*)*datoB;
    
    return *numA - *numB;
}

void imprimenumero(ofstream &arch,const void*a){
    void ** datoA = (void**)a;
    int *numA = (int*)*datoA;
    arch << *numA << endl;
}
