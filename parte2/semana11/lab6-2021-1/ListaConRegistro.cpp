//
//  ListaConRegistro.cpp
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#include "ListaConRegistro.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void leerCadena(ifstream &arch , char *&cad){
    char buff[200];
    arch.getline(buff,200,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
}
void* leeregistro(ifstream &archDatos){
    int aux, *codLicencia,dd,mm,aa,*fecha,*codInfraccion;
    char *placa,car;
   
    archDatos>>aux;
    if(archDatos.eof()) return nullptr;
    codLicencia=new int;
    *codLicencia=aux;
    archDatos.get();
    leerCadena(archDatos,placa);
    archDatos>>dd>>car>>mm>>car>>aa;
    fecha=new int;
    *fecha=aa*10000+mm*100+dd;
    archDatos.get();
    codInfraccion=new int;
    archDatos>>*codInfraccion;
    
    void **registro;
    registro=new void*[4];
    registro[0]=codLicencia;
    registro[1]=placa;
    registro[2]=fecha;
    registro[3]=codInfraccion;
    
    return registro;
}

int cmpregistro(const void *a, const void *b) {
    void **registroConductorA=(void **)a;
    void **registroConductorB=(void **)b;
    
    int *fechaA,*fechaB;
    fechaA=(int *)registroConductorA[2];
    fechaB=(int *)registroConductorB[2];
    
    return *fechaA-*fechaB;
}
