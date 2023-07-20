/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 27 de junio de 2023, 08:52 AM
 */
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Alumno.h"
#include "Nodo.h"

using namespace std;

int main(int argc, char** argv) {
    vector <Alumno> vAlumno;
    Alumno aux;
    ifstream arch("Alumnos2.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir los alumnos";
        exit(1);
    } 
    ofstream repo("reporte.txt",ios::out);
    if(!repo){
        cout << "No se pudo abrir los Reporte";
        exit(1);
    }
    
    while(1){
        aux.lee(arch);
        if(arch.eof()) break;
        vAlumno.push_back(aux);
    }
    sort(vAlumno.begin(),vAlumno.end());
      for(int i=0; i<vAlumno.size();i++)  
          vAlumno[i].imprime(repo);



    
    
    return 0;
}

