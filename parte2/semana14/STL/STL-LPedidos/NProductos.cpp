/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.cpp
 * Author: cueva
 * 
 * Created on 9 de julio de 2022, 08:07 PM
 */
#include <iostream>
#include "NProductos.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

NProductos::NProductos() {
  this->prod = nullptr;

}

NProductos::NProductos(const NProductos& orig) {
  // En este caso es punteor, no hace falta sobrecargar
  this->prod = orig.prod;
}

NProductos::~NProductos() {
}

void NProductos::leeproductos(ifstream &arch){
  int cat;
  arch >> cat;
  if(arch.eof()) return;
  arch.get(); // coma 
  if(cat == 1 ) prod = new Categoria1;
  if(cat == 2 ) prod = new Categoria2;
  if(cat == 3 ) prod = new Categoria3;
  prod->leeprod(arch);

}


void NProductos::imprimeproductos(ofstream &arch){
  prod->imprimeprod(arch);
}
