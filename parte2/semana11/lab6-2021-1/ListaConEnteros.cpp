//
//  ListaConEnteros.cpp
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


#include "ListaConEnteros.h"
using namespace std;

void* leenum(ifstream &arch){
    int aux;
    char c;
    char buff[200];
    int dd , mm ,aa, infraccion;
    arch  >> aux;
    if(arch.eof()) return nullptr;
    arch >> c;
    arch.getline(buff,200,',');
    arch >> dd >> c >> mm >> c >>aa>> c >> infraccion; 
    int *fecha = new int;
    *fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

int cmpnum(const void *a , const void *b){
    void **datoA = (void**)a;
    void **datoB = (void**)b;

    int *numA = (int*)(*datoA);
    int *numB = (int*)(*datoB);

    return *numA - *numB;
}

void imprimenum(ofstream &arch,const void *a ){
    int *num = (int*)a;
    arch << *num << endl;

}
