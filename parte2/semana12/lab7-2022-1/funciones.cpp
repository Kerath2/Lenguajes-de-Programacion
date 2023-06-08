/*
 * Gerardo Miguel Tacay Terrazos
 * Codigo : 20193503
 */

#include "funciones.h"
#include <iostream>
#include "medico.h"
#include <fstream>


using namespace std;

void llenarMedicos(medico * arrMedicos){
    ifstream  arch("./medicos.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo " << endl;
        exit(1);
    }

    int i = 0;
    while(1){
        arch >> arrMedicos[i]; 
        if(arch.eof()) break;
        i++;
    }
}
