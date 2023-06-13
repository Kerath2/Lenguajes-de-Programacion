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
        citatemp<=arrMedicos;
        int ind = devuelveIndicePaciente(citatemp.GetDni(),arrPacientes);
        if(ind != -1)
            arrPacientes[ind]+=citatemp;
    }
    

}

int devuelveIndicePaciente(int dni, paciente * arrPacientes){
    for (int i = 0 ; arrPacientes[i].GetDni() ;i++)
        if(dni == arrPacientes[i].GetDni())
            return i;

    return -1;
}

    
void actualizarTarifas(paciente * arrPacientes){
    for (int i = 0 ; arrPacientes[i].GetDni() ; i++){
        arrPacientes[i]++;
    }
}


void imprimePacientes(paciente *arrPacientes){
    ofstream arch("Reportepacientes.txt",ios::out);
    if(!arch){
        cout << "Error en la apertura del archivo" << endl;
        exit(1);
    }
    for (int i = 0 ; arrPacientes[i].GetDni() ; i++){
       arch << arrPacientes[i]; 
    }
}
