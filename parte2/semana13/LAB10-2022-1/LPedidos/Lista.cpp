/*
 * File:   Lista.cpp
 * Author: gkerath
 */

#include "Lista.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

Lista::Lista() {
  lini = nullptr;
  lfin = nullptr;
}

Lista::Lista(const Lista &orig) {}

Lista::~Lista() {}

void Lista::inserta(ifstream &arch) {
  int codigo;
  Nodo *nuevo, *p, *rec;
  nuevo = new Nodo;
  arch >> codigo;
  if (arch.eof())
    return;
  // En adelante puede ser un metodo creanodo
  if (codigo < 400000)
    nuevo->ped = new PedidoEspecial;
  if (codigo >= 400000 && codigo <= 600000)
    nuevo->ped = new PedidoUsual;
  if (codigo >= 600000)
    nuevo->ped = new PedidoEventual;

  nuevo->ped->lee(codigo, arch);
  p = lini;
  while (p) {
    if(p->cmp(*nuevo)) break;
    rec = p;
    p = p->sig;
  }
  nuevo->sig = p;
    nuevo->ant = rec;
    if (rec == nullptr) {
    lini = nuevo;
    if(p == nullptr)lfin = nuevo;
    }else{
        rec->sig = nuevo;
        if(rec == lfin) 
            lfin = nuevo;
    }

}

// PROBAR : crear el metodo en la propia lista y pasarle dos punteros NODO
