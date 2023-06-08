/*
 * Gerardo Miguel Tacay Terrazos
 * Codigo : 20193503
 */

#include "funciones.h"
#include <iostream>
#include "medico.h"
#include "paciente.h"
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
    

void llenaPacientes(paciente *arrPacientes){
    ifstream  arch("./pacientes.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo pacientes" << endl;
        exit(1);
    }

    int i = 0;
    while(1){
        arch >> arrPacientes[i]; 
        if(arch.eof()) break;
        i++;
    }

}
    

void llenaCitasPacientes(paciente * arrPacientes,medico *arrMedicos){
    ifstream arch("./consultas.csv",ios::in);
    if(!arch){
        cout << "Error en la epertura del archivo consultas" << endl;
        exit(1);
    }

    cita citatemp;

    while(1){
        arch >> citatemp;
        if(arch.eof()) break;
        citatemp.LlenaTarifa(arrMedicos);
    }
    
    

}
