/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.cpp
 * Author: cueva
 * 
 * Created on 9 de julio de 2022, 08:02 PM
 */
#include <iostream>
#include "Programa.h"
#include "Nodo.h"
#include <fstream>


Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}

void Programa::carga(){
  cargaproductos();
}

void Programa::cargaproductos(){
  NProductos naux;

  ifstream arch("./productos4.csv",ios::in);
  if(!arch){
    cout << "Error en la apertura productos" << endl;
    exit(1);
  }

  while(1){
    naux.leeproductos(arch); 
    if(arch.eof()) break;
  }
}

void Programa::muestra(){
    ofstream arch("Reporte.txt",ios::out);
  if(!arch){
    cout << "Error en la apertura del reporte" << endl;
    exit(1);
  }

  for (int i = 0 ; i <this->vproductos.size() ; i++){
    vproductos[i].imprimeproductos(arch);
  }

}
